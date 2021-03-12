#include <dht.h>
#include "HT1621.h"
HT1621 ht(13,12,8);
#define dht_apin A1 
 
dht DHT;
 
void setup(){
    ht.begin();  
  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);
    ht.clearDisp();
 pinMode(A0,OUTPUT); 
 pinMode(A2,OUTPUT);
 digitalWrite(A0,HIGH);
 digitalWrite(A2,LOW);
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);
}
void loop(){
    DHT.read11(dht_apin);
    int tempr=(int)DHT.temperature;
    int humi=(int)DHT.humidity;
    int msb;
    int lsb;
    int MSB;
    int LSB;
    if(tempr<100){
      msb=tempr/10;
      lsb=tempr%10;}
    
    else {msb=9;
          lsb=9;}
          
    if(humi<100){
      MSB=humi/10;
      LSB=humi%10;}
    
    else{MSB=9;
          LSB=9;}
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    ht.inWrite(7,lsb);
    ht.inWrite(6,msb);
    ht.inWrite(4,MSB);
    ht.inWrite(5,LSB);
    delay(2000);
}
