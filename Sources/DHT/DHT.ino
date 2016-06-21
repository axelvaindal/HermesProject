#include "DHTSensor.h"
DHTSensor DHT;

void setup() 
{
   Serial.begin(9600);
}

void loop()
{
    DHT.read();
    Serial.println(DHT.getTemperature().temperature);
    Serial.println(DHT.getHumidity().humidity);
    delay(150);
}