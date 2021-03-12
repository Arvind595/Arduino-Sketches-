void setup() {
 Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(LED_BUILTIN,OUTPUT);
for(int i=0;i<20;i++){
  if(i!=2)
  pinMode(i,OUTPUT);
}
  pinMode(2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), message, FALLING);
}
void message(){
  detachInterrupt(2);
 digitalWrite(13,1);
 delay(1000);
 digitalWrite(13,0);
}
void loop() {

//HERE ON THE CHIP IS DEEP SLEEP SUB MICRO AMP FOREVER
//disable adc
ADCSRA &= ~(1<<7);
//sleep forever
SMCR |= (1<<2);
SMCR |=1;
//bod disable
MCUCR |= (3<<5);
MCUCR = (MCUCR & ~(1<<5))| (1<<6);
__asm__ __volatile__("sleep");
delay(1000);
}
