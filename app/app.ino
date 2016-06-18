/**
* Threading library
*/
#include <ChibiOS_AVR.h>

/**
* Manager libraries
*/

#include <AlertManager.h>
#include <BufferManager.h>
#include <RGBLed.h>

/**
* Writter library
*/

#include <SDWriter.h>

/**
* Thread Working Area Declaration
*/

static WORKING_AREA(waGPS, 1);
static WORKING_AREA(waDHTLight, 1);
static WORKING_AREA(waWriter, 1);
static WORKING_AREA(waAccelerometer, 1);

/**
* Variables declaration
*/

BufferManager* b;
AlertManager* a;

SDWriter writer("43", 10);

Accelerometer accelerometer;
DHTSensor dht;
//GPS gps;
LightSensor light;
RGBLed rgb;


SLinearAcceleration linearAcceleration;
SAngularAcceleration angularAcceleration;
SAngularPosition angularPosition;
STemperature temperature;
SHumidity humidity;
SLight lightLevel;
SCoordinate coordinate;
SDatetime clock;

/**
 * Setup Function
 * This function is used in order to initialize component for the arduino application
 */

void setup() 
{
	/**
	* Thread Library initialization
	*/
	cli();
 	halInit();
  	chSysInit();

  	b->setAlertManager(a);

  	writer.initialize();

  	accelerometer.init();
}

/**
 * Loop function
 * This module is used in order to process treatment over and over again
 */

void loop() 
{
	accelerometer.read(&linearAcceleration, &angularAcceleration, &angularPosition);

	
	//gps.read(&coordinate, &clock);
	/*dht.read(&temperature, &humidity);

	String b = "";
	b.concat("Temperature : ");
	b.concat(temperature)*/

	

	if (writer.isInitialized())
	{
		writer.addToJSONString("DateTime", "Titi");
		writer.pushToSD();
	}
	else
	{
		writer.raz();
	}
    
  	delay(100);
}
