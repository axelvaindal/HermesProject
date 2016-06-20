#ifndef GPS_H
#define GPS_H

#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "Arduino.h"

#define RX 6
#define TX 5


typedef struct SCoordinate
{
    double longitude;
    double latitude;
} Scoordinate;

typedef struct SDatetime
{
    String Datetime;
} SDatetime;

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
        void push(SCoordinate coordinate, SDatetime datetime);
		bool check();

		/**
		 * Private attributes
		 */
		TinyGPSPlus tinyGps;
		SoftwareSerial ss;
        SCoordinate coordinate;
        SDatetime datetime;

		
};

#endif // !GPS_H
