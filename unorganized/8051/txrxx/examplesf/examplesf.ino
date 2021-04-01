/*
  ShiftRegister74HC595 - Library for simplified control of 74HC595 shift registers.
  Created by Timo Denk (www.timodenk.com), Nov 2014.
  Additional information is available at http://shiftregister.simsso.de/
  Released into the public domain.
*/

#include <ShiftRegister74HC595.h>

// create a global shift register object
// parameters: (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (1, 7, 6, 8); 
 
void setup() { 
}

void loop() {

 
  
  sr.setAllLow(); // set all pins LOW
  delay(500); 
  

  uint8_t pinValues[] = { B10101010 }; 
  sr.setAll(pinValues); 
  delay(1000);

  
  
}
