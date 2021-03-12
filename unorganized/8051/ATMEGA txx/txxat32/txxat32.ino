//atmel32l
//5feb2020
//txx
void setup() {
  pinMode(24, INPUT_PULLUP);
  pinMode(25, INPUT_PULLUP);
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP); //msb

  pinMode(23, OUTPUT); //f
  pinMode(22, OUTPUT); //b
  pinMode(21, OUTPUT); //l

  digitalWrite(23, LOW);
  digitalWrite(22, LOW);
  digitalWrite(21, LOW);
}
void loop() {
  int binary = (1 * (!digitalRead(24)) + 2 * (!digitalRead(25)) + 4 * (!digitalRead(26)) + 8 * (!digitalRead(27)) + 16 * (!digitalRead(28)) + 32 * (!digitalRead(29)) + 64 * (!digitalRead(30)) + 128 * (!digitalRead(31)));

  if  (binary <= 255 && binary >= 128 ) {
    digitalWrite(23, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(21, HIGH);
  }
  else if  (binary <= 127 && binary >= 64) {
    digitalWrite(23, HIGH);
    digitalWrite(22, HIGH);
    digitalWrite(21, LOW);
  }
  else if  (binary <= 63 && binary >= 32 ) {
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
    digitalWrite(21, HIGH);
  }
  else if  (binary <= 31 && binary >= 16 ) {
    digitalWrite(23, HIGH);
    digitalWrite(22, LOW);
    digitalWrite(21, LOW);
  }
  else  if  (binary <= 15 && binary >= 8 ) {
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
    digitalWrite(21, HIGH);
  }
  else if  (binary <= 7 && binary >= 4 ) {
    digitalWrite(23, LOW);
    digitalWrite(22, HIGH);
    digitalWrite(21, LOW);
  }
  if  (binary <= 3 && binary >= 2 ) {
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    digitalWrite(21, HIGH);
  }
  else if  (binary <= 1 && binary >= 0 ) {
    digitalWrite(23, LOW);
    digitalWrite(22, LOW);
    digitalWrite(21, LOW);
  }
  delay(100);
}
