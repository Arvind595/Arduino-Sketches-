
//avrdude -c avrisp -p m32 -P COM3 -b 19200 -U flash:w:"C:\Users\Aravind Anirudh\AppData\Local\Temp\arduino_build_174955\Blink.ino.hex":i
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PD0 8
#define PD1 9
#define PD2 10
#define PD3 11
#define PD4 12
#define PD5 13
#define PD6 14
#define PD7 15

#define PC0 16
#define PC1 17
#define PC2 18
#define PC3 19
#define PC4 20
#define PC5 21
#define PC6 22
#define PC7 23

#define PA0 31
#define PA1 30
#define PA2 29
#define PA3 28
#define PA4 27
#define PA5 26
#define PA6 25
#define PA7 24
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(PD2, OUTPUT);
  pinMode(PD1, OUTPUT);
  pinMode(PC0, INPUT);
  pinMode(PD3, INPUT);
//  for (int i = 0; i <= 31; i++) {
//    if (i != 11 & i != 16) {
//      pinMode(i, OUTPUT);
//    }
//  }
//  for (int i = 0; i <= 31; i++) {
//    if (i != 11 & i != 16) {
//      digitalWrite(i, 0);
//    }
//  }
  digitalWrite(PD2, 1);
  digitalWrite(PD1, 1);
//  ADCSRA = ADCSRA & B10000000;
//  ACSR = B10000000;
  //DIDRO = DIDRO | B00111111;
}

// the loop function runs over and over again forever
void loop() {
  bool state = digitalRead(PC0);
  bool state2 = digitalRead(PD3);
  if( state == true & state2 == false){
	digitalWrite(PD1,HIGH); // NO INVERT
	digitalWrite(PD2,LOW);
  }
  else if(state == false & state2== true){
	digitalWrite(PD1,LOW); // NO INVERT
	digitalWrite(PD2,HIGH);
  }
else if (state == false & state2 == false ){
	digitalWrite(PD1,HIGH);// INVERT
	digitalWrite(PD2,HIGH);
}

