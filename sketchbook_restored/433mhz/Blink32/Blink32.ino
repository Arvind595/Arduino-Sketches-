
/*Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 11;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
 //avrdude -c avrisp -p m32 -P COM3 -b 19200 -U flash:w:"C:\Users\Aravind Anirudh\AppData\Local\Temp\arduino_build_544480\Blink32.ino.hex":i
}

// the loop routine runs over and over again forever:
void loop() {
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
 
  // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);      
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
 
  // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); 
 
  // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); // wait for a second
}
