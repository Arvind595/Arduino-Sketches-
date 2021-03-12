#define Player1 4
#define Player2 5
#define Player1_out 6
#define Player2_out 7
#define buzzer 9
#define minimum 1000
#define maximum 5000
bool p1=0;
bool p2=0;
byte p1Score=0;
byte p2Score=0;
void setup() {
  // put your setup code here, to run once:
pinMode(Player1,INPUT);
pinMode(Player2,INPUT);
pinMode(buzzer,OUTPUT);
randomSeed(analogRead(0));
digitalWrite(Player1_out,LOW);
digitalWrite(Player2_out,LOW);
}
void win_sound(){
  
}
void getreaction(){
  while((p1 || p2)!=1){
  p1=digitalRead(Player1);
  p2=digitalRead(Player2);
  }
}
void socreUpdate(bool p1,bool p2){
  if(p1) p1Score++;
  else p2Score++;
}
void notifyPlayer(){
  if(p1){
  digitalWrite(Player1_out,HIGH);
}
else digitalWrite(Player1_out,LOW);

if(p2){
  digitalWrite(Player2_out,HIGH);
}
else digitalWrite(Player2_out,LOW);
}
void blinkP1(){
  for(int i=0;i<6;i++){
  digitalWrite(Player1_out,HIGH);
  delay(100);
  digitalWrite(Player1_out,LOW);
  delay(100);
  }
  digitalWrite(Player1_out,HIGH);
}
void blinkP2(){
  for(int i=0;i<6;i++){
  digitalWrite(Player2_out,HIGH);
  delay(100);
  digitalWrite(Player2_out,LOW);
  delay(100);
  }
  digitalWrite(Player2_out,HIGH);
}
void loop() {
  
for(int i=0;i<5;i++){
p1=0;
p2=0;
long time_delay=random(minimum,maximum);
delay(time_delay);
getreaction();
scoreUpdate(p1,p2);
notifyPlayer();
delay(1000);
}
if(p1Score>p2Score){
  //p1 won
  blinkP1();
}
else blinkP2();
delay(5000);
}
