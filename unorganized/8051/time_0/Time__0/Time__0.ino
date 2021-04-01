#include <LiquidCrystal.h>
#include <SPI.h>

LiquidCrystal lcd(10);

int h=0;
int m;
int s;

int TIME;


const int hs=8;
const int ms=9;

int state1;
int state2;

void setup()
{
  lcd.begin(16,2);
    lcd.clear();
}
void loop()
{
s=s+1;
 lcd.setCursor(0,0);
 
    
 lcd.print("TIME:");
 lcd.print(h);
        
lcd.print(":");
 lcd.print(m);
    lcd.print(":");
lcd.print(s);
  
    
    switch(h){
        case 0 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 1 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 2 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 3 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 4 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 5 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 6 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 7 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 8 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 9 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 10 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 11 :
        lcd.setCursor(0,1);
        lcd.print("GOOD MORNING!");
        break;
        case 12 :
        lcd.setCursor(0,1);
        lcd.print("GOOD AFTERNOON!");
        break;
        case 13 :
        lcd.setCursor(0,1);
        lcd.print("GOOD AFTERNOON!");
        break;
        case 14 :
        lcd.setCursor(0,1);
        lcd.print("GOOD AFTERNOON!");
        break;
        case 15 :
        lcd.setCursor(0,1);
        lcd.print("GOOD AFTERNOON!");
        break;
        case 16 :
        lcd.setCursor(0,1);
        lcd.print("GOOD EVENING!");
        break;
        case 17 :
        lcd.setCursor(0,1);
        lcd.print("GOOD EVENING!");
        break;
        case 18 :
        lcd.setCursor(0,1);
        lcd.print("GOOD EVENING!");
        break;
        case 19 :
        lcd.setCursor(0,1);
        lcd.print("GOOD EVENING!");
        break;
        case 20 :
        lcd.setCursor(0,1);
        lcd.print("GOOD NIGHT!");
        break;
        case 21 :
        lcd.setCursor(0,1);
        lcd.print("GOOD NIGHT!");
        break;
        case 22 :
        lcd.setCursor(0,1);
        lcd.print("GOOD NIGHT!");
        break;
        case 23 :
        lcd.setCursor(0,1);
        lcd.print("GOOD NIGHT!");
        break;
        case 24 :
        lcd.setCursor(0,1);
        lcd.print("GOOD NIGHT!");
        break;
    }
    delay(1000);
    lcd.clear();
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
  
 }
 if(h==24)
 {
  h=0;
 }

 state1=digitalRead(hs);

 if(state1==1)
{
  h=h+1;
 
  
  if(h==24)h=0;
}
state2=digitalRead(ms);
if(state2==1){
      
  s=0;
  m=m+1;

}
}
 
 

