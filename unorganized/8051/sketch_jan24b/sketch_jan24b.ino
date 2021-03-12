void setup() {
  // put your setup code here, to run once:

pinMode(12,OUTPUT);
pinMode(11,OUTPUT);
pinMode(11,OUTPUT);
}

void updateout(short level) {
  //B76543210

  if (level == 0) {
    digitalWrite(12,LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
   

  }
  if (level == 1) {

    digitalWrite(12,LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
 
  }
  if (level == 2) {

    digitalWrite(12,LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  
  }
  if (level == 3) {

    digitalWrite(12,LOW);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    
   
  }
  if (level == 4) {

    digitalWrite(12,HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    
  }
  if (level == 5) {

    digitalWrite(12,HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);

  }
  if (level == 6) {

    digitalWrite(12,HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
  if (level == 7) {

    digitalWrite(12,HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
  }}
 
  

void loop() {
  for (short i=0;i<8;i++){
    updateout(i);
    delay(1000);
  }
 /*/ pinMode(11,2OUTPUT);
 digitalWrite(11,2LOW);
 delay(500);
 digitalWrite(11,2HIGH);
 //pinMode(11,2INPUT);
 delay(500); 
 //pinMode(11,1OUTPUT);
 digitalWrite(11,1LOW);
 delay(500);
 digitalWrite(11,1HIGH);
 // pinMode(11,1INPUT);
 delay(500); */
}
