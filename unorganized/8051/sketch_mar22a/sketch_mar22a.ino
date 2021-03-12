#include <I2Cdev.h>
#include <MPU6050.h>
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
MPU6050 accelgyro(0x69);
int16_t ax, ay, az;

#define devAddr 0x69
#define MPU6050_RA_XA_OFFS_H        0x06 //[15:0] XA_OFFS
#define MPU6050_RA_XA_OFFS_L_TC     0x07
#define MPU6050_RA_YA_OFFS_H        0x08 //[15:0] YA_OFFS
#define MPU6050_RA_YA_OFFS_L_TC     0x09
#define MPU6050_RA_ZA_OFFS_H        0x0A //[15:0] ZA_OFFS
#define MPU6050_RA_ZA_OFFS_L_TC     0x0B


void setZAccelOffset(int16_t offset) {
  uint8_t SaveAddress = MPU6050_RA_ZA_OFFS_H
  writeWord(devAddr, SaveAddress, offset);
}


 
bool writeWord(uint8_t devAddr, uint8_t regAddr, uint16_t data) {
    return writeWords(devAddr, regAddr, 1, &data);
}

void writeWords(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint16_t* data) {

        Wire.beginTransmission(devAddr);
        Wire.send(regAddr); // send address
    for (uint8_t i = 0; i < length; i++) { 
            Wire.send((uint8_t)(data[i] >> 8));     // send MSB
            Wire.send((uint8_t)data[i]);          // send LSB
    }
        Wire.endTransmission();

}
void setup() {
   Serial.begin(115200);
  // put your setup code here, to run once:
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    accelgyro.initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
delay(1000);
}
