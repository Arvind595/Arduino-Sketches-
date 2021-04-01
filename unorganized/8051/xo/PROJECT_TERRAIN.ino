#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 13, d5 = A4, d6 = A3, d7 = A2;
LiquidCrystal lcd(rs, en, d4, d5, d6,d7);
#include <Servo.h>  
Servo myservo;
int servposnum = 0;
int servpos = 0;
const int leftIr=A1; //left side ir pins
const int rightIr=A6; //right side ir pins 
const int buzzer=A5; // buzzer pin radar sound
// Setup Motor A (front and rear) pins
int enableA = 2;
int pinA1 = 4;
int pinA2 = 3;
// Setup Motor B (front and rear) pins
int enableB = 7;
int pinB1 = 6;
int pinB2 = 5;
// Setup Ultrasonic Sensor pins
#define trigPin 9
#define echoPin 10

void setup() { // this section of codes runs only once  
    Serial.begin(115200);
    lcd.begin(16,2);
    lcd.print("Initilising...");
    lcd.setCursor(0,1);
    lcd.print("please wait...");
 delay(2000);
   pinMode (rightIr, INPUT);
   pinMode (leftIr, INPUT);
   pinMode (buzzer, OUTPUT);
   pinMode (enableA, OUTPUT);
   pinMode (pinA1, OUTPUT);
   pinMode (pinA2, OUTPUT);
   pinMode (enableB, OUTPUT);
   pinMode (pinB1, OUTPUT);
   pinMode (pinB2, OUTPUT); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   // Turn pin into servo driver. Calls pinMode. Returns 0 on failure.
   myservo.attach(8);
}
void loop() {

  // Main code goes here and will run repeatedly:
     car(); // function keeps moving car forward while distance > 15cm
     avoid(); // function makes car go back, turn slightly right to move forward in new direction
     notification();
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
void motorAon() {
 digitalWrite (enableA, HIGH);
}
void motorBon() {
 digitalWrite (enableB, HIGH);
}
void motorAoff() {
 digitalWrite (enableA, LOW);
}
void motorBoff() {
 digitalWrite (enableB, LOW);
}
// Setup movement functions
void forward (int duration) {
 motorAforward();
 motorBforward();
 delay (duration);
}
void backward (int duration) {
 motorAbackward();
 motorBbackward();
 delay (duration);
}
void right (int duration) {
 motorAbackward();
 motorBforward();
 delay (duration);
}
void left (int duration) {
 motorAforward();
 motorBbackward();
 delay (duration);
}
void coast (int duration) {
 motorAcoast();
 motorBcoast();
 delay (duration);
}
void breakRobot (int duration) {
 motorAstop();
 motorBstop();
 delay (duration);
}
void disableMotors() {
 motorAoff();
 motorBoff();
}
void enableMotors() {
 motorAon();
 motorBon();
}
// Setup Ultrasonic Sensor distance measuring
int distance() {
  int duration, distance, hump,crater;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
    hump = 11.7 - distance;
    crater = distance - 11.7;
  return distance;
    Serial.println(distance);
  delay(100);
   lcd.clear();
if(distance>11.748){
  lcd.setCursor(0,0);
  lcd.print("Hump!!");
  lcd.setCursor(0,1);
  lcd.print(hump);
}
else if(distance<11.748){
  lcd.setCursor(0,0);
  lcd.print("crater!");
  lcd.setCursor(0,1);
  lcd.print(crater);
}
else(distance==11.7);{
  lcd.setCursor(0,0);
  lcd.print("clear!");
  lcd.setCursor(0,1);
  lcd.print(distance);
}

}
void notification() {
  
 
 
  if(distance<10 || distance>13 ){
    tone(buzzer,3200);
        delay(110);
        noTone(buzzer);
        delay(120);
  }
  else{
    tone(buzzer,3200);
        delay(300);
        noTone(buzzer);
        delay(2000);
  }
}
// Setup the main car function
void car() {
int distance_0;
distance_0 = distance();
  // Keep moving forward in a straight line while distance of objects > 15cm
  while(distance_0 == 11.7)
  {
     // Keep moving servo motor back and forth to scan surroundings
     // This allows the ultrasonic sensor to see more to its left and right
     if(servposnum == 0)
     {
      myservo.writeMicroseconds (1900);
      servposnum = 1;
      delay(100);
 
     }
     else if(servposnum == 1)
     {
      myservo.writeMicroseconds (2200);
      servposnum = 2;
     delay(100);
 
     }
     else if(servposnum  == 2)
     {
      myservo.writeMicroseconds (1900);
      servposnum = 3;
      delay(100);
  
     }

     else if(servposnum == 3)
     {
      myservo.writeMicroseconds (1600);
      servposnum = 1;
      delay(100);
     }
     motorAon();
     motorBon();
     forward(1);    
     distance_0 = distance();
     
  }
  breakRobot(0);
}
void avoid()
{
    // Go back and turn slightly right to move car in new direction if object detected < 15cm away
    backward(500);
    right(360);
}


