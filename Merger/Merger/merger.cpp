#include "merger.h"
#include "ui_merger.h"

Merger::Merger(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Merger)
{
    ui->setupUi(this);
}

Merger::~Merger()
{
    delete ui;
}
