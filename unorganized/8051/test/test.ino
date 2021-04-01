#include "HT1621Translator.h"
#include<HT1621.h>
HT1621 ht(13,12,8);
Translator TH(true);

void setup() {
  // put your setup code here, to run once:

  
  ht.begin(); 
  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
  randomSeed(analogRead(A0));
ht.write(1,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  long rndNo = TH.getRandomNumber();
  
  // This cannot be done - it is PRIVATE
  //float test = TH.getPi();

  Serial.println(rndNo);

  delay(2000);
}
