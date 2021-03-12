#define slatch 12
#define sclock 15
#define sdata 13
byte leds = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(slatch, OUTPUT);
  pinMode(sdata, OUTPUT);
  pinMode(sclock, OUTPUT);
  digitalWrite(slatch, LOW);
  shiftOut(sdata, sclock, LSBFIRST, leds);
  digitalWrite(slatch, HIGH);

}

void loop() {
  int val = Serial.parseInt();
 leds=val;
//  switch (val) {
//    case 1: leds = 128;
//      break;
//    case 2: leds = 129;
//      break;
//    case 3: leds = 131;
//      break;
//    case 4: leds = 135;
//      break;
//    case 5: leds = 143;
//      break;
//    case 6: leds = 159;
//      break;
//    case 7: leds = 191;
//      break;
//    case 8: leds = 255;
//      break;
//    default : leds=0;
//      break;
//  }
  digitalWrite(slatch, LOW);
  shiftOut(sdata, sclock, LSBFIRST, leds);
  digitalWrite(slatch, HIGH);
  leds = 0;
}
