int ir1 = 2;
int ir2= 3;


int led1 = 11;
int led2 = 12;

void setup()
{
        Serial.begin(9600);     
        pinMode(ir1 , INPUT); pinMode(ir2 , INPUT);
        pinMode(led1, OUTPUT); pinMode(led2, OUTPUT);
       
}

void loop()
{
       int readsen1 = digitalRead( ir1 );
       int readsen2 = digitalRead( ir2 );
       int val1=digitalRead(2);
       int val2=digitalRead(3);

if(readsen1 == HIGH && readsen2 == HIGH )
{
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
}
else if(readsen1 == LOW && readsen2 == HIGH )
{
       digitalWrite(led1, LOW);
       digitalWrite(led2, HIGH);
}
else if(readsen1 == HIGH && readsen2 == LOW )
{
       digitalWrite(led1, HIGH);
       digitalWrite(led2, LOW);
}
else
{
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
}
delay(1);
}
