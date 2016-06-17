#include "SDWriter.h"

SDWriter Writer("43", 10);

void setup()
{
	Serial.begin(9600);
	Writer.initialize();
}

void loop()
{
	if (Writer.isInitialized())
	{
		//Writer.addToJSONString("titi", "toto");
		//Writer.pushToSD();
	}
	else
	{
		Writer.raz();
	}
    
  	delay(100); 
}
