//last modified 7-12-19
#include <SPI.h>

#include <ShiftRegister74HC595.h>
// LCD SHIFT REG CONNECTIONS latch (9) clock (13) data(11) true
ShiftRegister74HC595 sr (1, 7, 6, 8);// OUTPUT SHIFT REG CONNECRTIONS latch
// parameters: (number of shift registers, data pin, clock pin, latch pin)
const int F_MSB = 2;
const int R = 3;
const int L_LSB = 4;
const int bz = 5;
bool f = 0, r = 0, l = 0;
int i = 0, j = 0, level = 0, mapping2 = 0, mapping1 = 0, tank1 = 0, tank2 = 0;
void setup() {
  Serial.begin(9200);
  
  pinMode(F_MSB, INPUT_PULLUP);
  pinMode(R, INPUT);
  pinMode(L_LSB, INPUT);
  pinMode(bz, OUTPUT);
  sr.setAll(HIGH);
delay (2000);

}
void loop() {
  // put your main code here, to run repeatedly:
// sr.set(0, HIGH);
//    sr.set(1, HIGH);
//    sr.set(2, HIGH);
//    sr.set(3, HIGH);
//    sr.set(4, HIGH);
//    sr.set(5, LOW);
//    sr.set(6, LOW);
//    sr.set(7, LOW);
}
