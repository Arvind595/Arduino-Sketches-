#include<Wire.h>
int chipadd=0xA0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  unsigned celladd = 0;
  writeTo(chipadd, celladd, 128);
  Serial.println(readfrom(chipadd, celladd), DEC);
}

void loop() {
  // put your main code here, to run repeatedly:

}
void writeTo(int chipadd, unsigned int celladd, byte wdata) {
  Wire.beginTransmission(chipadd);
  Wire.write((int)celladd);
  //Wire.write((int)celladd & 0xFF);
  Wire.write(wdata);
  Wire.endTransmission();
  delay(100);
}

byte readfrom(int chipadd, unsigned celladd) {
  Wire.beginTransmission(chipadd);
  Wire.write((int)celladd);
  //Wire.write((int)celladd & 0xFF);
  Wire.endTransmission();
  Wire.requestFrom(chipadd, 1);
  byte rdata = 0;
  if (Wire.available()) {
    rdata = Wire.read();
  }
  delay(10);
  return rdata;
}
