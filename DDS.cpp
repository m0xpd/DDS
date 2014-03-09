/*
  DDS.cpp - Library for hosting an AD9850 DDS Module
  on the Arduino under software SPI.
  Created by m0xpd, March 2014.
  Released into the public domain.
*/

#include "Arduino.h"
#include "DDS.h"



DDS::DDS(int W_CLK, int FQ_UD, int DATA, int RESET)
{
	_W_CLK = W_CLK;
	_FQ_UD = FQ_UD;
	_DATA = DATA;
	_RESET = RESET;
	_TrimFreq = 125000000;
}

void DDS::setFrequency(double frequency)
{
  int32_t freq = frequency * 4294967295/_TrimFreq;
  for (int b=0; b<4; b++, freq>>=8) {
    shiftOut(_DATA, _W_CLK, LSBFIRST, freq & 0xFF);
  } 
  shiftOut(_DATA, _W_CLK, LSBFIRST, 0x00);  
  pulseHigh(_FQ_UD); 
}

void DDS::init()
{
	init_priv();
}

void DDS::init_priv()
{
  	pinMode(_FQ_UD, OUTPUT);
  	pinMode(_W_CLK, OUTPUT);
  	pinMode(_DATA, OUTPUT);
  	pinMode(_RESET, OUTPUT);

  	pulseHigh(_RESET);
  	pulseHigh(_W_CLK);
  	pulseHigh(_FQ_UD);  
        setFrequency(0); 
}

void DDS::trim(double TrimFreq)
{
	_TrimFreq=TrimFreq;
}

// Subroutine to generate a positive pulse on 'pin'...
void DDS::pulseHigh(int _pin) 
{
digitalWrite(_pin, HIGH);
digitalWrite(_pin, LOW); 
}
