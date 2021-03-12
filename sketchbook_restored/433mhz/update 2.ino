#include <LiquidCrystal.h>
const int rs = 12, en = 13, d4 = A1, d5 = A2, d6 =A3, d7 = A4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include<SimpleDHT.h>
int pinDHT11 = A0;
SimpleDHT11 dht11;

int buzzer= A5;

int trigPin1=2;// LEFT SENSOR.
int echoPin1=4;//NON PWM PINS.

int trigPin2=7;//MIDDLE SENSOR.
int echoPin2=8;//NON PWM PINS.

int trigPin3=10;// RIGHT SENSOR.
int echoPin3=11;//NON PWM PINS.

// A IS MOTAR A AND B IS MOTOR B.
// MOTORS ARE AALWAYS ENABLE.

int  pinA1=6;//PWM PINS FOR SPEED CONTROL.
int pinA2=3;//PWM PINS FOR SPEED CONTROL.
int pinB1=9;//PWM PINS FOR SPEED CONTROL.
int pinB2=5;//PWM PINS FOR SPEED CONTROL.

 float duration1, distance1, speed1, duration2, distance2,speed2, duration3, distance3, speed3;
    
void setup() {
  Serial.begin (19200);
  lcd.begin(16,2);
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
   pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(pinA1,OUTPUT);
  pinMode(pinA2,OUTPUT);
  pinMode(pinB1,OUTPUT);
pinMode(pinB2,OUTPUT);
}
// Create motor functions
void motorAforward() {
 digitalWrite (pinA1, 0.8*255);
 digitalWrite (pinA2, LOW);
}
void motorBforward() {
 digitalWrite (pinB1, LOW);
 analogWrite (pinB2, 0.8*255);
}
void motorAbackward() {
 digitalWrite (pinA1, LOW);
 analogWrite (pinA2, 0.8*255);
}
void motorBbackward() { 
 digitalWrite (pinB1, 0.8*255);
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
void checkPlane(){
  if (( 8<= distance1 >=11) && ( 8<= distance2 >=11) && ( 8<= distance3 >=11 ) ){
    carForward();
    lowBeep();
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Going good!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3);
  
  } 
}
void checkLeft(){
  if (distance1>11){
    carStop();
    carLeft();
    highBeep();
    lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Crater detected!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3); 
  }
  else if (distance1<8){
    carStop();
    carLeft();
    highBeep();
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Hump detected!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3);
  }
}
void checkStraight(){
  if (distance2>11){
    carStop();
    carBackward();
    highBeep();
    lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Crater detected!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3); 
  }
  else if (distance2<8){
    carStop();
    carBackward();
    highBeep();
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Hump detected!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3);
  }
}
  void checkRight(){
    if (distance3>11){
      carStop();
    carRight();
    highBeep();
    lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Crater detected!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3); 
  }
  else if (distance3<8){
    carStop();
    carRight();
    highBeep();
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("Hump detected!");
     lcd.setCursor(0,1);
     lcd.print(distance1);
     lcd.print(" ");
     lcd.print(distance2);
     lcd.print(" ");
     lcd.print(distance3);
       }
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
  
  delay(1);

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
  
  delay(1);
  
    
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
  Serial.print("  T  ");
  Serial.println(temp); 
   Serial.print("   H   ");
  Serial.println(humi);
  Serial.print("  S  ");
  Serial.println(speed1);

  checkPlane();
  checkStraight();
  checkLeft();
  checkRight();
}


