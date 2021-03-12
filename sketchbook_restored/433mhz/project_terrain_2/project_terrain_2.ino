
#include<Adafruit_Sensor.h>
#include <dht.h>
#define DHT11_PIN A0

dht DHT;

int trigPin1=2;
int echoPin1=3;

int trigPin2=4;
int echoPin2=5;

int trigPin3=6;
int echoPin3=7;



void setup() {
  Serial.begin (19200);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
   pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  

}

void loop() {
  float duration1, distance1;
    float speed1;
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
   
     speed1 = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity); distance1 = (duration1 / 2) * (speed1 / 10000); 
 

   if (distance1 >= 500 || distance1 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print ( "Sensor1  ");
    Serial.print ( distance1);
    Serial.println("cm");
  }
  delay(100);
float duration2, distance2;
     float speed2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
    
 speed2 = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity); distance2 = (duration2 / 2) * (speed2 / 10000); 

   if (distance2 >= 500 || distance2 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor2  ");
    Serial.print(distance2);
    Serial.println("cm");
  }
  delay(100);
  float duration3, distance3;
     float speed3;
    
  digitalWrite(trigPin3, LOW);  
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
    
    speed3 = 331.4 + (0.606 * DHT.temperature) + (0.0124 * DHT.humidity); distance3 = (duration3 / 2) * (speed3 / 10000); 


   if (distance3 >= 500 || distance3 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor3  ");
    Serial.print(distance3);
    Serial.println("cm");
  }
  delay(100);

}
