// oneMHz
// 
// Demonstrate use of the DDS Library
// m0xpd
// http://m0xpd.blogspot.com
// March 2014

// include the DDS Library:
#include <DDS.h>
//======================================
// AD9850 Module....
// set pin numbers:
const int W_CLK = 2;
const int FQ_UD = 3; 
const int DATA = 4;
const int RESET = 5;

double freq = 1000000;

  // Instantiate the DDS...
  DDS dds(W_CLK, FQ_UD, DATA, RESET);

void setup() {
  // start up the DDS...   
  dds.init();  
  // (Optional) trim if your xtal is not at 125MHz...
  dds.trim(125000000); // enter actual osc freq 
  // start the oscillator...
  dds.setFrequency(freq);  
}

void loop() {
}
