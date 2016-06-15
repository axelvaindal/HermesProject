#ifndef GPS_H
#define GPS_H

#include "TinyGPS++.h"
#include "SoftwareSerial.h"

#define RX 11,
#define TX 10;


class GPS
{
	public:
		GPS(double[][3]& position, String[]& datetime);

		bool read();

	private:
		void init();
		void push(double[3] position, String datetime);
		bool check();



		TinyGPSPlus tinyGps;
		SoftwareSerial ss(RX, TX);

		double[][3] Position;
		String[] Datetime;
		
}

#endif // !GPS_H