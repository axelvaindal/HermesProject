#ifndef RESETBUTTON_H
#define RESETBUTTON_H

#include "Arduino.h"
#include "SDWritter.h"

/**
 *  ResetButton class
 *  This class allows to make an interruption when the pin's state change
 */
class ResetButton
{
	private:
		int8_t interruptPin;
		SDWritter* writter;
		
	public:
		ResetButton(SDWritter* writter);
		ResetButton(SDWritter* writter, int _interruptPin);
		void init();
		void reset();
}
