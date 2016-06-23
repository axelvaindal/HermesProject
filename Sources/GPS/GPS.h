#ifndef GPS_H
#define GPS_H

#include "TinyGPS++.h"
#include "SoftwareSerial.h"
#include "Arduino.h"

#define RX 7
#define TX 5


typedef struct SCoordinate
{
    double longitude;
    double latitude;
} Scoordinate;

typedef struct SDatetime
{
    String datetime;
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
		bool read(SCoordinate* c, SDatetime* clk);

	private:
		/**
		 * Private Methods
		 */

		void init();
		bool check();

		/**
		 * Private attributes
		 */
		TinyGPSPlus tinyGps;
		SoftwareSerial ss;
};

#endif // !GPS_H
