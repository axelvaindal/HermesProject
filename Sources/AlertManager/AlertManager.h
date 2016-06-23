#ifndef ALERTMANAGER_H
#define ALERTMANAGER_H

#include "Arduino.h"
#include "DHTSensor.h"
#include "GPS.h"
#include "LightSensor.h"
#include "Accelerometer.h"


typedef struct SAlert
{
    int id;
    String type;
    String data;
} SAlert;


/*
 * AlertManager Class
 * Module used to detect alerts from sensors
*/
class AlertManager
{
    public:
        AlertManager();
        bool checkLight(SAlert* alert, SLight* sLight);
        bool checkHumidity(SAlert* alert, SHumidity* sHumidity);

    private:
        int LightCap        = 300;
        int HumidityCap     = 80;
        int idAlert         = 0;
        void createAlert(SAlert* sAlert, String type, String data);
        String parseSLightToString(SLight* sLight);
        String parseSHumidityToString(SHumidity* sHumidity);
};

#endif // ALERTMANAGER_H
