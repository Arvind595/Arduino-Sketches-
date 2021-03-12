/**
 * \SN74HC595.cpp
 * \date 25 april 2020
 * \version 1.0
 * \author=Aravind Anirudh
 */
 
#include "SN74HC595.h"
#include <SPI.h>

SN74HC595::SN74HC595(const uint8_t registers, const uint8_t serialDataPin,const uint8_t latchPin,const uint8_t clockPin){
	_registers = registers;
	_serialDataPin = serialDataPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
	
	pinMode(_serialDataPin,OUTPUT);
	pinMode(_latchPin,OUTPUT);
	pinMode(_clockPin,OUTPUT);
	
	digitalWrite(_latchPin,LOW);
	digitalWrite(_clockPin,LOW);

}

SN74HC595::SN74HC595(const uint8_t registers, const uint8_t serialDataPin,const uint8_t latchPin,const uint8_t clockPin,const uint8_t outputEnablePin){
	_registers = registers;
	_serialDataPin = serialDataPin;
	_latchPin = latchPin;
	_clockPin = clockPin;
	_outputEnablePin = outputEnablePin;
	
	pinMode(_serialDataPin,OUTPUT);
	pinMode(_latchPin,OUTPUT);
	pinMode(_clockPin,OUTPUT);
	pinMode(_outputEnablePin,OUTPUT);
	
	digitalWrite(_latchPin,LOW);
	digitalWrite(_clockPin,LOW);
	digitalWrite(_outputEnablePin,LOW);	
}

void SN74HC595::disableOutput(){
	digitalWrite( _outputEnablePin,HIGH);
}

void SN74HC595::enableOutput(){
	digitalWrite( _outputEnablePin,LOW);
}

void SN74HC595::brightness(uint8_t value){
	analogWrite( _outputEnablePin,255-value);
}

unsigned int SN74HC595::modifyBit(unsigned int number,unsigned int position,bool value){
    unsigned int mask = 1 << position; 
    return (number & ~mask) | ((value << position) & mask); 
	// whole numbers 0 is position of lsb
}

void SN74HC595::updateRegister(unsigned int value){
	 _binary = value;
	digitalWrite( _latchPin,LOW);
	shiftOut( _serialDataPin, _clockPin,LSBFIRST,value);
	digitalWrite( _latchPin,HIGH);
	 for (uint8_t i=0; i<(_registers-1);i++){
	digitalWrite( _latchPin,LOW);
	shiftOut( _serialDataPin, _clockPin,LSBFIRST,value>>8);
	digitalWrite( _latchPin,HIGH);
}
}

void SN74HC595::set(unsigned int value){
	updateRegister(value);
}

void SN74HC595::setAllHigh(){
	updateRegister((unsigned int)(pow(2,(_registers*8))));
}

void SN74HC595::setAllLow(){
	updateRegister(0);
}

void SN74HC595::setPin(unsigned int  pin ,bool value){
	updateRegister(modifyBit( _binary,pin,value));
}
unsigned int SN74HC595::getAllM(){
	return _binary;
}
bool SN74HC595::getPinM(unsigned int pin){
	return ((_binary>>pin)&1);
}
