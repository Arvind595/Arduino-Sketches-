int i, good, k;
byte data_in;
void setup() {
attachInterrupt(1,data_incoming,RISING);
pinMode(3,INPUT);
Serial.begin(115200);
}
void loop() {}
void data_incoming(){  
  detachInterrupt(1);
  while(1){
    if(digitalRead(3)==LOW){
      delay(350);
for(i=0; i<8; i++){
          if(digitalRead(3)==HIGH)
          bitWrite(data_in, i, 1);
          else
          bitWrite(data_in, i, 0);
          delay(200);
        }
Serial.println(char(data_in));
break;
}
 attachInterrupt(1,data_incoming,RISING); }
}
