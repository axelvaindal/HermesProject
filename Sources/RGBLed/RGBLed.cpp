#include "RGBLed.h"
/**
 * RGBLed
 * Default constructor, init class value and set com PIN to 8,9,10
 */

RGBLed :: RGBLed()
{
    redPin = 6;
    greenPin = 9;
    bluePin = 8;

}

/**
 * RGBLed
 * Overrided constructor, init set com PIN with param
 * @param _redPin
 * @param _greenPin
 * @param _bluePin
 */

RGBLed :: RGBLed(int _redPin,int _greenPin,int _bluePin)
{
    redPin = _redPin;
    greenPin = _greenPin;
    bluePin = _bluePin;
}

/**
 * lightOn
 * set color value green, blue, red
 * @param red
 * @param green
 * @param blue
 */
void RGBLed :: lightOn(int red,int green,int blue)
{
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}

/**
 * lightOff
 * switchOff RGB Led
 */
void RGBLed :: lightOff()
{
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}


