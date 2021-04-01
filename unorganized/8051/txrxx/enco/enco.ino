void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3,INPUT);
   pinMode(5,INPUT);
    pinMode(7,INPUT);
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
void loop() {
  // put your main code here, to run repeatedly:
  bool a0=digitalRead(3);
  bool a1=digitalRead(5);
  bool a2=digitalRead(7);
Serial.print("A2 A1 A0: ");
Serial.print(a2);
Serial.print(" ");
Serial.print(a1);
Serial.print(" ");
Serial.print(a0);
Serial.print(" ");
Serial.print(conv(a0,a1,a2));
Serial.println(" ");
}
