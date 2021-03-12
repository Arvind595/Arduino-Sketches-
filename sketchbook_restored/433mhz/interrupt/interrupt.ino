const int pins[3]= {3,4,5};
void setup(){
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    attachInterrupt(6,stop,FALLING);
}
void stop(){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
}

    void loop(){
    
}
