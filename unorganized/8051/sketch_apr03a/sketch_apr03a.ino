#define buz 14
#define fpin 16
#define rpin 4
#define lpin 5
#define slatch 12
#define sclock 15
#define sdata 13
bool f = false;
bool r = false;
bool l = false;
byte leds = 0;
void setup() {
  delay(2000);
  Serial.begin(9600);
  pinMode(fpin, INPUT);
  pinMode(rpin, INPUT);
  pinMode(lpin, INPUT);

  pinMode(slatch, OUTPUT);
  pinMode(sdata, OUTPUT);
  pinMode(sclock, OUTPUT);

  digitalWrite(slatch, LOW);
  shiftOut(sdata, sclock, LSBFIRST, leds);
  digitalWrite(slatch, HIGH);
}
void loop() {
  byte level = 0;

  digitalWrite(slatch, LOW);
  shiftOut(sdata, sclock, LSBFIRST, leds);
  digitalWrite(slatch, HIGH);

  if (digitalRead(fpin)) f = true; //constant
  else f = false;
  if (digitalRead(rpin)) r = true;
  else r = false;
  if (digitalRead(lpin)) l = true;
  else l = false;
  Serial.print(f);
  Serial.print(r);
  Serial.println(l);

  if (f == 1 && r == 1 && l == 0) {
    level = 5;
  }
  else if (f == 1 && r == 0 && l == 1) {
    level = 4;
  }
  else if (f == 1 && r == 0 && l == 0) {
    level = 3;
  }
  else if (f == 0 && r == 1 && l == 0) {
    level = 2;
  }
  else if (f == 0 && r == 0 && l == 1) {
    level = 1;
  }
  else if ( f == 0 && r == 0 && l == 0) {
    level = 6;
  }

  switch (level) {
    case 1: leds = 128;
      break;
    case 2: leds = 129;
      break;
    case 3: leds = 137;
      break;
    case 4: leds = 139;
      break;
    case 5: leds = 203;
      break;
    case 6 : leds = 0;
      break;
    default : leds = 0;
      break;
  }

  if (leds == 0 | leds == 203 ) {
    digitalWrite(slatch, LOW);
    shiftOut(sdata, sclock, LSBFIRST, (((leds == 203) ? leds : 128)));
    digitalWrite(slatch, HIGH);
    delay((leds == 203) ? 25 : 250);
    digitalWrite(slatch, LOW);
    shiftOut(sdata, sclock, LSBFIRST, (leds == 203) ? 139 : 0);
    digitalWrite(slatch, HIGH);
    delay((leds == 203) ? 25 : 250);
  }
  digitalWrite(slatch, LOW);
  shiftOut(sdata, sclock, LSBFIRST, leds);
  digitalWrite(slatch, HIGH);
  leds = 0;


  Serial.println(level);

  f = false;
  r = false;
  l = false;

  if (level == 5) {
    buzz();
  }
}
void buzz() {
  tone(buz, 2840);
  delay(80);
  noTone(buz);
  //delay(100);
}
