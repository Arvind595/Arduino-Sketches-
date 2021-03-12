#include "thermistor.h"
#include "HardwareSerial.h"

// Analog pin used to read the NTC
#define NTC_PIN               A1

// Thermistor object
THERMISTOR thermistor(NTC_PIN,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor

// Global temperature reading
uint16_t temp;
long c;
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <SimpleDHT.h>


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 7;
SimpleDHT11 dht11;

void setup() {
    lcd.begin(16,2);
  Serial.begin(115200);
}

void loop() {
    temp = thermistor.read();   // Read temperature
c=temp*0.1;
    lcd.setCursor(0,0);
  lcd.print(c);
    
  delay(1000);
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
 
    lcd.setCursor(0,1);
    lcd.print((int)temperature);
    lcd.setCursor(10,1);
    lcd.print((int)humidity);
   
}





 