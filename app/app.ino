/**
* Threading library
*/
#include <ChibiOS_AVR.h>

/**
* Sensor and state device libraries
*/

#include "Accelerometer.h"
#include "DHTSensor.h"
#include "GPS.h"
#include "LightSensor.h"
#include "RGBLed.h"

/**
* Manager libraries
*/

#include "AlertManager.h"
#include "BufferManager.h"

/**
* Writter library
*/

#include "SDWriter.h"

/**
* Thread Working Area Declaration
*/

/*static WORKING_AREA(waGPS, 1);
static WORKING_AREA(waDHTLight, 1);
static WORKING_AREA(waWritter, 1);
static WORKING_AREA(waAccelerometer, 1);*/

/**
* Variables declaration
*/

BufferManager* b;
AlertManager* a;

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
}

/**
 * Loop function
 * This module is used in order to process treatment over and over again
 */

void loop() 
{

}
