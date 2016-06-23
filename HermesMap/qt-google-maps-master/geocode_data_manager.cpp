#include "geocode_data_manager.h"

#include <QJson/Parser>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

GeocodeDataManager::GeocodeDataManager(QObject *parent) :
    QObject(parent)
{
    m_pNetworkAccessManager = new QNetworkAccessManager(this);
    //connect(m_pNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    //connect(m_pNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getReply(QNetworkReply*)));
}

void GeocodeDataManager::getCoordinates(const QString& address)
{
    getPoints = false;
    QString url = QString("http://maps.google.com/maps/api/geocode/json?address=%1&sensor=false&language=en").arg(address);
    m_pNetworkAccessManager->get(QNetworkRequest(QUrl(url)));
    qDebug() << "getCoordinate";
}

void GeocodeDataManager::lauch()
{
    getPoints = true;
    QString url = QString("http://couchdb.neometroplex.eu/hermes/_design/hermes/_view/getAllPositions");
    m_pNetworkAccessManager->get(QNetworkRequest(QUrl(url)));
    qDebug() << "launch";
}

/*void GeocodeDataManager::getReply(QNetworkReply* reply)
{
    qDebug() << "getReply";

    //pointList.clear();

    SPoint pointResult;
    QJsonObject jsonObj;
    QString replyString = (QString)reply->readAll();
    QJsonDocument doc   = QJsonDocument::fromJson(replyString.toUtf8());

    if(!doc.isNull())
        {
            if(doc.isObject())
            {
                jsonObj = doc.object();
            }
            else
            {
                qDebug() << "Document is not an object" << endl;
            }
        }
        else
        {
            qDebug() << "Invalid JSON...\n" << replyString << endl;
        }

    QJsonArray rows = jsonObj["rows"].toArray();

    for(int i=0; i<rows.count(); i++)
    {
        QString type        = "";

        QJsonObject t       = rows.takeAt(i).toObject();
        QJsonObject value   = t.take("value").toObject();

        qDebug() << value;
        qDebug() << value.find("longitude").value();
        qDebug() << value.find("latitude").value();

        double longitude   = value.find("longitude").value().toDouble();
        double latitude    = value.find("latitude").value().toDouble();
        bool alert          = value.find("alert").value().toBool();
        int idGroup         = (int)value.find("idGroup").value().toDouble();//toString().toInt();

        if(alert)
            type    = value.find("type").value().toString();

        pointResult.longitude   = longitude;
        pointResult.latitude    = latitude;
        pointResult.type        = type;
        pointResult.alert       = alert;
        pointResult.idGroup     = idGroup;

        //pointList.append(pointResult);
    }

    //emit(pointOk());
}*/

void GeocodeDataManager::replyFinished(QNetworkReply* reply)
{
    qDebug() << "replyFinished";

    if(!getPoints)
    {
        QString json = reply->readAll();
        qDebug() << "Reply = " << json;
        qDebug() << "URL = " << reply->url();

        QJson::Parser parser;

        bool ok;

        // json is a QString containing the data to convert
        QVariant result = parser.parse (json.toLatin1(), &ok);

        if(!ok)
        {
            emit errorOccured(QString("Cannot convert to QJson object: %1").arg(json));
            return;
        }

        QString code = result.toMap()["status"].toString();
        qDebug() << "Code" << code;

        if(code != "OK")
        {
            emit errorOccured(QString("Code of request is: %1").arg(code));
            return;
        }

        QVariantList results = result.toMap()["results"].toList();

        if(results.count() == 0)
        {
            emit errorOccured(QString("Cannot find any locations"));
            return;
        }

        double east  = results[0].toMap()["geometry"].toMap()["location"].toMap()["lng"].toDouble();
        double north = results[0].toMap()["geometry"].toMap()["location"].toMap()["lat"].toDouble();

        emit coordinatesReady(east, north);

        QString address = results[0].toMap()["formatted_address"].toString();
        emit addressReady(address);
    }
}
