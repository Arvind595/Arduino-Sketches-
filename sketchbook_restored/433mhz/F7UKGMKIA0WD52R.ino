//Lights control system using IR tx and IR Rx
int i,j;
int ir1 = 2;//output of ir receiveer 1
int ir2 = 3;//output of ir receiveer 2
int ir3 = 4;//output of ir receiveer 3
int ir4 = 5;//output of ir receiveer 4

int led1 = 12;//light of room1
int led2 = 13;//light of room2

void setup()
{
        i=0;j=0;    
        pinMode(ir1 , INPUT); pinMode(ir2 , INPUT);
        pinMode(ir3 , INPUT); pinMode(ir4 , INPUT);
        pinMode(led1, OUTPUT); pinMode(led2, OUTPUT);
}

void loop()
{
       int readsen1 = digitalRead( ir1 );
       int val1=digitalRead(2);
                        
      if(val1==1)
      {delay(500);
        int readsen2 = digitalRead( ir2 );
        int val2=digitalRead(3);
         if(val2==1)
         {i++;}
      }
      int readsen2 = digitalRead( ir2 );
      int val2=digitalRead(3);
      if(val2==1)
      { delay(500);
        int readsen1 = digitalRead( ir1 );
        int val1=digitalRead(2);
        if(val1==1)
        {i--;}
      }
      
       int readsen3 = digitalRead( ir3 );
       int val3=digitalRead(4);
              
       if(val3==1)
      { delay(500);
        int readsen4 = digitalRead( ir4 );
        int val4=digitalRead(5);
        if(val4==1)
        {j++;i--;}
      }
        int readsen4 = digitalRead( ir4 );
        int val4=digitalRead(5);
      if(val4==1)
      { delay(500);
        int readsen3 = digitalRead( ir3 );
        int val3=digitalRead(4);
        if(val3==1)
        {j--;i++;}
      }
  
    if(i>0)
  {digitalWrite(led1, HIGH);}
  else
  {digitalWrite(led1, LOW);}
  
   if(j>0)
  {digitalWrite(led2, HIGH);}
  else
  {digitalWrite(led2, LOW);}
      
}
