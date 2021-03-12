#define clockpin D3
#define latchpin D1
#define datapin D0
byte leds = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(D4,INPUT);
  pinMode(D2,INPUT);
  pinMode(datapin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  digitalWrite(latchpin, LOW);
  digitalWrite(clockpin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds=0;
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, leds);
  digitalWrite(latchpin, HIGH);
  delay(100);
  leds=B10101010;
    digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, leds);
  digitalWrite(latchpin, HIGH);
  delay(100);
}
