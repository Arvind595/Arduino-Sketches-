void setup() {
  // put your setup code here, to run once:
pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 tone(3, 2840);
  delay(80);
  noTone(3);
  delay(100);
}
