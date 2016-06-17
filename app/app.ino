/**
* Threading library
*/
#include <ChibiOS_AVR.h>

/**
* Manager libraries
*/

#include <AlertManager.h>
#include <BufferManager.h>

/**
* Writter library
*/

#include <SDWriter.h>

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

SDWriter writer("43", 10);

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
}

/**
 * Loop function
 * This module is used in order to process treatment over and over again
 */

void loop() 
{
	if (writer.isInitialized())
	{
		writer.addToJSONString("titi", "toto");
		writer.pushToSD();
	}
	else
	{
		writer.raz();
	}
    
  	delay(100);
}
