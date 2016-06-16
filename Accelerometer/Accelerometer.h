#ifndef ACCELEROMETER_H
#define ACCELEROMETER_H

#include "Arduino.h"
#include "I2Cdev.h"
#include "MPU6050.h"


#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


#define LSB_TO_G_2 	16384.0
#define LSB_TO_G_4 	8192.0
#define LSB_TO_G_8 	4096.0
#define LSB_TO_G_16 2048.0

#define LSB_TO_DPS_250	131.0
#define LSB_TO_DPS_500	65.5
#define LSB_TO_DPS_1000	32.8
#define LSB_TO_DPS_2000	16.4

#define GRAVITY_CONSTANT 9.80665

/**
 * Accelerometer Class
 * This module is used in order to manage an MPU6050 sensor with Arduino
 */
class Accelerometer
{
	public:

		/**
		* Default constructor
		*/
		Accelerometer();

		/**
		* Overrided constructor
		* @param  {int} deltaTime 
		*/
		Accelerometer(int deltaTime);

		/**
		* Getters and Setters
		*/
		void setDeltaTime(int dt);
		int getDeltaTime();

		/**
		* Public Methods
		*/
		void read(double* result);
		void update();
		void init();

		void getLinearAccelerationG(double* result);
		void getLinearAccelerationGWithoutGravity(double* result);
		void getLinearAccelerationMPS(double* result);
		void getLinearAccelerationMPSWithoutGravity(double* result);
		void getAngularAccelerationDPS(double* result);
		void getAngularAccelerationRPS(double* result);
		void getAngularPositionD(double* result);
		void getAngularPositionR(double* result);		

	private:

		/**
		* Private Methods
		*/
		void removeGravityEffect(double* result);

		/**
		* Private Attributes
		*/
	
		MPU6050 chipset;

		int deltaTime;
		unsigned long lastExecution;
		double alpha, beta, theta;

		int16_t ax, ay, az; 
		int16_t gx, gy, gz;
		int16_t gx0, gy0, gz0;
};

#endif
