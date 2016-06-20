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
bool GPS::read(SCoordinate* c, SDatetime* clk)
{
	if (check())
	{
		if (true)
		{
            //c->latitude = tinyGps.location.lat();
            //c->longitude = tinyGps.location.lng();
            c->latitude = 1.8;
            c->longitude = 1.4;
		}
		else
		{
            c->latitude = 0.0;
            c->longitude = 0.0;
		}

		if (tinyGps.date.isValid() && tinyGps.time.isValid())
		{
			clk->datetime.concat(tinyGps.date.day());
			clk->datetime.concat("/");
			clk->datetime.concat(tinyGps.date.month());
			clk->datetime.concat("/");
			clk->datetime.concat(tinyGps.date.year());
			clk->datetime.concat(" ");
			clk->datetime.concat(tinyGps.time.hour());
		    clk->datetime.concat(":");
			clk->datetime.concat(tinyGps.time.minute());
		    clk->datetime.concat(":");
			clk->datetime.concat(tinyGps.time.second());	
		}
		else
		{
			clk->datetime = "INVALID";
		}

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
