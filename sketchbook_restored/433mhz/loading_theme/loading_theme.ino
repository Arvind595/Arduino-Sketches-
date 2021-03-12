#include <SPI.h>
#include <LiquidCrystal.h>
int val;
LiquidCrystal lcd(10);
byte arrow[8]={
    0b10000,
    0b01000,
    0b00100,
    0b00010,
    0b00100,
    0b01000,
    0b10000,
    0b00000
    
};
void setup(){
    pinMode(A1,INPUT);
    lcd.begin(16,2);
    lcd.home();
    lcd.createChar(1,arrow);
}
void loop(){ 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Loading...");
    
     val = analogRead(A1);   
    
  val = map(val, 0,600, 50, 1000);
    for (int i; i<16; i++)
    {
        lcd.setCursor(i,1);
        lcd.write(1);
        delay(val);
        }
  
    }