#include "merger.hpp"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <iostream>
#include <QTextStream>
#include <QDirIterator>
#include <QPushButton>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Merger m;
    m.show();


    return app.exec();
}


