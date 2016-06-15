#include "RGBLed.h"
/**
 * RGBLed
 * Default constructor, init class value and set com PIN to 8,9,10
 */

RGBLed :: RGBLed()
{
    redpin = 10;
    greenpin = 9;
    bluepin = 8;

}
/**
 * RGBLed
 * Overrided constructor, init set com PIN with param
 * @param _redpin
 * @param _greenpin
 * @param _bluepin
 */
RGBLed :: RGBLed(int _redpin,int _greenpin,int _bluepin)
{
    redpin = _redpin;
    greenpin = _greenpin;
    bluepin = _bluepin;


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
    analogWrite(redpin, red);
    analogWrite(greenpin, green);
    analogWrite(bluepin, blue);
}
/**
 * lightOff
 * switchOff RGB Led
 */
void RGBLed :: lightOff()
{
    analogWrite(redpin, 0);
    analogWrite(greenpin, 0);
    analogWrite(bluepin, 0);
}


