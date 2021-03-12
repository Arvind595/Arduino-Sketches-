

// automatatic water valve controller.
//9/4/18
// refer circuit diagram for connections.

#include<Servo.h>
Servo servo;


#define in 3
#define out 4
#define fans 5
#define valve 2
#define lights 6


int count=0;

void IN()
{
    count++;
    
    Serial.print("people= ");
    Serial.println(count);
    delay(1000);
}

void OUT()
{
  count--;
    
    Serial.print("people= ");
    Serial.println(count);
    delay(1000);
}

void setup()
{
  servo.attach(9);
  Serial.begin(9600);
  
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(valve, OUTPUT);
  pinMode (fans, OUTPUT);
  pinMode (lights, OUTPUT);
    pinMode(7,OUTPUT);
      pinMode(8,OUTPUT);
    pinMode(10,OUTPUT);
      pinMode(11,OUTPUT);
      pinMode(12,OUTPUT);
      pinMode(13,OUTPUT);
 delay(1000);
}

void loop()
{  
  
  if(digitalRead(in))
  IN();
  if(digitalRead(out))
  OUT();
  
  if(count<=0)
  {
    
    digitalWrite(valve, LOW);
     digitalWrite(fans, LOW);
          digitalWrite(lights, LOW);
          
          if (servo.read()>100){// assuming that on position is 180 degree
            servo.write (0);
            delay(15);
          }
      
     servo.write(0);
    delay(200);
  }
  
  else
    digitalWrite(valve, HIGH);
       digitalWrite(fans, HIGH);
          digitalWrite(lights, HIGH);
          if (servo.read()<90){// assuming that off position is 0 degree
            servo.write(180);
          delay(15);
          }
          servo.write(180);
  
}
