#include <HT1621.h>

HT1621 ht(13,12,8);// ss, w, data
//standartgithub
  // cs to pin 13
  // wr to pin 12
  // Data to pin 8
  // backlight to pin 10
  const short  val[]={250,96,188,244,102,214,222,112,254,246,126,206,154,236,158,30,218,110,10,232,138,122,204,62,118,26,214,142,234,230};
void setup() {
  Serial.begin(9600);
  
  ht.begin(); 
  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
  
  for(int i=0; i<127; i++)
    {ht.write(i,0);}
    delay(1000);
}
void loop(){
ht.clearDisp();
ht.specialSeg("d2",'y');
delay(1000);
ht.specialSeg("d1",'y');
delay(1000);
ht.inWrite(5,6);
ht.specialSeg("d2",'n');
delay(1000);
ht.specialSeg("d1",'n');
delay(1000);
//ht.inWrite(6,5,'e','e');
//delay(1000);
//ht.inWrite(7,5,'n','n');
//delay(1000);
//ht.write(14,0b11100000);
//ht.write(13,0b00001101);
//for(int i=1;i<8;i++){
//ht.inWrite(i,8);
//delay(1000);}
//for(int i=5;i<16;i++){
//  Serial.print(i);
//    Serial.print("  ");
//Serial.println(ht.read(i),BIN);
//delay(10);}
}
    
   
