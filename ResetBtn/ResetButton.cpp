#include "ResetButton.h"


/**
 * ResetButton
 * Default constructor, init class value and set com pin to 3
 */
ResetButton::ResetButton(SDWritter* p)
{
	writter = p;
	interruptPin = 3;
}

/**
 * ResetButton
 * Overrided constructor, init writter and set com PIN with param
 * @param int _interruptPin value 
 */
ResetButton::ResetButton(SDWritter* p, int _interruptPin)
{
	writter = p;
	interruptPin = _interruptPin
}

/**
 * init
 * Detect statement 
 */
void ResetButton::init()
{
	attachInterrupt(digitalPinToInterrupt(interruptPin), reset, RISING);
}

/**
 * reset
 * Erase data from SDCard
 */
void ResetButton::reset()
{
	writter->eraseSD();
}