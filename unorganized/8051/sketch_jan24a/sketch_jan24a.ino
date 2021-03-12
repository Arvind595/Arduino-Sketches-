void setup() {
  // put your setup code here, to run once:
pinMode(2,OUTPUT);
digitalWrite(2,HIGH);
pinMode(5,INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(2,LOW);
if(digitalRead(5)==HIGH){
  digitalWrite(2,LOW);
  Serial.println(1);
}
digitalWrite(2,HIGH);
}
