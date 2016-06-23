#include "form.h"
#include "ui_form.h"
#include <QDebug>
#include <QWebFrame>
#include <QWebElement>
#include <QMessageBox>
#include <QJson/Parser>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->goButton, SIGNAL(clicked()), this, SLOT(goClicked()));
    connect(ui->buttonShowPoints, SIGNAL(clicked()), this, SLOT(registerPoints()));

    connect(&m_geocodeDataManager, SIGNAL(coordinatesReady(double,double)), this, SLOT(showCoordinates(double,double)));
    connect(m_geocodeDataManager.m_pNetworkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getReply(QNetworkReply*)));

    connect(this, SIGNAL(pointOk()), this, SLOT(setPointsOk()));

    connect(&m_geocodeDataManager, SIGNAL(addressReady(QString)), ui->lePostalAddress, SLOT(setText(QString)));

    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);

    ui->lePostalAddress->setText("");
    ui->webView->setUrl(QUrl("qrc:/html/google_maps.html"));

    QStringList groupList;

    for(int i=1; i<46; i++)
    {
        groupList.append(QString::number(i));
    }

    ui->listGroup->addItems(groupList);

    m_geocodeDataManager.lauch();
}

Form::~Form()
{
    delete ui;
}

void Form::setPointsOk()
{
    pointsOk = true;
}

void Form::registerPoints()
{
    qDebug() << "registerPoints";

    if(!pointsOk)
    {
        QMessageBox::warning(this, "Chargement en cours","Les points n'ont pas finis de se charger.\nVeuillez réessayer plus tard.");
        return;
    }

    QString str =
            QString("for (var val in circles){") +
            QString("val.setMap(null); }");

    qDebug() << str;
    ui->webView->page()->currentFrame()->documentElement().evaluateJavaScript(str);
    qDebug() << "Count points : " << pointList.count();
    for(int i = 0; i < 60/*pointList.count()*/;i++)
    {
        if(ui->listGroup->currentRow() + 1 == pointList[i].idGroup)
        {
            setCircle(pointList[i].longitude,pointList[i].latitude,pointList[i].alert,pointList[i].type);
        }
    }
}

void Form::setCircle(double east, double north, bool alert, QString type)
{
    QString strokeColor = "#3C61C8";
    QString fillColor   = "#47BFE3";
    int radius          = 5000;

    if(alert)
    {
        if(type == "temperature")
        {
            strokeColor = "#BAC002";
            fillColor   = "#F6FE01";
            radius      = 10000;
        }
        else if(type == "humidity")
        {
            strokeColor = "#3C61C8";
            fillColor   = "#47BFE3";
            radius      = 10000;
        }
        else if(type == "choc")
        {
            strokeColor = "#AC0000";
            fillColor   = "#FE0101";
            radius      = 10000;
        }
        else
        {
            strokeColor = "#199700";
            fillColor   = "#29F401";
            radius      = 5000;
        }
    }
    else
    {
        strokeColor = "#199700";
        fillColor   = "#29F401";
        radius      = 5000;
    }

    QString str =
            QString("var circle = new google.maps.Circle({") +
            QString("strokeColor: '%1',").arg(strokeColor) +
            QString("strokeOpacity: 0.8, ") +
            QString("strokeWeight: 2, ") +
            QString("fillColor: '%1', ").arg(fillColor) +
            QString("fillOpacity: 0.3, ") +
            QString("map: map,") +
            QString("center: {lat: %1, lng: %2}, ").arg(north).arg(east) +
            QString("radius: %1").arg(radius) +
            QString("});") +
            QString("circles.push(circle);");

    //qDebug() << str;

    ui->webView->page()->currentFrame()->documentElement().evaluateJavaScript(str);
}

void Form::getReply(QNetworkReply* reply)
{
    qDebug() << "getReply";

    pointList.clear();

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

        double longitude    = value.find("longitude").value().toDouble();
        double latitude     = value.find("latitude").value().toDouble();
        bool alert          = value.find("alert").value().toBool();
        int idGroup         = (int)value.find("idGroup").value().toDouble();//toString().toInt();

        if(alert)
            type    = value.find("type").value().toString();

        pointResult.longitude   = longitude;
        pointResult.latitude    = latitude;
        pointResult.type        = type;
        pointResult.alert       = alert;
        pointResult.idGroup     = idGroup;

        pointList.append(pointResult);
    }

    emit(pointOk());
}

void Form::goClicked()
{
    QString address = ui->lePostalAddress->text();
    m_geocodeDataManager.getCoordinates(address.replace(" ", "+"));
}

void Form::showCoordinates(double east, double north)
{
    qDebug() << "Form, showCoordinates" << east << north;

    QString str =
            QString("var newLoc = new google.maps.LatLng(%1, %2); ").arg(north).arg(east) +
            QString("map.setCenter(newLoc);") +
            QString("map.setZoom(%1);").arg(ui->zoomSpinBox->value());

     qDebug() << str;

    ui->webView->page()->currentFrame()->documentElement().evaluateJavaScript(str);
}
