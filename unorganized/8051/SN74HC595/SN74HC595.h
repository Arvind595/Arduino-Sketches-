 /**
 * \SN74HC595.h
 * \date 25 april 2020
 * \version 1.0
 * \author=Aravind Anirudh
 */

#ifndef SN74HC595_H
#define SN74HC595_H

#if defined(__AVR__)
	#include "Arduino.h"
#endif

class SN74HC595{
	
	public: 
	
	SN74HC595(const uint8_t registers, const uint8_t serialDataPin,const uint8_t latchPin,const uint8_t clockPin);
	SN74HC595(const uint8_t registers, const uint8_t serialDataPin,const uint8_t latchPin,const uint8_t clockPin,const uint8_t outputEnablePin);	
	
	void disableOutput();
	void enableOutput();
	void brightness(uint8_t value);
	void setAllHigh();
	void setAllLow();
	void setPin(unsigned int pin, bool value);
	void set(unsigned int value);
	
	// special circutry needed : 74hc595 as SISO (as input)
	unsigned int getAll();
	bool getPin(unsigned int pin);
	
	//to read last latching of output
	unsigned int getAllM();//main function
	bool getPinM(unsigned int);
	
	private: 
	
	unsigned int modifyBit(unsigned int number,unsigned int position,bool value);
	void updateEEPROM(unsigned int value);
	void updateRegister(unsigned int value);
	void pluse();
	uint8_t _registers;
	uint8_t _serialDataPin;
	uint8_t _latchPin;
	uint8_t _clockPin;
	uint8_t _outputEnablePin;
	unsigned int _binary=0;

};

#endif