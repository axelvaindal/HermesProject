#include "AlertManager.h"

AlertManager::AlertManager(BufferManager* bufferManager)
{
    this->bufferManager = bufferManager;
}

/*
 * AlertManager::checkLight
 * Check if light value is too high and send an alert to the buffer
 * @param {Light *} light : Light object to check
*/
void AlertManager::checkLight(SLight* sLight)
{
    if(sLight->lightLevel > LightCap)
    {
        this->createAlert("Light", this->parseSLightToString(sLight));
    }
}

/*
 * AlertManager::checkHumidity
 * Check if humidity value is too high and send an alert to the buffer
 * @param {Humidity *} humidity : Humidity object to check
*/
void AlertManager::checkHumidity(SHumidity* sHumidity)
{
    if(sHumidity->humidityLevel > HumidityCap)
    {
        this->createAlert("Humidity", this->parseSHumidityToString(sHumidity));
    }
}

/*
 * AlertManager::createAlert
 * Private method to create Alert struct from alert infos
 * @param {String} type: String descripting which type of sensor is sending the alert (Humidity, Light, etc...)
 * @param {String} data: JSON string descripting the values of the sensor
*/
void AlertManager::createAlert(SAlert* sAlert, String type, String data)
{
    this->idAlert++;
    sAlert->id = idAlert;
    sAlert->type = type;
    sAlert->data = data;

    buffermanager->pushAlert(sAlert);
}

/*
 * AlertManager::parseSLightToString
 * Private method to parse Light structure to JSON string
 * @param {SLight*} sLight: Light Structure with lightLevel int argument
*/
String AlertManager::parseSLightToString(SLight* sLight)
{
    String parsedString = "{\"lightLevel\": ";
    parsedString        += sLight.lightLevel;
    parsedString        += "}";
    return parsedString;
}

/*
 * AlertManager::parseSHumidityToString
 * Private method to parse Humidity structure to JSON string
 * @param {SHumidity*} sHumidity: Humidity Structure with humidityLevel int argument
*/
String AlertManager::parseSHumidityToString(SHumidity* sHumidity)
{
    String parsedString = "{\"humidityLevel\": ";
    parsedString        += sHumidity.humidityLevel;
    parsedString        += "}";
    return parsedString;
}
