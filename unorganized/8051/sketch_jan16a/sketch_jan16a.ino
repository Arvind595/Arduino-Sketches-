#define trigPin 2
#define echoPin 4
#include "DHT.h"
DHT dht(9, DHT11);
#include <LiquidCrystal.h>
LiquidCrystal lcd(7);
float duration, distance;
void setup() {
    lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, 1);
  
  digitalWrite(10, 0);
  digitalWrite(8, 1);
  
  Serial.begin(115200);
  dht.begin();
  lcd.clear();
lcd.print("distance");
delay(2000);
}
void loop() {
 lcd.clear();
    delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  float Speed = 331.4 + (0.606 * t) + (0.0124 * h);
  distance = (duration / 2) * (Speed / 10000);
  //distance = (duration / 2) * 0.0344;
  Serial.print(Speed);
  Serial.print(" Distance = ");
  Serial.print(distance);
  Serial.println(" cm");}
