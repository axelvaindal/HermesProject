/********************************************************************************
** Form generated from reading UI file 'merger.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERGER_H
#define UI_MERGER_H

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

class Ui_Merger
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Merger)
    {
        if (Merger->objectName().isEmpty())
            Merger->setObjectName(QStringLiteral("Merger"));
        Merger->resize(400, 300);
        menuBar = new QMenuBar(Merger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Merger->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Merger);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Merger->addToolBar(mainToolBar);
        centralWidget = new QWidget(Merger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Merger->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Merger);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Merger->setStatusBar(statusBar);

        retranslateUi(Merger);

        QMetaObject::connectSlotsByName(Merger);
    } // setupUi

    void retranslateUi(QMainWindow *Merger)
    {
        Merger->setWindowTitle(QApplication::translate("Merger", "Merger", 0));
    } // retranslateUi

};

namespace Ui {
    class Merger: public Ui_Merger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGER_H
