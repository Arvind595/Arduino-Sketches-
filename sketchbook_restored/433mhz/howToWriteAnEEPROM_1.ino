/*
  SparkFun Electronics
  Date: June 11th, 2017

  Demonstrate how to read the entirety of an EEPROM and output it to a terminal.
  This sketch shows how to read the entire contents of a 24LC1025 I2C EEPROM.

  You'll need to use a terminal to capture the incoming contents to a text file. The
  Arduino terminal will not work. We recommend Teraterm: 
  https://learn.sparkfun.com/tutorials/terminal-basics
  
  Remember to send files to the terminal not using drag and drop as this will often try to
  send the file clear text. Use File->Send File and select the 'binary' option.
  
  Hardware Connections (IC to Arduino):
  -Pin 1(A0) = GND
  -Pin 2(A1) = GND
  -Pin 3(A2) = 3.3V or 5V
  -Pin 4(VSS) = GND
  -Pin 5(SDA) = SDA
  -Pin 6(SCL) = SCL
  -Pin 7(WP) = GND (No write protection)
  -Pin 8(VCC) = 3.3V or 5V

  Two pull up resistors are needed as well:
  -4.7K SDA = VCC
  -4.7K SCL = VCC

  EEPROMs general have thousands of bytes that will be stored even after power is disconnected.
  There are some EEPROMs that are large enough they require an extra address. The 24LC1025 is
  one example.
  
*/

#include <Wire.h>

//The 24LC1025 has a weird I2C address. The IC responds to two addresses in practice:
//0b.101.0000 (0x50) and 0b.101.0100 (0x54). There is a block select bit (bit 2) that
//allows us to read the full 17-bit address space
#define EEPROM_ADR_LOW_BLOCK 0x50 //0b.101.0000 0x50
#define EEPROM_ADR_HIGH_BLOCK 0x54 //0b.101.0100 0x54

#define MAX_I2C_WRITE 16 //32 fails for unknown reasons; only 30 bytes are written. 16 works.

byte tempStore[MAX_I2C_WRITE]; //128 bytes per EEPROM bulk write

void setup()
{
  Wire.begin();
  Wire.setClock(400000); //Let's go fast!

  Serial.begin(19200);

  long currentSpot = 0;
  long timerReset = 0;
  byte counter = 0;

  //Listen for bytes and increment as we go
  while (1)
  {
    while (Serial.available())
    {
      tempStore[counter++] = Serial.read(); //Read this byte into the array

      if (counter == MAX_I2C_WRITE)
      {
        writeEEPROMPage(currentSpot);
        counter = 0; //Reset
        currentSpot += MAX_I2C_WRITE;
      }

      timerReset = millis();
    }

    if (millis() - timerReset > 2000)
    {
      Serial.println(currentSpot);
      timerReset = millis();
    }
  }

}

void loop()
{

}

//The 24LC1025 is 1024kbit or 128k bytes.
//If the eeaddress is less than the 64k byte threshold we use I2C address 0x50
//If the address is above 65535 then we use 0x54 address
//Based on: https://playground.arduino.cc/Code/I2CEEPROM
void writeEEPROM(long eeAddress, byte data)
{
  if (eeAddress < 65536)
  {
    Wire.beginTransmission(EEPROM_ADR_LOW_BLOCK);
    eeAddress &= 0xFFFF; //Erase the first 16 bits of the long variable
  }
  else
  {
    Wire.beginTransmission(EEPROM_ADR_HIGH_BLOCK);
  }

  Wire.write((int)(eeAddress >> 8)); // MSB
  Wire.write((int)(eeAddress & 0xFF)); // LSB
  Wire.write(data);
  Wire.endTransmission();
}

byte readEEPROM(long eeaddress)
{
  if (eeaddress < 65536)
    Wire.beginTransmission(EEPROM_ADR_LOW_BLOCK);
  else
    Wire.beginTransmission(EEPROM_ADR_HIGH_BLOCK);

  Wire.write((int)(eeaddress >> 8)); // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();

  if (eeaddress < 65536)
    Wire.requestFrom(EEPROM_ADR_LOW_BLOCK, 1);
  else
    Wire.requestFrom(EEPROM_ADR_HIGH_BLOCK, 1);

  byte rdata = 0xFF;
  if (Wire.available()) rdata = Wire.read();
  return rdata;
}


//Given a global array, write 32 bytes to EEPROM
//EEPROM can handle single writes up to 128 bytes but Arduino's Wire buffer is only 32 bytes :(
//Function does not handle crossing block boundary, it's left to the user
void writeEEPROMPage(long eeAddress)
{
  if (eeAddress < 65536)
  {
    Wire.beginTransmission(EEPROM_ADR_LOW_BLOCK);
    eeAddress &= 0xFFFF; //Erase the first 16 bits of the long variable
  }
  else
  {
    Wire.beginTransmission(EEPROM_ADR_HIGH_BLOCK);
  }

  Wire.write((int)(eeAddress >> 8)); // MSB
  Wire.write((int)(eeAddress & 0xFF)); // LSB

  //Write bytes to EEPROM
  for (byte x = 0 ; x < MAX_I2C_WRITE ; x++)
    Wire.write(tempStore[x]); //Write the data

  Wire.endTransmission(); //Send stop condition
}

