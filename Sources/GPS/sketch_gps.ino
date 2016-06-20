#include "GPS.h"
#include "Arduino.h"

GPS gps;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{  
  gps.read();
}
