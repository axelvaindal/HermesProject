#include "Accelerometer.h"

/**
* Default constructor
*/
Accelerometer::Accelerometer()
{
	deltaTime = 100;
	lastExecution = 0;
	angularPosition.alpha = 0;
	angularPosition.beta = 0;
	angularPosition.theta = 0;
}

/**
* Overrided constructor
* @param {int} deltaTime 
*/
Accelerometer::Accelerometer(int dt)
{
	deltaTime = dt;
	lastExecution = 0;
	angularPosition.alpha = 0;
	angularPosition.beta = 0;
	angularPosition.theta = 0;
}


/**
 * Accelerometer::setDeltaTime
 * Setter for deltaTime attribute
 * @param {int} dt The new deltaTime to be used
 */
void Accelerometer::setDeltaTime(int dt)
{
	if (dt > 0)
	{
		deltaTime = dt;
	}
}

/**
 * Accelerometer::getDeltaTime
 * Getter for deltaTime attribute
 * @return {int}
 */
int Accelerometer::getDeltaTime()
{
	return deltaTime;
}


/**
 * Accelerometer::init
 * Initialization method in order to set sensibility and tare
 * @return {void}
 */
void Accelerometer::init()
{
	#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
	
	// Set accelerometer sensibility to 2g and gyroscope sensibility to 250°/s
	chipset.initialize();
	chipset.getRotation(&gx0, &gy0, &gz0);
}

/**
 * Accelerometer::read
 * Reading method in order to retrieve the data
 * @param {SLinearAcceleration*} lA The result structure where to put the linear acceleration data
 * @param {SAngularAcceleration*} aA The result structure where to put the angular acceleration data 
 * @param {SAngularPosition*} aP The result structure where to put the angular position data  
 * @return {void}
 */
void Accelerometer::read(SLinearAcceleration* lA, SAngularAcceleration* aA, SAngularPosition* aP)
{
	update();
	
	/* Linear Acceleration */
	getLinearAccelerationMPS(lA);
	 
	/* Angular Acceleration */
	getAngularAccelerationDPS(aA);
	 
	/* Angular Position */
	getAngularPositionD(aP);
}

/**
 * Accelerometer::update
 * Update method in order to set the new value of the attribute from the sensor
 * @return {void}
 */
void Accelerometer::update()
{
	if (millis() - lastExecution >= deltaTime)
	{
		chipset.getMotion6(&(rawData.ax), &(rawData.ay), &(rawData.az), &(rawData.gx), &(rawData.gy), &(rawData.gz));
	}
}

/**
 * Accelerometer::getLinearAccelerationG
 * This method returns the absolute acceleration of the sensor in g
 * @param {SLinearAcceleration*} result The result structure where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationG(SLinearAcceleration* result)
{
	result->ax = (double) (rawData.ax) / LSB_TO_G_2;
	result->ay = (double) (rawData.ay) / LSB_TO_G_2;
	result->az = (double) (rawData.az) / LSB_TO_G_2;
}

/**
 * Accelerometer::getLinearAccelerationGWithoutGravity
 * This method returns the absolute acceleration of the sensor in g without gravity effect
 * @param {SLinearAcceleration*} result The result structure where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationGWithoutGravity(SLinearAcceleration* result)
{
	removeGravityEffect(result);
}

/**
 * Accelerometer::getLinearAccelerationMPS
 * This method returns the absolute acceleration of the sensor in m/s²
 * @param {SLinearAcceleration*} result The result structure where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationMPS(SLinearAcceleration* result)
{
	getLinearAccelerationG(result);

	result->ax *= GRAVITY_CONSTANT;
	result->ay *= GRAVITY_CONSTANT;
	result->az *= GRAVITY_CONSTANT;

}

/**
 * Accelerometer::getLinearAccelerationMPSWithoutGravity
 * This method returns the absolute acceleration of the sensor in m/s² without gravity effect
 * @param {SLinearAcceleration*} result The result structure where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationMPSWithoutGravity(SLinearAcceleration* result)
{
	getLinearAccelerationGWithoutGravity(result);

	result->ax *= GRAVITY_CONSTANT;
	result->ay *= GRAVITY_CONSTANT;
	result->az *= GRAVITY_CONSTANT;
}

/**
 * Accelerometer::getAngularAccelerationDPS
 * This method returns the absolute angular speed of the sensor in degree/s 
 * @param {SAngularAcceleration*} result The result structure where to put the data 
 * @return {void} 
 */
void Accelerometer::getAngularAccelerationDPS(SAngularAcceleration* result)
{
	result->gx = (double) (rawData.gx) / LSB_TO_DPS_250;
	result->gy = (double) (rawData.gy) / LSB_TO_DPS_250;
	result->gz = (double) (rawData.gz) / LSB_TO_DPS_250;
}

/**
 * Accelerometer::getAngularAccelerationRPS
 * This method returns the absolute angular speed of the sensor in rad/s
 * @param {SAngularAcceleration*} result The result structure where to put the data
 * @return {void}
 */
