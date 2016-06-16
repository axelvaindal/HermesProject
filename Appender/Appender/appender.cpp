#include "appender.h"
#include "ui_appender.h"

Appender::Appender(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Appender)
{
    ui->setupUi(this);
}

Appender::~Appender()
{
    delete ui;
}
