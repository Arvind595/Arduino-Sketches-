#include <LiquidCrystal.h>
const int rs = 12, en = 13, d4 = A1, d5 = A2, d6 =A3, d7 = A4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include<SimpleDHT.h>
int pinDHT11 = A0;
SimpleDHT11 dht11;

int buzzer= A5;

int trigPin1=6;
int echoPin1=7;

int trigPin2=8;
int echoPin2=9;

int trigPin3=10;
int echoPin3=11;

// A IS MOTAR A AND B IS MOTOR B.
// MOTORS ARE AALWAYS ENABLE.

int  pinA1=2;
int pinA2=3;
int pinB1=4;
int pinB2=5;

void setup() {
  Serial.begin (19200);
  lcd.begin(16,2);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
   pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  

}
// Create motor functions
void motorAforward() {
 digitalWrite (pinA1, HIGH);
 digitalWrite (pinA2, LOW);
}
void motorBforward() {
 digitalWrite (pinB1, LOW);
 digitalWrite (pinB2, HIGH);
}
void motorAbackward() {
 digitalWrite (pinA1, LOW);
 digitalWrite (pinA2, HIGH);
}
void motorBbackward() { 
 digitalWrite (pinB1, HIGH);
 digitalWrite (pinB2, LOW);
}
void motorAstop() {
 digitalWrite (pinA1, HIGH);
 digitalWrite (pinA2, HIGH);
}
void motorBstop() {
 digitalWrite (pinB1, HIGH);
 
 digitalWrite (pinB2, HIGH);
}
void motorAcoast() {
 digitalWrite (pinA1, LOW);
 digitalWrite (pinA2, LOW);
}
void motorBcoast() {
 digitalWrite (pinB1, LOW);
 digitalWrite (pinB2, LOW);
}
void carForward(){
  motorAforward();
  motorBforward();
}
void carBackward(){
  motorAbackward();
  motorBbackward();
}
void carLeft(){
  motorAstop();
  motorBforward();
}
void carRight(){
  motorBstop();
  motorAforward();
}
void carStop(){
  motorAstop();
  motorBstop();
}
void highBeep(){
    tone(buzzer,3200);
        delay(110);
        noTone(buzzer);
        delay(120);
  }
  void lowBeep(){
    tone(buzzer,3200);
        delay(300);
        noTone(buzzer);
        delay(2000);
  }
void loop() {
  byte temperature =0;
  byte humidity =0;
  int err = SimpleDHTErrSuccess;
  
  if ((err = dht11.read(pinDHT11,& temperature,&humidity, NULL)) != SimpleDHTErrSuccess){
    return;
  }
  
  float temp = (int)temperature;
  float humi = (int)humidity;
  
  float duration1, distance1;
    float speed1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
   
     speed1 = 331.4 + (0.606 * temp) + (0.0124 * humi);
     distance1 = (duration1 / 2) * (speed1 / 10000) - 1; 
 


    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
  
  delay(100);
float duration2, distance2;
     float speed2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
    
 speed2 = 331.4 + (0.606 * temp) + (0.0124 * humi);
 distance2 = (duration2 / 2) * (speed2 / 10000) - 1; 

 
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
  
  delay(100);
  float duration3, distance3;
     float speed3;
    
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
    
    speed3 = 331.4 + (0.606 * temp) + (0.0124 * humi);
    distance3 = (duration3 / 2) * (speed3 / 10000) - 1; 


    Serial.print("Sensor3  ");
    Serial.print(distance3);
    Serial.println("cm");
 
  delay(100);
  Serial.print("  T  ");
  Serial.println(temp); 
   Serial.print("   H   ");
  Serial.println(humi);

}
 
