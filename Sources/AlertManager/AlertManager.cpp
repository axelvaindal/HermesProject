#include "AlertManager.h"

AlertManager::AlertManager()
{
}

/*
 * AlertManager::checkLight
 * Check if light value is too high and send an alert to the buffer
 * @param {Light *} light : Light object to check
*/
bool AlertManager::checkLight(SAlert* alert, SLight* sLight)
{
    if(sLight->lightLevel > LightCap)
    {
        createAlert(alert, "Light", parseSLightToString(sLight));
        return true;
    }

    return false;
}

/*
 * AlertManager::checkHumidity
 * Check if humidity value is too high and send an alert to the buffer
 * @param {Humidity *} humidity : Humidity object to check
*/
bool AlertManager::checkHumidity(SAlert* alert, SHumidity* sHumidity)
{
    if(sHumidity->humidity > HumidityCap)
    {
        createAlert(alert, "Humidity", parseSHumidityToString(sHumidity));
        return true;
    }

    return false;
}

/*
 * AlertManager::createAlert
 * Private method to create Alert struct from alert infos
 * @param {String} type: String descripting which type of sensor is sending the alert (Humidity, Light, etc...)
 * @param {String} data: JSON string descripting the values of the sensor
*/
void AlertManager::createAlert(SAlert* alert, String type, String data)
{
    this->idAlert++;

    alert->id = idAlert;
    alert->type = type;
    alert->data = data;
}

/*
 * AlertManager::parseSLightToString
 * Private method to parse Light structure to JSON string
 * @param {SLight*} sLight: Light Structure with lightLevel int argument
*/
String AlertManager::parseSLightToString(SLight* sLight)
{
    String parsedString = "{\"lightLevel\": ";
    parsedString        += sLight->lightLevel;
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
    parsedString        += sHumidity->humidity;
    parsedString        += "}";
    return parsedString;
}
