#include "LightSensor.h"

/**
* Default constructor
*/
LightSensor::LightSensor()
{
	lightPin = 0;
}

/**
* Overrided constructor
* @param  {int} pin number
*/
LightSensor::LightSensor(int pin)
{
	lightPin = pin;
}

/**
* read method
* This method get the light level from the light sensor and store the value in the lighLevel variable
* @return {SLight}
*/
void LightSensor::read()
{
	light.lightLevel = analogRead(lightPin);
}

/**
* getLightLevel method
* This method return the light level between 0 and 1023
* @return {SLight}
*/
SLight LightSensor::getLight()
{
	return light;
}