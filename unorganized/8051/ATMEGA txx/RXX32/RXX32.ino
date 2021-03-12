//ATMEL32 RXXX
#include <ShiftRegister74HC595.h>
ShiftRegister74HC595<1> sr(7, 6, 8);
// parameters: <number of shift registers>( data pin, clock pin, latch pin)

const int F_MSB = 8;
const int R = 9;
const int L_LSB = 10;
const int bz = 3;
bool f = 0, r = 0, l = 0;
int level = 0;

void setup() {
  pinMode(F_MSB, INPUT_PULLUP);
  pinMode(R, INPUT_PULLUP);
  pinMode(L_LSB, INPUT_PULLUP);
  pinMode(bz, OUTPUT);
  sr.setAll(LOW);

  for (int i = 0; i <= 8; i++) {

    sr.set(i, HIGH); // set single pin HIGH
    delay(50);
  }
  for (int i = 8; i >= 0; i--) {

    sr.set(i, LOW); // set single pin HIGH
    delay(50);
  }
  buzz();
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
  tone(bz, 2840);
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

  f = digitalRead(F_MSB);
  r = digitalRead(R);
  l = digitalRead(L_LSB);

  if (f == 1 && r == 1 && l == 1) {
    buzz();
  }
  else  digitalWrite(bz, LOW);

  level = conv(f, r, l);
  updateout();

}
