#include "GPS.h"

GPS::GPS(double* position)
{
	init();
	Position = position;

}

bool GPS::Read()
{

}


GPS::init()
{
	ss.begin(9600);
}