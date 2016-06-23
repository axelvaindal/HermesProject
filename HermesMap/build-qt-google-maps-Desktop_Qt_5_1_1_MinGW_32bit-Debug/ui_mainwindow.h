/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionMoscow;
    QAction *actionNewYork;
    QAction *actionLondon;
    QAction *actionSanJose_CA;
    QAction *actionBedford_MA;
    QAction *actionSky;
    QAction *actionBorders;
    QAction *actionRoads;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 700);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionMoscow = new QAction(MainWindow);
        actionMoscow->setObjectName(QStringLiteral("actionMoscow"));
        actionNewYork = new QAction(MainWindow);
        actionNewYork->setObjectName(QStringLiteral("actionNewYork"));
        actionLondon = new QAction(MainWindow);
        actionLondon->setObjectName(QStringLiteral("actionLondon"));
        actionSanJose_CA = new QAction(MainWindow);
        actionSanJose_CA->setObjectName(QStringLiteral("actionSanJose_CA"));
        actionBedford_MA = new QAction(MainWindow);
        actionBedford_MA->setObjectName(QStringLiteral("actionBedford_MA"));
        actionSky = new QAction(MainWindow);
        actionSky->setObjectName(QStringLiteral("actionSky"));
        actionBorders = new QAction(MainWindow);
        actionBorders->setObjectName(QStringLiteral("actionBorders"));
        actionBorders->setCheckable(true);
        actionRoads = new QAction(MainWindow);
        actionRoads->setObjectName(QStringLiteral("actionRoads"));
        actionRoads->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Hermes Map", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionMoscow->setText(QApplication::translate("MainWindow", "Moscow", 0));
        actionNewYork->setText(QApplication::translate("MainWindow", "New York", 0));
        actionLondon->setText(QApplication::translate("MainWindow", "London", 0));
        actionSanJose_CA->setText(QApplication::translate("MainWindow", "San Jose CA", 0));
        actionBedford_MA->setText(QApplication::translate("MainWindow", "Bedford MA", 0));
        actionSky->setText(QApplication::translate("MainWindow", "Sky", 0));
        actionBorders->setText(QApplication::translate("MainWindow", "Borders and Names", 0));
        actionRoads->setText(QApplication::translate("MainWindow", "Roads", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
