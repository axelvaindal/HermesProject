#ifndef GPS_H
#define GPS_H

#include "TinyGPS++.h"
#include "SoftwareSerial.h"

#define RX 11,
#define TX 10;


class GPS
{
	public:
		GPS(double* position);

		bool read();

	private:
		void init();


		TinyGPSPlus tinyGps;
		SoftwareSerial ss(RX, TX);

		double* Position;
}

#endif // !GPS_H