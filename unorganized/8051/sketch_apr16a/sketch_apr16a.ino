#include <Wire.h> //I2C Arduino Library

#define HMC 0x0D //I2C Address for The HMC5883

void setup() {

  Serial.begin(9600);
  Wire.begin();


  Wire.beginTransmission(HMC); //start talking
  Wire.write(0x0B); // Tell the HMC5883 to Continuously Measure
  Wire.write(0x01); // Set the Register
  Wire.endTransmission();
  Wire.beginTransmission(HMC); //start talking
  Wire.write(0x09); // Tell the HMC5883 to Continuously Measure
  Wire.write(0x1D);                  //mode|odr|rng|osr
  Wire.endTransmission();
}

void loop() {



  //Tell the HMC what regist to begin writing data into
int azimuth;
int x,y,z;
  Wire.beginTransmission(HMC);
  Wire.write(0x00); 
  Wire.endTransmission(false);
  Wire.requestFrom(HMC, 6,true);
  if (6 <= Wire.available()) {
    x = Wire.read(); //MSB  x
    x |= Wire.read() << 8; //LSB  x
    z = Wire.read(); //MSB  z
    z |= Wire.read() << 8; //LSB z
    y = Wire.read(); //MSB y
    y |= Wire.read() << 8; //LSB y
  }
  azimuth = (int)(atan2(y, x) * 180.0 / PI);
  if (azimuth < 0)azimuth += 360.0;
  // Show Values
  Serial.print("X Value: ");
  Serial.println(x);
  Serial.print("Y Value: ");
  Serial.println(y);
  Serial.print("Z Value: ");
  Serial.println(z);
  Serial.println(azimuth);

  delay(500);
}
