const int bz =5;
void setup() {
  // put your setup code here, to run once:
pinMode(bz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 tone(bz, 2500);
  delay(80);
  noTone(bz);
  delay(100);
}
