/********************************************************************************
** Form generated from reading UI file 'appender.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPENDER_H
#define UI_APPENDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Appender
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Appender)
    {
        if (Appender->objectName().isEmpty())
            Appender->setObjectName(QStringLiteral("Appender"));
        Appender->resize(400, 300);
        menuBar = new QMenuBar(Appender);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Appender->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Appender);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Appender->addToolBar(mainToolBar);
        centralWidget = new QWidget(Appender);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Appender->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Appender);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Appender->setStatusBar(statusBar);

        retranslateUi(Appender);

        QMetaObject::connectSlotsByName(Appender);
    } // setupUi

    void retranslateUi(QMainWindow *Appender)
    {
        Appender->setWindowTitle(QApplication::translate("Appender", "Appender", 0));
    } // retranslateUi

};

namespace Ui {
    class Appender: public Ui_Appender {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPENDER_H
