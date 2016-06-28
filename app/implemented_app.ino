/**
* Threading library
*/


/**
* Manager libraries
*/

#include <Accelerometer.h>
#include <DHTSensor.h>
#include <GPS.h>
#include "Time.h"

/**
* Writter library
*/

#include <SDWriter.h>

/**
* Variables declaration
*/

SDWriter writer("44");

Accelerometer accelerometer;
DHTSensor dht;
//GPS gps;

SLinearAcceleration linearAcceleration;
SAngularAcceleration angularAcceleration;
STemperature temperature;
SHumidity humidity;
SCoordinate coordinate;
String t;

/**
 * Setup Function
 * This function is used in order to initialize component for the arduino application
 */

void setup() 
{
  	writer.initialize();

  	accelerometer.init();

    setTime(10, 00, 00, 21, 6, 2016);
}

/**
 * Loop function
 * This module is used in order to process treatment over and over again
 */

void loop() 
{
	/* Sensors reading procedures */
	accelerometer.read(&linearAcceleration, &angularAcceleration);
	dht.read(&humidity, &temperature);
	//gps.read(&coordinate, &datetime);
	//light.read(&lightLevel);
  t.concat(F("2016"));
  t.concat(F("-"));
  t.concat(F("06"));
  t.concat(F("-"));
  t.concat(day());
  t.concat(F("T"));
  t.concat(hour());
  t.concat(F(":"));
  t.concat(minute());
  t.concat(F(":"));
  t.concat(second());
  t.concat(F("Z"));
	writer.pushToSD(writer.parseData(&angularAcceleration, &linearAcceleration, &humidity, &temperature, &coordinate, t));
  t = F("");
}
