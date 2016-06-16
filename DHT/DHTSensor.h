#ifndef DHTSENSOR_H
#define DHTSENSOR_H

#include "Arduino.h"

typedef struct SHumidity
{
	int8_t humidity;
} SHumidity;

typedef struct STemperature
{
	int8_t temperature;
} STemperature;

/**
 * DHTSensor class
 * This module is used in order to manage an DHT11 sensor with arduino
 */
class DHTSensor
{
	private:
		int8_t pin;
		SHumidity humidity;
		STemperature temperature;
	public:
        DHTSensor();
        DHTSensor(int _pin);
		bool read();
		int8_t getTemperature();
		int8_t getHumidity();
};

#endif
