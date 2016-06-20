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
GPS gps;
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

  	Serial.begin(9600);
  	Serial.println("Debut de la liaison serie");

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
	/* Sensors reading procedures */
	accelerometer.read(&linearAcceleration, &angularAcceleration, &angularPosition);
	dht.read(&humidity, &temperature);
	gps.read(&coordinate, &clock);
	light.read(&lightLevel);

	String t = "Cooordonnees GPS: ";
	t.concat(coordinate.longitude);
	t.concat("/");
	t.concat(coordinate.latitude);
	t.concat("/");
	t.concat(clock.datetime);
	
	Serial.println(t);
	/* Writter writting procedure */
	/*if (writer.isInitialized())
	{
		writer.addToJSONString("DateTime", "Titi");
		writer.pushToSD();
	}
	else
	{
		writer.raz();
	}*/

	  rgb.lightOn(255,0,0);// color RED
	  delay(1000);
	  rgb.lightOn(180,70,0); //color YELLOW
	  delay(1000);
	  rgb.lightOn(0,150,0);//color GREEN
	  delay(1000);

}
