//=====================RECIVER==========================
#define stationID 0x01
#define stationAxis 1
#define refreshID 2000
#define refreshLog 30
unsigned long timer1=0;
byte currentID;
byte previousID;
byte playingID;

#include <SD.h>
File myFile;

#include <RTClib.h>
RTC_DS3231 rtc;
byte seconds, minutes, hours, dates, months;
uint16_t years = 2020;
float Temperature;
uint16_t heading=0;

#include <Wire.h>
#define slave 0x44 //slave processor

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"ALPHA", "GAMMA"};//40-bit address


struct dumpster { // data to be transmited
  byte id;
  byte sent_time;
  byte s;
  byte m;
  byte h;
  byte d;
  byte mag;
  byte mag2;
  byte ax;
  byte ay;
  byte az;
  byte velocity;
} recived = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  Serial.begin(115200);
  pinMode(3, OUTPUT); //kill yourself ~RST
  pinMode(3, HIGH);
  Wire.begin();
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));// stamp last sync time to eeprom and retrive here
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00002
  radio.openReadingPipe(1, addresses[1]); // 00001
  radio.setChannel(120);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();              //set as transmitter
  delay(5);
}
void loop() {
  timer1=millis();
  recive_payload();
  heading = (recived.mag2 << 8) + recived.mag;
  currentID=recived.id;
  AlgorithmAction();
  refresh();
  //Serial_print();
  reset_dumpster();
  delay(100);
}
void refresh(){
	if(timer1>2000 & timer1<3000){
	playingID=0;
	}
	if(timeNow-lastPreviousIdTime=refreshLog){
	releaseId();
	}
}
void AlgorithmAction(){

while((heading=stationAxis)&(recived.velocity>=-3 & recived.velocity<=3)&((currentID!=previousID)|(currentID!=playingID))){
	
	if(!checkThisId(currentID,/*loadSDIds/update?=*/true)){
		createThisId(currentID);
	}
	if(!checkLastEntry()<30){//recently updated - discard
		updateIds(currentID,previousID,playingID);
		pushOutputs();
		delay(100);
	}
	
}
}
void Serial_print() {
//debugging section - ignore;
  Serial.print(recived.id);
  Serial.print(",");
  Serial.print(recived.sent_time);
  Serial.print(",");
  Serial.print(recived.s);
  Serial.print(",");
  Serial.print(recived.m);
  Serial.print(",");
  Serial.print(recived.h);
  Serial.print(",");
  Serial.print(recived.d);
  Serial.print(",");
  Serial.print(recived.mag);
  Serial.print(",");
  Serial.print(recived.mag2);
  Serial.print(",");
  Serial.print(recived.ax);
  Serial.print(",");
  Serial.print(recived.ay);
  Serial.print(",");
  Serial.print(recived.az);
  Serial.print(",");
  Serial.println(recived.velocity);


}
void reset_dumpster() {
  recived.id = 0;
  recived.sent_time = 0;
  recived.s = 0;
  recived.m = 0;
  recived.h = 0;
  recived.d = 0;
  recived.mag = 0;
  recived.mag2 = 0;
  recived.ax = 0;
  recived.ay = 0;
  recived.az = 0;
  recived.velocity = 0;

}
void recive_payload() {
  radio.startListening();
  if (radio.available()) {
    radio.read(&recived, sizeof(dumpster));
  }
}
