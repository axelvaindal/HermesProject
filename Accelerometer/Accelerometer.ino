#include "Accelerometer.h"

/* Variables declaration */
Accelerometer accel;
SLinearAcceleration lA; 
SAngularAcceleration aA; 
SAngularPosition aP;

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
    accel.read(&lA, &aA, &aP);
  
    /* Displaying Linear Acceleration */
    Serial.print("Linear Acceleration x axis");
    Serial.print(" : ");
    Serial.println(lA.ax);
    Serial.print("Linear Acceleration y axis");
    Serial.print(" : ");
    Serial.println(lA.ay);
    Serial.print("Linear Acceleration z axis");
    Serial.print(" : ");
    Serial.println(lA.az);

    /* Displaying Angular Acceleration */
    Serial.print("Angular Acceleration x axis");
    Serial.print(" : ");
    Serial.println(aA.gx);
    Serial.print("Angular Acceleration y axis");
    Serial.print(" : ");
    Serial.println(aA.gy);
    Serial.print("Angular Acceleration z axis");
    Serial.print(" : ");
    Serial.println(aA.gz);

    /* Displaying Angular Position */
    Serial.print("Angular Position x/y axis");
    Serial.print(" : ");
    Serial.println(aP.alpha);
    Serial.print("Angular Position x/z axis");
    Serial.print(" : ");
    Serial.println(aP.beta);
    Serial.print("Angular Position y/z axis");
    Serial.print(" : ");
    Serial.println(aP.theta);

    delay(100);
}
