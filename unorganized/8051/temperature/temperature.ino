#include "thermistor.h"
#include "HardwareSerial.h"
#define NTC_PIN  A1
THERMISTOR thermistor(NTC_PIN,
                      10000, 
                      3950,
                      10000);
uint16_t temp;
float c,v,r,spd;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <SimpleDHT.h>
int pinDHT11 = A0;
SimpleDHT11 dht11;
int sensorPin = A2; 
int sensorValue = 0;

void setup() {
   Serial.begin(9600);
    lcd.begin(16,2);
    lcd.clear();
    lcd.print("waiting for data");
    delay(5000);
    lcd.clear();
    lcd.print("data acquried");
    delay(1000);
    lcd.blink();
    delay(700);
    lcd.noBlink();
    delay(500);
  
}

void loop() {
    sensorValue = analogRead(sensorPin);
    delay(1000); 
    v=5 * sensorValue/1024;
    r=v/0.0004;
  temp = thermistor.read();
c=temp*0.1;
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
lcd.setCursor(0,1);
    lcd.print((int)temperature);
    lcd.setCursor(13,1);
    lcd.print((int)humidity);
    delay(1000);
   spd=331.4+(0.606+(int)temperature)+(0.0124*(int)humidity);
    lcd.setCursor(4,1);
    lcd.print("S=");
    lcd.print(spd);
    lcd.setCursor(0,0);
  lcd.print(c);
      lcd.setCursor(6,0);
    lcd.print("ldr=");
lcd.print(sensorValue);
    delay(1000);
    Serial.print((int)temperature);
    Serial.print((int)humidity);
    
}





 