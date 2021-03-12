#define clockpin 2
#define latchpin 3
#define datapin 4
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
pinMode(clockpin,OUTPUT);
pinMode(latchpin,OUTPUT);
pinMode(datapin,INPUT);
digitalWrite(latchpin,LOW);
digitalWrite(clockpin,LOW);
}

void loop() {
  byte binary = 0;
  digitalWrite(clockpin, LOW);
  digitalWrite(latchpin, LOW);
  delayMicroseconds(1000);
  digitalWrite(latchpin, HIGH);

  for (uint8_t  i = 0; i < (8); i++) {
    bool  pinstate = digitalRead(datapin);
    digitalWrite(clockpin, LOW);
    delayMicroseconds(5000);
    digitalWrite(clockpin, HIGH);
    delayMicroseconds(5000);
    binary = (binary << 1) | pinstate;
  }
Serial.println(binary,BIN);
//Serial.println(String(binary));
delay(100);
}
