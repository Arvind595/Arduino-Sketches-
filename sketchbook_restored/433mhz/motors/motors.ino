int enA = 10;
int in1 = 9;
int in2 = 8;
 // motor two int enB = 5; int in3 = 7; int in4 = 6;
void setup() 
{
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
} 
void demoOne() 
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 200); 
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 200);
delay(2000);
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW); 
digitalWrite(in4, HIGH);
delay(2000);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW); 
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
} 
void demoTwo() 
{ 
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
for (int i = 0; i < 256; i++) 
{ 
analogWrite(enA, i);
analogWrite(enB, i);
delay(20); 
}  
for (int i = 255; i >= 0; --i)
{
analogWrite(enA, i);
analogWrite(enB, i);
delay(20); 
}
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW); 
}
 void loop() 
{ 
demoOne();
delay(1000);
demoTwo();
delay(1000);
}