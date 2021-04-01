/*
  ShiftRegister74HC595 - Library for simplified control of 74HC595 shift registers.
  Created by Timo Denk (www.timodenk.com), Nov 2014.
  Additional information is available at http://shiftregister.simsso.de/
  Released into the public domain.
*/

#include <ShiftRegister74HC595.h>
const int bz = 5;
// create a global shift register object
// parameters: (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (1, 7, 6, 8); 
 
void setup() { 
}
void buzz() {
  tone(bz, 2840);
  delay(80);
  noTone(bz);
  delay(100);
}
void loop() {

 
  

  // setting single pins
  for (int i = 0; i <= 8; i++) {
    
    sr.set(i, HIGH); // set single pin HIGH
    delay(100); 
  }
    for (int i = 8; i >= 0; i--) {
    
    sr.set(i, LOW); // set single pin HIGH
    delay(100); 
  }



 
 }
