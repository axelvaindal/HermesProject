#ifndef GPS_H
#define GPS_H

#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "Arduino.h"

#define RX 6
#define TX 5

/**
 * GPS Class
 * This module is used in order to manage an Ublox NEO-6M sensor with arduino
 */
class GPS
{
	public:
		/**
		 * Default constructor 
		 */
		GPS();

		/**
		 * Public Methods
		 */
		bool read();

	private:
		/**
		 * Private Methods
		 */
		void init();
		void push(double position[2], String datetime);
		bool check();

		/**
		 * Private attributes
		 */
		TinyGPSPlus tinyGps;
		SoftwareSerial ss;

		double Position[10][2];
		String Datetime[10];
		
};

#endif // !GPS_H