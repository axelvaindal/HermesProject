#include "LightSensor.h"
LightSensor Light; //Pin par défaut : 0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println(Light.read().lightLevel);
}
