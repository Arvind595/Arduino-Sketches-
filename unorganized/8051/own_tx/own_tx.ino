void setup() {
pinMode(2,OUTPUT);
digitalWrite(2,HIGH);
}
void loop() {
  byte input='H';
  int i;
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(300); 
  for(i=0; i<8; i++){
  if(bitRead(input,i)==1)
  digitalWrite(2, LOW);
  else
  digitalWrite(2, HIGH);
  delay(100);
  if(bitRead(input,i)==1)
  digitalWrite(2, HIGH);
  else
  digitalWrite(2, LOW);
  delay(100); }
  digitalWrite(2,HIGH);
}  
