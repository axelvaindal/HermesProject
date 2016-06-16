#include "Accelerometer.h"

/**
* Default constructor
*/
Accelerometer::Accelerometer()
{
	deltaTime = 100;
	lastExecution = 0;
	alpha = 0;
	beta = 0;
	theta = 0;
}

/**
* Overrided constructor
* @param {int} deltaTime 
*/
Accelerometer::Accelerometer(int dt)
{
	deltaTime = dt;
	lastExecution = 0;
	alpha = 0;
	beta = 0;
	theta = 0;
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
 * Initialization method in order to set sensibility and tare
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::read(double* result)
{
	update();
	 
	double temp[3] = {1.0, 1.0, 1.0};
	 
	 
	getLinearAccelerationG(temp);
	 
	result[0] = temp[0];
	result[1] = temp[1];
	result[2] = temp[2];
	 
	getLinearAccelerationGWithoutGravity(temp);
	 
	result[3] = temp[0];
	result[4] = temp[1];
	result[5] = temp[2];
	 
	getLinearAccelerationMPS(temp);
	 
	result[6] = temp[0];
	result[7] = temp[1];
	result[8] = temp[2];
	 
	getLinearAccelerationMPSWithoutGravity(temp);
	 
	result[9]  = temp[0];
	result[10] = temp[1];
	result[11] = temp[2];
	 
	 
	getAngularAccelerationDPS(temp);
	 
	result[12] = temp[0];
	result[13] = temp[1];
	result[14] = temp[2];
	 
	getAngularAccelerationRPS(temp);
	 
	result[15] = temp[0];
	result[16] = temp[1];
	result[17] = temp[2];
	 
	getAngularPositionD(temp);
	 
	result[18] = temp[0];
	result[19] = temp[1];
	result[20] = temp[2];
	 
	getAngularPositionR(temp);
	 
	result[21] = temp[0];
	result[22] = temp[1];
	result[23] = temp[2];
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
		chipset.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
	}
}

/**
 * Accelerometer::getLinearAccelerationG
 * This method returns the absolute acceleration of the sensor in g
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationG(double* result)
{
	result[0] = (double) (ax) / LSB_TO_G_2;
	result[1] = (double) (ay) / LSB_TO_G_2;
	result[2] = (double) (az) / LSB_TO_G_2;
}

/**
 * Accelerometer::getLinearAccelerationGWithoutGravity
 * This method returns the absolute acceleration of the sensor in g without gravity effect
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationGWithoutGravity(double* result)
{
	double angularPosition[3], linearAcceleration[3];
	
	removeGravityEffect(result);
}

/**
 * Accelerometer::getLinearAccelerationMPS
 * This method returns the absolute acceleration of the sensor in m/s²
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationMPS(double* result)
{
	getLinearAccelerationG(result);

	result[0] *= GRAVITY_CONSTANT;
	result[1] *= GRAVITY_CONSTANT;
	result[2] *= GRAVITY_CONSTANT;

}

/**
 * Accelerometer::getLinearAccelerationMPSWithoutGravity
 * This method returns the absolute acceleration of the sensor in m/s² without gravity effect
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getLinearAccelerationMPSWithoutGravity(double* result)
{
	getLinearAccelerationGWithoutGravity(result);

	result[0] *= GRAVITY_CONSTANT;
	result[1] *= GRAVITY_CONSTANT;
	result[2] *= GRAVITY_CONSTANT;

}

/**
 * Accelerometer::getAngularAccelerationDPS
 * This method returns the absolute angular speed of the sensor in degree/s 
 * @param {double*} result The result array where to put the data
 * @return {void} 
 */
void Accelerometer::getAngularAccelerationDPS(double* result)
{
	result[0] = (double) (gx) / LSB_TO_DPS_250;
	result[1] = (double) (gy) / LSB_TO_DPS_250;
	result[2] = (double) (gz) / LSB_TO_DPS_250;
}

