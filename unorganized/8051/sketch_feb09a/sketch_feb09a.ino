
/*Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
#include <ShiftRegister74HC595.h>

// create a global shift register object
// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<1> sr(0, 1, 2);
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
 
 //avrdude -c avrisp -p m32 -P COM3 -b 19200 -U flash:w:"C:\Users\Aravind Anirudh\AppData\Local\Temp\arduino_build_544480\Blink32.ino.hex":i
}

// the loop routine runs over and over again forever:
void loop() {
  sr.set(1, HIGH); // set single pin HIGH
    delay(250);
    sr.set(1, LOW); // set single pin HIGH
    delay(250);
}
