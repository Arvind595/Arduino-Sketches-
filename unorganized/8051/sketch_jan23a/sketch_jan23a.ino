
/*
 * \file HT1621-test.ino
 * \brief Simple test sketch for the HT1621 class.
 * \author Enrico Formenti
 * \date 4 february 2015
 * \version 1.0
 * \copyright BSD license, check the License page on the blog for more information. All this text must be
 *  included in any redistribution.
 *  <br><br>
 *  See macduino.blogspot.com for more details.
 */

#include "HT1621.h"
 int number;
// refere to Macduino website for pin connections and their meaning
HT1621 ht(13,12,8);// cs,wr,data
//const short  val[]={250,96,188,244,102,214,222,112,254,246,126,206,154,236,158,30,218,110,10,232,138,122,204,62,118,26,214,142,234,230};
//bin values for 0-9 and a-y char for 7segment all possible shapes 

  //const short val[10] = {250, 96, 188, 244, 102, 214, 222, 112, 254, 246};
  
  //const short val[10]={0xfa,0x60,0xbc,0xf4,0x66,0xd6,0xde,0x70,0xfe,0xf6}
  
  //val for Digits-7,6,9 segment 0-9 hex values , with lsb as special functions to use set lsb =1
  
  //const short vals5[10]={0x5f,0x50,0x3d,0x79,0x72,0x6f,0x6f,0x51,0x7f,0x73};
  
    //const short valMSB[10]={0xa0,0x00,0xc0,0x40,0x60,0x60,0xe0,0x00,0xe0,0x60};
    
  //const short valLSB[10]={0x0f,0x06,0x0b,0x0f,0x06,0x0d,0x0d,0x07,0x0f,0x07};
void setup() {

  register uint8_t i;
  
  ht.begin();
  Serial.begin(9600);
  ht.sendCommand(HT1621::RC256K);
  ht.sendCommand(HT1621::BIAS_THIRD_4_COM);
  ht.sendCommand(HT1621::SYS_EN);
  ht.sendCommand(HT1621::LCD_ON);

  ht.clearDisp();
  
  //avaliable to public:
  //uint8_t read(uint8_t address);
  
    //ht.inWrite( unsigned short segment, unsigned short number,char play, char pause);
  
  //ht.inWrite( unsigned short segment, unsigned short number);
  
  //ht.specialSeg(uint8_t binten,uint8_t binfiften);
  
  //ht.specialSeg(String s,char en);
  
  //ht.adWrite(unsigned short address, uint8_t value);
}

void loop() {
  
  //writing a number to segment/digit palce
  ht.adWrite(2,0xfa);
  delay(2000);
  
 
 number |= 1 << 0;//set nth bit 
  Serial.println(number,HEX);
// number &= ~(1<< 0);// rest nth bit 0-7,lsb-msb
 //Serial.println(number,HEX);
 ht.write(6,number);
   delay(2000);
  ht.clearDisp();

  //addWrite address write translates the address/segment byte to natural numbers
  //and can write the bytes direclty to manupilate all coms and segs
  // i/p byte segment-----hardware byte segment---contents to control---8-BIT
  //   1----5---WMA--------------------------------OB  1111 1111 / 0000 0000
  //   2----6---D7[FULL],||------------------------OB  0000 000PU
  //   3----7---D6[FULL],>-------------------------OB  0000 000PL
  //   4----8--- :,D5[FULL]------------------------OB D2000 0000
  //   5----9---D4[FULL],MP3-----------------------OB  0000 000MP
  //   6----10--LINE72^----------------------------OB  0000 0000
  //   7----11--ROCK,JAZZ,DIGITAL,CLASSIC,D3[dcba]-OB  OOOO 0000
  //   8----12--D3[EGF],CHAMP,D2[dcba]-------------OB  000C 0000
  //   9----13--D2[egf],TRACK,D1[dcba]-------------OB  000T 0000
  //   10---14--D1[egf],TITLE,ALB,SHUFF,PROG-------OB  000T OOOX
  //   11---15--ALL,REP, :,A,-B,DD,----------------OB  OOOX OOOX
 
}
