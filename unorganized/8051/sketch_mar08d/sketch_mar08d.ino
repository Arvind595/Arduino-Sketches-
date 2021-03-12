#include<Servo.h>

Servo motor;

void setup() {
  delay(10);
Serial.begin(115200);
  motor.attach(9);
  delay(10);
}
void loop() {
  
  motor.write(180);
  Serial.println(motor.read());
  delay(1000);
  motor.write(0);
  Serial.println(motor.read());
  delay(1000);
  
}
