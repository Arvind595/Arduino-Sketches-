/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
//avrdude -c avrisp -p m32 -P COM3 -b 19200 -U flash:w:"C:\Users\Aravind Anirudh\AppData\Local\Temp\arduino_build_174955\Blink.ino.hex":i
// the setup function runs once when you press reset or power the board
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PD0 8
#define PD1 9
#define PD2 10
#define PD3 11
#define PD4 12
#define PD5 13
#define PD6 14
#define PD7 15

#define PC0 16
#define PC1 17
#define PC2 18
#define PC3 19
#define PC4 20
#define PC5 21
#define PC6 22
#define PC7 23

#define PA0 31
#define PA1 30
#define PA2 29
#define PA3 28
#define PA4 27
#define PA5 26
#define PA6 25
#define PA7 24
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PD2, OUTPUT);
  pinMode(PD1, OUTPUT);
  pinMode(PC0, INPUT);
  pinMode(PD3, INPUT);
//  for (int i = 0; i <= 31; i++) {
//    if (i != 11 & i != 16) {
//      pinMode(i, OUTPUT);
//    }
//  }
//  for (int i = 0; i <= 31; i++) {
//    if (i != 11 & i != 16) {
//      digitalWrite(i, 0);
//    }
//  }
  digitalWrite(PD2, 1);
  digitalWrite(PD1, 1);
//  ADCSRA = ADCSRA & B10000000;
//  ACSR = B10000000;
  //DIDRO = DIDRO | B00111111;
}

// the loop function runs over and over again forever
void loop() {
  bool state = digitalRead(PC0);
  bool state2 = digitalRead(PD3);
  if (state == true & state2 == true) {
    blinky(800);
  }
  else if (state == true & state2 == false) {
    digitalWrite(PD2, LOW);
    digitalWrite(PD1, HIGH);
  }
  else if (state == false & state2 == true) {
    digitalWrite(PD2, HIGH);
    digitalWrite(PD1, LOW);
  }
  else if (state == false & state2 == false) {
    digitalWrite(PD2, HIGH);
    digitalWrite(PD1, HIGH);
  }
}
void blinky(int wait) {
  digitalWrite(PD2, HIGH);
  digitalWrite(PD1, LOW);
  delay(wait);
  digitalWrite(PD2, LOW);
  digitalWrite(PD1, HIGH);
  delay(wait);
}
