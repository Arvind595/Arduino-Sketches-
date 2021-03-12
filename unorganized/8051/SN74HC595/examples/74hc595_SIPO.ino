#include<SN74HC595.h>

SN74HC595 io(1,5,6,3,9);

void setup(){

}
void loop(){
  io.setAllHigh();
  for (int i=0;i<256;i++){
  io.brightness(i);
  delay(5);
}
for (int i=255;i>=0;i--){
io.brightness(i);
delay(5);
}
}
