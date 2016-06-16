#include "GPS.h"

GPS::GPS(double[][3]* position, String[]* datetime)
{
	init();
	Position = position;
	Datetime = datetime;
}

bool GPS::Read()
{
	if(check())
	{
		double[3] position;
		if (tinyGps.location.isValid() && tinyGps.altitude.isValid())
		{
			positon = { tinyGps.location.lat(), 
						tinyGps.location.lng(), 
						tinyGps.altitude.meters()  };
		}

		String datetime;
		if (tinyGps.date.isValid() && tinyGps.time.isValid())
		{
			datetime =  tinyGps.date.day() +
						'/' +
						tinyGps.date.month() +
						'/' +
						tinyGps.date.year() +
						' ' +
						tinyGps.time.hour() +
						':' +
						tinyGps.time.minute() +
						':' +
						tinyGps.time.second() +
						':' +
						tinyGps.time.centisecond()
		}

		push(position, datetime);
	}
}

GPS::init()
{
	ss.begin(9600);
	
}

GPS::push(double[3] position, String datetime)
{
	
}

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