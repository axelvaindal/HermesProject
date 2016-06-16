#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include "Arduino.h"

/**
 * DHTSensor class
 * This module is used in order to manage an DHT11 sensor with arduino
 */
class DHTSensor
{
	private:
		int8_t pin, temperature, humidity; //Variable value
	public:
        DHTSensor();
        DHTSensor(int _pin);
		bool readDHT();
		int8_t getTemperature();
		int8_t getHumidity();
};

#endif
