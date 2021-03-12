#define latchPin 6
#define dataPin 5
#define clockPin 3
#define out 7
void updateRegister(uint8_t value) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, value);
  digitalWrite(latchPin, HIGH);
  digitalWrite(latchPin, LOW);
}
void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  // put your setup code here, to run once:
  updateRegister(128);
  updateRegister(128);
  digitalWrite(out,OUTPUT);
  digitalWrite(out,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
