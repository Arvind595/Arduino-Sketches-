void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop() {
  int x=-300;
  byte xlow = x & 0xff;
byte xhigh = (x >> 8);
Serial.println(xhigh,HEX);
Serial.println(xlow,HEX);
delay(1000);
}
