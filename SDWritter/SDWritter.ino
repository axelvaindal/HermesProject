#include "SDWriter.h"
SDWriter Writer("43",10);

void setup()
{
 Serial.begin(9600);
}
void loop()
{
  writtre();
  //erase();
 delay(100); 
}

void writtre()
{
  Writer.addToJSONString("test","tarte");
  Writer.pushToSD();
}
void erase()
{
  Writer.eraseSD();
}

