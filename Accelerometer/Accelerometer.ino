#include "Accelerometer.h"

/* Accelerometer Object */
Accelerometer accel;

/* Setup function */
void setup() 
{
	/* Start serial link with 9600 bauds */
    Serial.begin(9600);
    Serial.println("Initializing I2C devices...");

    /* Initialize Accelerometer Object */
    accel.init();
}

/* Loop function */
void loop() 
{
	// Read the data from the sensor
	accel.read(result);
  
  	/* Displaying loop */
  	for (int i = 0; i < 24; i++)
  	{
    	Serial.print(i);
    	Serial.print(" : ");
    	Serial.println(result[i]);
    
    	if ((i+1) % 3 == 0)
    	{
      		Serial.println("---");
    	}
  	}

  	Serial.println("*****");

  	delay(100);
}
