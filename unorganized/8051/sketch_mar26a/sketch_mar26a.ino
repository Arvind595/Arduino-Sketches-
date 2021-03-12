#include<Wire.h>
int x;
void setup() {
  Serial.begin(115200);
  Wire.begin(4); 
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x=0;
  x = Wire.read();    // read one character from the I2C
}
void loop() {
Serial.println(x,DEC);
delay(1000);
}