void Accelerometer::getAngularAccelerationRPS(SAngularAcceleration* result)
{
	getAngularAccelerationDPS(result);

	result->gx = (double) (result->gx * PI / 180);
	result->gy = (double) (result->gy * PI / 180);
	result->gz = (double) (result->gz * PI / 180);

}

/**
 * Accelerometer::getAngularPositionD
 * This method returns the absolute angular position of the sensor in degree
 * @param {SAngularPosition*} result The result structure where to put the data
 * @return {void}
 */
void Accelerometer::getAngularPositionD(SAngularPosition* result)
{
	SAngularAcceleration a;
	getAngularAccelerationDPS(&a);

	angularPosition.alpha 	+= (double) (a.gx * deltaTime / 1000);
	angularPosition.beta 	+= (double) (a.gy * deltaTime / 1000);
	angularPosition.theta 	+= (double) (a.gz * deltaTime / 1000);

	result->alpha = angularPosition.alpha;
	result->beta = angularPosition.beta;
	result->theta = angularPosition.theta;
}

/**
 * Accelerometer::getAngularPositionR
 * This method returns the absolute angular position of the sensor in rad
 * @param {SAngularPosition*} result The result structure where to put the data 
 * @return {void}
 */
void Accelerometer::getAngularPositionR(SAngularPosition* result)
{
	getAngularPositionD(result);

	result->alpha = (double) (result->alpha * PI / 180);
	result->beta = (double) (result->beta * PI / 180);
	result->theta = (double) (result->theta * PI / 180);

}

/**
 * Accelerometer::removeGravityEffect
 * This method returns the corrected acceleration (without gravity effect)
 * @param {SLinearAcceleration*} result The result structure where to put the data
 * @return {void} 
 */
void Accelerometer::removeGravityEffect(SLinearAcceleration* result)
{
	/* Calculation variables */
	double motionAccel[3];
	double rotatedAccel[3];
	double rotatedGravity[3];
	
	double gravity[3] = {0.0, 0.0, 1.0};

	
	/* Get angular position and linear acceleration */
	SAngularPosition aP;
	SLinearAcceleration lA;
	
	getAngularPositionR(&aP);
	getLinearAccelerationG(&lA);
	

  	// Calculation of rotation matrix
	float R[3][3] =
  	{
    	{ cos(aP.alpha) * cos(aP.beta) , cos(aP.alpha) * sin(aP.beta) * sin(aP.theta) - sin(aP.alpha) * cos(aP.theta) , cos(aP.alpha) * sin(aP.beta) * cos(aP.theta) + sin(aP.alpha) * sin(aP.theta) },
    	{ sin(aP.alpha) * cos(aP.beta) , sin(aP.alpha) * sin(aP.beta) * sin(aP.theta) + cos(aP.alpha) * cos(aP.theta) , sin(aP.alpha) * sin(aP.beta) * cos(aP.theta) - cos(aP.alpha) * sin(aP.theta) },
    	{     -1 * sin(aP.beta)       ,                  cos(aP.beta) * sin(aP.theta)                          ,               cos(aP.beta) * cos(aP.theta)                   }
  	};


  	// Apply rotation matrix on gravity vector
	rotatedGravity[0] = gravity[0] * R[0][0] + gravity[1] * R[0][1] + gravity[2] * R[0][2] ;
 	rotatedGravity[1] = gravity[0] * R[1][0] + gravity[1] * R[1][1] + gravity[2] * R[1][2] ;
  	rotatedGravity[2] = gravity[0] * R[2][0] + gravity[1] * R[2][1] + gravity[2] * R[2][2] ;

  
  	// Apply rotation matrix on accelerometer datas
  	rotatedAccel[0] = lA.ax * R[0][0] + lA.ay * R[0][1] + lA.az * R[0][2] ;
  	rotatedAccel[1] = lA.ax * R[1][0] + lA.ay * R[1][1] + lA.az * R[1][2] ;
  	rotatedAccel[2] = lA.ax * R[2][0] + lA.ay * R[2][1] + lA.az * R[2][2] ;


  	// Determinate motion acceleration according to previous values (remove gravity effect on rotated acceleration vector)
  	motionAccel[0] = rotatedAccel[0] - rotatedGravity[0];
  	motionAccel[1] = rotatedAccel[1] - rotatedGravity[1];
  	motionAccel[2] = rotatedAccel[2] - rotatedGravity[2];


  	// Restore corrected acceleration vector into his first orientation
  	result->ax = (double) (motionAccel[0] * R[0][0] + motionAccel[1] * R[1][0] + motionAccel[2] * R[2][0]);
  	result->ay = (double) (motionAccel[0] * R[0][1] + motionAccel[1] * R[1][1] + motionAccel[2] * R[2][1]);
  	result->az = (double) (motionAccel[0] * R[0][2] + motionAccel[1] * R[1][2] + motionAccel[2] * R[2][2]);
}
