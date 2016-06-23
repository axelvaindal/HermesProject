#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "geocode_data_manager.h"

namespace Ui {
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

signals:
    void pointOk();

private slots:
    void goClicked();
    void registerPoints();
    void showCoordinates(double east, double north);
    void getReply(QNetworkReply* reply);
    void setCircle(double east, double north, bool alert, QString type);
    void setPointsOk();

private:
    void getCoordinates(const QString& address);
    QList<SPoint> pointList;
    bool pointsOk = false;

private:
    Ui::Form *ui;
    GeocodeDataManager m_geocodeDataManager;
};

#endif // FORM_H
