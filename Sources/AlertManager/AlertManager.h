#ifndef ALERTMANAGER_H
#define ALERTMANAGER_H

#include "Arduino.h"
//#include "Light.h"
//#include "Humidity.h"

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
        AlertManager(BufferManager* bufferManager);
        void checkLight(SLight* sLight);
        void checkHumidity(SHumidity* sHumidity);

    private:
        int LightCap        = 300;
        int HumidityCap     = 80;
        int idAlert         = 0;
        BufferManager* bufferManager;
        void createAlert(SAlert* sAlert, String type, String data);
        String parseSLightToString(SLight* sLight);
        String parseSHumidityToString(SHumidity* sHumidity);
};

#endif // ALERTMANAGER_H
