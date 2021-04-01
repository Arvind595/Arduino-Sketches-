#include"LiquidCrystal.h"
LiquidCrystal lcd(12,11,5,4,3,2);
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
void setup(){
    lcd.begin(16,2);
    lcd.clear();
    lcd.createChar(1,tree);
   
}
void loop(){
    lcd.setCursor(0,0);
    lcd.print("X-Mas tree: ");
    lcd.setCursor(12,0);
    lcd.write(1);
   lcd.setCursor(13,0);
    lcd.write(1);
  lcd.setCursor(14,0);
    lcd.write(1);
   lcd.setCursor(15,0);
    lcd.write(1);
    
} 
