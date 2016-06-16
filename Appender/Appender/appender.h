#ifndef APPENDER_H
#define APPENDER_H

#include <QMainWindow>

namespace Ui {
class Appender;
}

class Appender : public QMainWindow
{
    Q_OBJECT

public:
    explicit Appender(QWidget *parent = 0);
    ~Appender();

private:
    Ui::Appender *ui;
};

#endif // APPENDER_H
