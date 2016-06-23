#ifndef LIGHTSENSOR
#define LIGHTSENSOR

#include "Arduino.h"

/**
* Structure representing the light level
*/
typedef struct SLight
{
	int lightLevel;
} SLight;


/**
 * LightSensor
 * This class is used in order to manage the light sensor
 */
class LightSensor
{
	private :
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
		void read(SLight* light);
};

#endif