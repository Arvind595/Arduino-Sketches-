#include <SPI.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include <ShiftRegister74HC595.h>
LiquidCrystal lcd(9);// LCD SHIFT REG CONNECTIONS latch (9) clock (13) data(11) true
ShiftRegister74HC595 sr (1, 7, 6, 8);// OUTPUT SHIFT REG CONNECRTIONS latch
// parameters: (number of shift registers, data pin, clock pin, latch pin)
//const int F_MSB = 4;
//const int R = 3;
//const int L_LSB = 2;
const int bz = 5;
bool f = 0, r = 0, l = 0;
int i = 0, j = 0,level,stor, mapping2 = 0, mapping1 = 0, tank1 = 0, tank2 = 0;
void setup() {
 
  Serial.begin(9200);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.home();
  lcd.print("TANK 1 = ");
  lcd.setCursor(0, 1);
  lcd.print("TANK 2 = ");
  lcd.setCursor(12, 0);
  lcd.print("%");
  lcd.setCursor(12, 1);
  lcd.print("%");
//  pinMode(F_MSB, INPUT);
//  pinMode(R, INPUT);
//  pinMode(L_LSB, INPUT);
  pinMode(bz, OUTPUT);
  sr.setAll(LOW);
  EEPROM.write(0, 9);

}
void disp() {
  lcd.setCursor(15, 0);
  lcd.print(level);
  if (tank1 == 0) {
    lcd.setCursor(11, 0);
    lcd.print("0");
  }
  if (tank2 == 0) {
    lcd.setCursor(11, 1);
    lcd.print("0");
  }
  if (tank1 <= 99) {
    lcd.setCursor(9, 0);
    lcd.print(" ");
    lcd.setCursor(10, 0);

  }
  else {
    lcd.setCursor(9, 0);
  }

  lcd.print(tank1);



  if (tank2 <= 99) {
    lcd.setCursor(9, 1);
    lcd.print(" ");
    lcd.setCursor(10, 1);

  }
  else {
    lcd.setCursor(9, 1);
  }

  lcd.print(tank2);

}
int conv(bool a, bool b, bool c) {
  if (a == 0 && b == 0 && c == 0) {
    return 0;
  }
  if (a == 0 && b == 0 && c == 1) {
    return 1;
  }
  if (a == 0 && b == 1 && c == 0) {
    return 2;
  }
  if (a == 0 && b == 1 && c == 1) {
    return 3;
  }
  if (a == 1 && b == 0 && c == 0) {
    return 4;
  }
  if (a == 1 && b == 0 && c == 1) {
    return 5;
  }
  if (a == 1 && b == 1 && c == 0) {
    return 6;
  }
  if (a == 1 && b == 1 && c == 1) {
    return 7;
  }
}
void buzz() {
  tone(bz, 2500);
  delay(80);
  noTone(bz);
  delay(100);
}
void updateout() {
  //B76543210

  if (level == 0) {
    sr.set(0, HIGH);
    sr.set(1, LOW);
    sr.set(2, LOW);
    sr.set(3, LOW);
    sr.set(4, LOW);
    sr.set(5, LOW);
    sr.set(6, LOW);
    sr.set(7, LOW);

  }
  if (level == 1) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, LOW);
    sr.set(3, LOW);
    sr.set(4, LOW);
    sr.set(5, LOW);
    sr.set(6, LOW);
    sr.set(7, LOW);
  }
  if (level == 2) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, HIGH);
    sr.set(3, LOW);
    sr.set(4, LOW);
    sr.set(5, LOW);
    sr.set(6, LOW);
    sr.set(7, LOW);
  }
  if (level == 3) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, HIGH);
    sr.set(3, HIGH);
    sr.set(4, LOW);
    sr.set(5, LOW);
    sr.set(6, LOW);
    sr.set(7, LOW);
  }
  if (level == 4) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, HIGH);
    sr.set(3, HIGH);
    sr.set(4, HIGH);
    sr.set(5, LOW);
    sr.set(6, LOW);
    sr.set(7, LOW);
  }
  if (level == 5) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, HIGH);
    sr.set(3, HIGH);
    sr.set(4, HIGH);
    sr.set(5, HIGH);
    sr.set(6, LOW);
    sr.set(7, LOW);
  }
  if (level == 6) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, HIGH);
    sr.set(3, HIGH);
    sr.set(4, HIGH);
    sr.set(5, HIGH);
    sr.set(6, HIGH);
    sr.set(7, LOW);
  }
  if (level == 7) {

    sr.set(0, HIGH);
    sr.set(1, HIGH);
    sr.set(2, HIGH);
    sr.set(3, HIGH);
    sr.set(4, HIGH);
    sr.set(5, HIGH);
    sr.set(6, HIGH);
    sr.set(7, HIGH);

  }
}
void check(){
  if (Serial.available()>0) 
{
 stor = Serial.parseInt();
 EEPROM.write(0, stor);
 
}
}
void loop() {

//  f = digitalRead(F_MSB);
//  r = digitalRead(R);
//  l = digitalRead(L_LSB);

//  if (f == 1 && r == 1 && l == 1) {
//    buzz();
//  }
check();
level=EEPROM.read(0);
if (level>=3 && level==7){
  buzz();
}
  else digitalWrite(bz, LOW);

//  level = conv(f, r, l);
  updateout();

  if (level >= 0 && level <= 3) {
    mapping1 = level;
  }
  else mapping1 = 3;


  if (level >= 4 && level <= 7) {
    mapping2 = (level - 4);
  }
  else mapping2 = 0;

  tank1 = map(mapping1, 0, 3, 0, 100);
  tank2 = map(mapping2, 0, 3, 0, 100);

  disp();

//  Serial.print("bits  ");
//  Serial.print(f);
//  Serial.print(r);
//  Serial.print(l);
//  Serial.print(" ");
//  Serial.print("   level= ");
//  Serial.print(level);
//  Serial.print(" ");
//  Serial.println(" ");

}
