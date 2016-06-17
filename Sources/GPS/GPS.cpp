#include "GPS.h"

/**
 *  Default constructor
 */
GPS::GPS() : ss(RX, TX)
{
	init();
}


/**
 * GPS::read
 * Write data in buffers
 * @return {bool}
 */
bool GPS::read()
{
	if(check())
	{

		if (tinyGps.location.isValid())
		{
            coordinate.latitude = tinyGps.location.lat();
            coordinate.longitude = tinyGps.location.lng();
		}
		else
		{
            coordinate.latitude = 0.0;
            coordinate.longitude = 0.0;
		}

		if (tinyGps.date.isValid() && tinyGps.time.isValid())
		{
			clock.datetime.concat(tinyGps.date.day());
			clock.datetime.concat("/");
			clock.datetime.concat(tinyGps.date.month());
			clock.datetime.concat("/");
			clock.datetime.concat(tinyGps.date.year());
			clock.datetime.concat(" ");
			clock.datetime.concat(tinyGps.time.hour());
		    clock.datetime.concat(":");
			clock.datetime.concat(tinyGps.time.minute());
		    clock.datetime.concat(":");
			clock.datetime.concat(tinyGps.time.second());
			
		}
		else
		{
			clock.datetime = "INVALID";
		}

        push(coordinate, clock);
		return true;
	}

	return false;
}

/**
 * GPS::init
 * Initialization method
 * @return {void}
 */
void GPS::init()
{
	ss.begin(9600);
	
}

/**
 * GPS::push
 * NOT IMPLEMENTED
 * Write data in buffers
 * @param {double[2]} position Contain lat and lng datas
 * @param {String} datetime Datetime data
 * @return {void}
 */
void GPS::push(SCoordinate coordinate, SDatetime datetime)
{
	Serial.print("latitude : ");
    Serial.println(coordinate.latitude);
	Serial.print("longitude : ");
    Serial.println(coordinate.longitude);
	Serial.print("date : ");
	Serial.println(clock.datetime);
	Serial.println("");
}

/**
 * GPS::check
 * Write data in buffers
 * @return {bool}
 */
bool GPS::check()
{
	if(ss.available() > 0 && tinyGps.encode(ss.read()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
