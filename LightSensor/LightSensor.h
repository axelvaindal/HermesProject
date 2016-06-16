#ifndef LIGHTSENSOR
#define LIGHTSENSOR

#include "Arduino.h"

/**
 * LightSensor
 * This class is used in order to manage the light sensor
 */
class LightSensor
{
	private :
		int lightLevel;
		int lightPin;

	public :
		/**
		* Default constructor
		*/
		LightSensor();
		
		/**
		* Overrided constructor
		* @param  {int} pin number
		*/
		LightSensor(int pin);
		
		/**
		* read method
		* This method get the light level from the light sensor and store the value in the lighLevel variable
		* @return {int}
		*/
		int read();
		
		/**
		* getLightLevel method
		* This method return the light level between 0 and 1023
		* @return {int}
		*/
		int getLightLevel();
};

#endif