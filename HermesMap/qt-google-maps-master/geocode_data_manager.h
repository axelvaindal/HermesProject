#ifndef GEOCODE_DATA_MANAGER_H
#define GEOCODE_DATA_MANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

typedef struct SPoint
{
    double longitude = 0;
    double latitude = 0;
    bool alert = false;
    QString type = "";
    int idGroup = 0;
}SPoint;

class GeocodeDataManager : public QObject
{
    Q_OBJECT
public:
    explicit GeocodeDataManager(QObject *parent = 0);
    QNetworkAccessManager* m_pNetworkAccessManager;
    bool getPoints = false;

    void getCoordinates(const QString& address);
    void lauch();


signals:
    void errorOccured(const QString&);
    void coordinatesReady(double east, double north);
    void addressReady(const QString&);

private slots:
    void replyFinished(QNetworkReply* reply);
    //void getReply(QNetworkReply* reply);

};

#endif // GEOCODE_DATA_MANAGER_H
