#include <SimpleDHT.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 8;
SimpleDHT11 dht11;
byte tree[8]={
    0b00100,
    0b00100,
    0b01110,
    0b01110,
    0b11111,
    0b11111,
    0b00100,
    0b00100
};


void setup() {
  Serial.begin(115200);
    lcd.begin(16,2);
    lcd.clear();
    lcd.createChar(1,tree);
}

void loop() {
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
 
    return;
  }
  
  lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.setCursor(6,0);
    lcd.print((int)temperature);
    lcd.setCursor(9,0);
    lcd.print("*C");
    lcd.setCursor(0,1);
    lcd.print ("Humi: ");
    lcd.setCursor(6,1);
    lcd.print((int)humidity);
    lcd.setCursor(9,1);
    lcd.print("%H");
    delay(400);
   
}
