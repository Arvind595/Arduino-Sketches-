//TRANSMITTER uno 328p
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define irq 2
#define clockpin 9
#define latchpin 10
#define datapin 5
#define relay 3
byte dataa;
RF24 radio(7, 8); // CE, CSN
const byte address[][6] = {"00001", "00002"};

void setup() {
  Serial.begin(9600);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(datapin, INPUT);
  pinMode(irq, INPUT_PULLUP);
  pinMode(relay,OUTPUT);

  digitalWrite(relay,LOW);
  
  radio.begin();
  radio.openWritingPipe(address[1]);
  radio.openReadingPipe(1, address[0]);
  radio.setAutoAck(1);
  radio.enableAckPayload();
  radio.maskIRQ(1, 1, 0); //(tx_ok,tx_fail,rx_ready);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
  attachInterrupt(digitalPinToInterrupt(irq), message, FALLING);
  delay(2000);
}
void readd(){
  byte   binary = 0;
  digitalWrite(clockpin, LOW);
  digitalWrite(latchpin, LOW);
  delayMicroseconds(10);
  digitalWrite(latchpin, HIGH);

  for (uint8_t  i = 0; i < (8); i++) {
    bool pinstate = digitalRead(datapin);
    Serial.println(pinstate);
    digitalWrite(clockpin, LOW);
    delayMicroseconds(10);
    digitalWrite(clockpin, HIGH);
    delayMicroseconds(10);
    binary = (binary << 1) | pinstate;
  } 
  dataa=binary;
  Serial.println(binary,BIN);
   digitalWrite(relay,LOW); 
}

void message() {
  detachInterrupt(irq);
  if (radio.available()){
    byte text = 0;
    radio.read(&text, sizeof(text));
    radio.stopListening();
    radio.write(&dataa, sizeof(dataa));
    radio.startListening();
  }
  
}

void loop() {
  readd();
  //HERE ON THE CHIP IS DEEP SLEEP SUB MICRO AMP FOREVER
  //sleep forever
  //disable adc
  ADCSRA &= ~(1 << 7);
  SMCR |= (1 << 2);
  SMCR |= 1;
  //bod disable
  MCUCR |= (3 << 5);
  MCUCR = (MCUCR & ~(1 << 5)) | (1 << 6);
  __asm__ __volatile__("sleep");
  digitalWrite(relay,HIGH);
  delay(2000);
  readd();
}
