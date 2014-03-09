/*
  DDS.h - Library for hosting an AD9850 DDS Module
  on the Arduino under software SPI.
  Created by m0xpd, March 2014.
  Released into the public domain.
*/
#ifndef DDS_h
#define DDS_h

#include "Arduino.h"

class DDS
{
	public:
	DDS(int W_CLK, int FQ_UD, int DATA, int RESET);
	void setFrequency(double frequency);
	void init();
	void trim(double TrimFreq);
	private:
	void pulseHigh(int _pin);
	int _W_CLK;
	int _DATA;
	int _FQ_UD;
	int _RESET;
	double _TrimFreq;
	void init_priv();
};

#endif
