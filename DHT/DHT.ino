#include "DHTSensor.h"
DHTSensor DHT;

void setup() 
{
   Serial.begin(9600);
}

void loop()
{
    DHT.readDHT();
    Serial.println(DHT.getTemperature());
    Serial.println(DHT.getHumidity());
    delay(150);
}

