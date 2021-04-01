#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <SPI.h>
#define LCD_CONTRAST 9
#define KEY_H 8
#define KEY_M 7
LiquidCrystal lcd(10);

unsigned long previousMillis = 0;
const long interval = 1000;

int hr, mins, sec;

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void setup() {
  pinMode(KEY_M, INPUT_PULLUP);
  pinMode(KEY_H, INPUT_PULLUP);
  setPwmFrequency(9, 1);
  pinMode(LCD_CONTRAST, OUTPUT);
  analogWrite(LCD_CONTRAST, 50);  
  lcd.begin(16, 2);
  lcd.print("Real Time Clock");
  mins = EEPROM.read(1);
  hr = EEPROM.read(0);
}

void doJob(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    sec++;
    if(sec >= 60){
      sec = 0;
      mins++;

      if(mins >= 60){
        mins = 0;
        hr++;
        if(hr >= 24){
          hr = 0;
        }
      }
      EEPROM.write(1, mins);
      EEPROM.write(0, hr);
    }

    lcd.setCursor(0,1);
    char h = hr %12;
    if(h == 0)
      h = 12;
      
    lcd.print(h/10);
    lcd.print(h%10);
    lcd.print(":");
    lcd.print(mins/10);
    lcd.print(mins%10);
    lcd.print(":");
    lcd.print(sec/10);
    lcd.print(sec%10);
    lcd.print(' ');
    if(hr >= 12)
      lcd.print("PM");
    else
      lcd.print("AM");
  }
  delay(1);
}

void loop() {
  doJob();
  
  if(!digitalRead(KEY_H)){
    hr++;
    if(hr >= 24)
      hr = 0;
    while(!digitalRead(KEY_H))
      doJob();
  }
  
  if(!digitalRead(KEY_M)){
    mins++;
    if(mins >= 60)
      mins = 0;
    while(!digitalRead(KEY_M))
      doJob();
  }
}