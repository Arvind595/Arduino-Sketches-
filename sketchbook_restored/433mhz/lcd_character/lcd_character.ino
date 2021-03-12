#include <LiquidCrystal.h>

byte box[8]={
    B1011111,
    B1000001,
    B1000001,
    B1000001,
    B1000001,
    B1000001,
    B1000001,
    B1111111
    
};
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup(){
    lcd.begin(16,2);
    lcd.createChar(2, box);
}
void loop(){
    lcd.write(2);
    delay(1000);
    lcd.clear();
}