#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
/*COMPONENTS AT RECIVER:
  NRF24L01------TRANSRECIVER
  SD CARD-------DATABASE/PLAYBACK
  .DAC-----------PLAYBACK
  .RTC-----------SYNC
  ARDUINO--------BRAINS
*/
//=============================DEBUG_CONTROL============================
#define DEBUG_ENABLE
#define DEBUG_SD
#define DEBUG_NRF
#define DEBUG_RTC
#define DEBUG_RATE 300
//=======================================================================

//==================RTC_DS3231======================
RTC_DS3231 rtc;
//uint16_t Ryear;
uint8_t /*Rmonth,*/ Rdate, Rhour, Rminute, Rsecond;
int8_t chip_temp = 0;
//==================================================

//============================RTC_START=====================
void RclockUpdate()
{
  DateTime now = rtc.now();
  //Ryear = now.year();
  //Rmonth = now.month();
  Rdate = now.day();
  Rhour = now.hour();
  Rminute = now.minute();
  Rsecond = now.second();
}
void boardTemp(int8_t *temp) {
  *temp = rtc.getTemperature();
}
//==========================RTC-END=========================

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if (!rtc.begin())
  {
    Serial.println("Couldn't find RTC");
  }
  if (rtc.lostPower())
  {
    Serial.println("RTC lost power, lets set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
  //mannual time adjust ex: 2014-jan-21-3am // y m d h m s
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  RclockUpdate();
  boardTemp(&chip_temp);
}

void loop() {
  RclockUpdate();
  boardTemp(&chip_temp);
  delay(50);

#ifdef DEBUG_ENABLE
  if (Serial.available() > 0)
  {
#ifdef DEBUG_RTC
    Serial.print("CLOCK:");
    Serial.print(Rdate);
    Serial.print("/");
    Serial.print(Rhour);
    Serial.print(":");
    Serial.print(Rminute);
    Serial.print(":");
    Serial.print(Rsecond);
    Serial.println("");

#endif // DEBUG_RTC

#ifdef DEBUG_SD

#endif // DEBUG_SD

#ifdef DEBUG_NRF

#endif // DEBUG_NRF

    delay(DEBUG_RATE);
  }
#endif // DEBUG_ENABLE
}
