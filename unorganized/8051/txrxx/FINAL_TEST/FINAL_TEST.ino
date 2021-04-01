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
String inString = "";
int val;
void setup() {
  Serial.begin(57600);
  
  pinMode(F_MSB, INPUT);
  pinMode(R, INPUT);
  pinMode(L_LSB, INPUT);
  pinMode(bz, OUTPUT);
  sr.setAll(LOW);


}
void buzz(int freq,int hd,int ld) {
  tone(bz, freq);
  delay(hd);
  noTone(bz);
  delay(ld);
}
void loop() {
  // put your main code here, to run repeatedly:
while (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
       
    }
    // if you get a newline, print the string, then the string's value:
    if (inChar == '\n') {
      Serial.print("Value:");
      val=inString.toInt();
      Serial.println(val);
      Serial.print("String: ");
      Serial.println(inString);
      // clear the string for new input:
      inString = "";
    }
  
    buzz(val,100,100);
    buzz(val,100,100);
    buzz(val,100,100);
    buzz(val,100,100);
    buzz(val,100,100);
    buzz(val,100,100);
    buzz(val,100,100);
   
}
}
