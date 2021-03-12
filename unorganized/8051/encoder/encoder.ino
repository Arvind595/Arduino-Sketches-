void setup() {
  // put your setup code here, to run once:
pinMode(4,INPUT_PULLUP );
pinMode(5,INPUT_PULLUP );
pinMode(6,INPUT_PULLUP );
pinMode(7,INPUT_PULLUP );
pinMode(9,OUTPUT );
pinMode(10,OUTPUT );
Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
int binary = (1 * (!digitalRead(4)) + 2 * (!digitalRead(5)) + 4 * (!digitalRead(6)) + 8 * (!digitalRead(7)));
Serial.println(binary);
//  if  (binary <= 15 && binary >= 8 ) {
//    digitalWrite(9, HIGH);
//    digitalWrite(10, HIGH);
//Serial.println(binary);
//  }
//  else if  (binary <= 7 && binary >= 4 ) {
//    digitalWrite(9, HIGH);
//       digitalWrite(10, LOW);
//    
//  }
//  if  (binary <= 3 && binary >= 2 ) {
//    digitalWrite(9, LOW);
//    digitalWrite(10, HIGH);
//   
//  }
//  else if  (binary <= 1 && binary >= 0 ) {
//    digitalWrite(9, LOW);
//    digitalWrite(10, LOW);
//  
//}
  delay(500);
}
