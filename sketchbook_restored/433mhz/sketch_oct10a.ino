#include <Servo.h>
Servo servo;
long count=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(7,INPUT);
pinMode(5,INPUT);
pinMode(9,OUTPUT);
digitalWrite(9,LOW);
delay(50);
servo.attach(10);


}
void ENTER(){
  
count++;
Serial.println(count);
servo.write(0);
delay(30);
digitalWrite(9,LOW);
delay(970);
}
void EXIT(){
  count--;
 
Serial.println(count);
delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(7)==HIGH){
ENTER();
  }
  else if (digitalRead(5)==HIGH){ 
EXIT();
}
if(count<=0){
digitalWrite(9,HIGH);
servo.write(70);
delay(30);
}
}

