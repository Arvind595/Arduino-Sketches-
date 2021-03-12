#include <ShiftRegister74HC595.h>
// parameters: <number of shift registers> (data pin, clock pin, latch pin)
ShiftRegister74HC595<1> sr(13, 15, 12);
#define bz 14
#define F_MSB 5
#define R  4
#define L_LSB 0
bool f = 0, r = 0, l = 0;
byte level = 0;
void setup() {
  delay(2000);
  pinMode(F_MSB, INPUT);
  pinMode(R, INPUT);
  pinMode(L_LSB, INPUT);
  pinMode(bz, OUTPUT);
  sr.setAll(LOW);
}
void buzzer() {
  tone(bz, 2840);
  delay(80);
  noTone(bz);
  delay(100);
}
byte conv(bool a, bool b, bool c) {
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
void updateout() {
  //B76543210

  if (level == 0) {
    sr.set(0, HIGH);
    sr.set(1, LOW);
    sr.set(2, LOW);
    sr.set(3, LOW);
    sr.set(4, HIGH);
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
void loop() {
  if (f == 1 && r == 1 && l == 1) {
    buzzer();
  }
  else  digitalWrite(bz, LOW);

  level = conv(f, r, l);
  updateout();

  f =0;// digitalRead(F_MSB);//constant pin
r=0;
l=0;
 // if (digitalRead(R) == HIGH) { //check for full cycle
   // delay(1700);
    //if (digitalRead(R) == HIGH) {
      //r = 1;
    //}
   // else r = 0;
  //}

//  if (digitalRead(L_LSB) == HIGH) {
//    delay(1700);
//    if (digitalRead(L_LSB) == HIGH) {
//      l = 1;
//    }
//    else l = 0;
//  }
}