/**
 * Accelerometer::getAngularAccelerationRPS
 * This method returns the absolute angular speed of the sensor in rad/s
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getAngularAccelerationRPS(double* result)
{
	getAngularAccelerationDPS(result);

	result[0] = (double) (result[0] * PI / 180);
	result[1] = (double) (result[1] * PI / 180);
	result[2] = (double) (result[2] * PI / 180);

}

/**
 * Accelerometer::getAngularPositionD
 * This method returns the absolute angular position of the sensor in degree
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getAngularPositionD(double* result)
{
	double acceleration[3];
	getAngularAccelerationDPS(acceleration);

	alpha 	+= (double) (acceleration[0] * deltaTime / 1000);
	beta 	+= (double) (acceleration[1] * deltaTime / 1000);
	theta 	+= (double) (acceleration[2] * deltaTime / 1000);

	result[0] = alpha;
	result[1] = beta;
	result[2] = theta;
}

/**
 * Accelerometer::getAngularPositionR
 * This method returns the absolute angular position of the sensor in rad
 * @param {double*} result The result array where to put the data 
 * @return {void}
 */
void Accelerometer::getAngularPositionR(double* result)
{
	getAngularPositionD(result);

	result[0] = (double) (alpha * PI / 180);
	result[1] = (double) (beta * PI / 180);
	result[2] = (double) (theta * PI / 180);

}

/**
 * Accelerometer::removeGravityEffect
 * This method returns the corrected acceleration (without gravity effect)
 * @param {double*} result The result array where to put the data
 * @return {void} 
 */
void Accelerometer::removeGravityEffect(double* result)
{
	double rotatedGravity[3];
	double rotatedAccel[3];
	double motionAccel[3];

	double angularPosition[3];
	double linearAcceleration[3];
	
	double gravity[3] = {0.0, 0.0, 1.0};

	
	getAngularPositionR(angularPosition);
	getLinearAccelerationG(linearAcceleration);
	
	double alphaRad = angularPosition[0];
	double betaRad = angularPosition[1];
	double thetaRad = angularPosition[2];

  	// Rotation matrix
	float R[3][3] =
  	{
    	{ cos(alphaRad) * cos(betaRad) , cos(alphaRad) * sin(betaRad) * sin(thetaRad) - sin(alphaRad) * cos(thetaRad) , cos(alphaRad) * sin(betaRad) * cos(thetaRad) + sin(alphaRad) * sin(thetaRad) },
    	{ sin(alphaRad) * cos(betaRad) , sin(alphaRad) * sin(betaRad) * sin(thetaRad) + cos(alphaRad) * cos(thetaRad) , sin(alphaRad) * sin(betaRad) * cos(thetaRad) - cos(alphaRad) * sin(thetaRad) },
    	{     -1 * sin(betaRad)       ,                  cos(betaRad) * sin(thetaRad)                          ,               cos(betaRad) * cos(thetaRad)                   }
  	};


  	// Apply rotation matrix on gravity vector
	rotatedGravity[0] = gravity[0] * R[0][0] + gravity[1] * R[0][1] + gravity[2] * R[0][2] ;
 	rotatedGravity[1] = gravity[0] * R[1][0] + gravity[1] * R[1][1] + gravity[2] * R[1][2] ;
  	rotatedGravity[2] = gravity[0] * R[2][0] + gravity[1] * R[2][1] + gravity[2] * R[2][2] ;

  
  	// Apply rotation matrix on accelerometer datas
  	rotatedAccel[0] = linearAcceleration[0] * R[0][0] + linearAcceleration[1] * R[0][1] + linearAcceleration[2] * R[0][2] ;
  	rotatedAccel[1] = linearAcceleration[0] * R[1][0] + linearAcceleration[1] * R[1][1] + linearAcceleration[2] * R[1][2] ;
  	rotatedAccel[2] = linearAcceleration[0] * R[2][0] + linearAcceleration[1] * R[2][1] + linearAcceleration[2] * R[2][2] ;


  	// Determinate motion acceleration according to previous values (remove gravity effect on rotated acceleration vector)
  	motionAccel[0] = rotatedAccel[0] - rotatedGravity[0];
  	motionAccel[1] = rotatedAccel[1] - rotatedGravity[1];
  	motionAccel[2] = rotatedAccel[2] - rotatedGravity[2];


  	// Restore corrected acceleration vector into his first orientation
  	result[0] = (double) (motionAccel[0] * R[0][0] + motionAccel[1] * R[1][0] + motionAccel[2] * R[2][0]);
  	result[1] = (double) (motionAccel[0] * R[0][1] + motionAccel[1] * R[1][1] + motionAccel[2] * R[2][1]);
  	result[2] = (double) (motionAccel[0] * R[0][2] + motionAccel[1] * R[1][2] + motionAccel[2] * R[2][2]);
}
