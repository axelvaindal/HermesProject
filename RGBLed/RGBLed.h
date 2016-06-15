#ifndef RGBLED_H
#define RGBLED_H


#include "arduino.h"


/**
 *RGBLed class
 *This module is used for change RGB led color
 */




class RGBLed
{
private:

        int8_t redpin,greenpin,bluepin; // Arduino pin

        int8_t red,green,blue; //variable value

public:
	RGBLed();
	RGBLed(int _redpin,int _greenpin,int _bluepin);
	
        void lightOn(int red,int green,int blue);
        void lightOff();
};
#endif
