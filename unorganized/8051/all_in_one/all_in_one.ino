//====================================TRANSMITTER======================================
/*
   Arduino IDE:1.8.12
   last modified:22-03-2020
   code by: aravind
   Handshake algorithm v22.3 -by amlan
   command/instruction set v22.3
*/
#include <RTClib.h>
RTC_DS3231 rtc;
byte seconds, minutes, hours, dates, months;
uint16_t years = 2020;
float Temperature;

#include <Wire.h>
#define MPU 0x69 // MPU6050 I2C address
#define FACTOR 2048.0 //16g
float AccX, AccY, AccZ;

#define HMC 0x0D //HMC5883 I2C address
uint16_t azimuth = 0;

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"ALPHA", "GAMMA"};//40-bit address
bool handShake = false;

struct dumpster_1 { // data recived is stored here
  byte ins0; byte ins1;
  byte ins2; byte ins3;
  byte ins4; byte ins5;
  byte ins6; byte ins7;
  byte ins8; byte additional; //saving some for future use
} rec_1;
struct payload_1 { // data to be transmited
  byte thisID; byte s;
  byte m; byte h;
  byte mag; byte mag2;
  byte ax; byte ay;
  byte az; byte d;
  byte additional;
} sen_1 = {75, 0, 0, 0, 0, 0, 0, 0, 0, 0,0};
void setup() {
  Serial.begin(115200);
  Wire.begin();
  rtc.begin();
  if (rtc.lostPower()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  Wire.beginTransmission(HMC);
  Wire.write(0x0B);
  Wire.write(0x01);                  //continuous mode
  Wire.endTransmission();
  Wire.beginTransmission(HMC);
  Wire.write(0x09);
  Wire.write(0x1D);                  //mode|odr|rng|osr

  Wire.endTransmission();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0x00);                  // Make reset - place a 0 into the 6B register
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);                  //Talk to the ACCEL_CONFIG register
  Wire.write(0x18);                  //[4:3] 00,01,10,11, 2,4,8,16
  Wire.endTransmission(true);

  radio.begin();
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setChannel(120);
  radio.setPALevel(RF24_PA_MIN);
  //radio.powerUp(); //increase current into engine
  //radio.setRetries(1,5);
  //radio.setDataRate(RF24_250KBPS);
  radio.stopListening();              //set as transmitter
  delay(5);
}
void loop() {
  //const String herID = "StationAB";
  //updateSensors();

  if (checkRecivers()) {
    //handShake = genuine;
    Serial.println("got a device");
  }

//  while (genuine & handShake) {
//    //start of conversation
//    transmitPayload();
//    delay(10);
//    reciveInstructions();
//    delay(10);
//    handShake = rec_1.ins0;
//    genuine = handShake;
//    if (rec_1.ins1) { // retransmit payload with updated values
//      updateSensors();
//      transmitPayload();
//    }
//    //still need to frame instructions coming soon....
//  }
}
void reciveInstructions() {
  radio.startListening();
  if (radio.available()) {
    radio.read(&rec_1, sizeof(dumpster_1));
  }
}
void transmitPayload() {
  radio.stopListening();
  radio.write(&sen_1, sizeof(payload_1));
}
bool checkRecivers() {
  char const magicWord[] = "KnockKnock";
  char const truePhraseWord[] = "WhoseThere";
  radio.stopListening();
  radio.write(&magicWord, sizeof(magicWord));
  delay(4);
  radio.startListening();
  delay(4);
  if (radio.available()) {
    char phraseWord[12] = "";
    radio.read(&phraseWord, sizeof(phraseWord));
    if (strcmp(phraseWord, truePhraseWord) == 0) {
      return true;
    }
    return false;
  }
  return false;
}
void updateSensors() {
  DateTime now = rtc.now();
  seconds = now.second();
  minutes = now.minute();
  hours = now.hour();
  dates = now.day();
  //months=now.month();
  //years=now.year();

  Wire.beginTransmission(HMC);
  Wire.write(0x00);
  Wire.endTransmission(false);
  Wire.requestFrom(HMC, 4, true);

  float ComX = Wire.read() << 8 | Wire.read(); // X-axis value
  float ComY = Wire.read() << 8 | Wire.read(); // Y-axis value
  //float ComZ = Wire.read() << 8 | Wire.read(); // Z-axis value
  azimuth = atan2(ComY, ComX) * 180.0 / PI;
  if (azimuth < 0)azimuth += 360.0;

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);

  AccX = (Wire.read() << 8 | Wire.read()) / FACTOR; // X-axis value
  AccY = (Wire.read() << 8 | Wire.read()) / FACTOR; // Y-axis value
  AccZ = (Wire.read() << 8 | Wire.read()) / FACTOR; // Z-axis value

  Wire.beginTransmission(MPU);
  Wire.write(0x41); // 0X41_0X42 H_L TEMP
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 2, true);
  Temperature = (Wire.read() << 8 | Wire.read()) / 340 + 36.53;
  //pack to payload_1
  sen_1.mag2 = (azimuth >> 8);
  sen_1.mag = (azimuth & 0xFF);
  sen_1.ax = AccX;
  sen_1.ay = AccY;
  sen_1.az = AccZ;
  sen_1.s = seconds;
  sen_1.m = minutes;
  sen_1.h = hours;

}
bool checkEngine() {
  if (radio.failureDetected) {
    radio.begin();                       // Attempt to re-configure the radio with defaults
    radio.failureDetected = 0;           // Reset the detection value
    radio.openWritingPipe(addresses[1]); // 00002
    radio.openReadingPipe(1, addresses[0]); // 00001
    radio.setChannel(120);
    //radio.setRetries
    radio.setPALevel(RF24_PA_MIN);
    radio.stopListening();              //set as transmitter
    return true ;                   // send a message to indicate failure
  }
  return false;
}
