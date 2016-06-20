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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Merger
{
public:
    QWidget *centralWidget;
    QPushButton *selectFolder;
    QLabel *label;
    QPushButton *selectJson;
    QLabel *label_2;
    QPushButton *merge;
    QLineEdit *folder;
    QLineEdit *json;
    QMenuBar *menuBar;
    QMenu *menuMerger;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Merger)
    {
        if (Merger->objectName().isEmpty())
            Merger->setObjectName(QStringLiteral("Merger"));
        Merger->resize(400, 300);
        centralWidget = new QWidget(Merger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        selectFolder = new QPushButton(centralWidget);
        selectFolder->setObjectName(QStringLiteral("selectFolder"));
        selectFolder->setGeometry(QRect(140, 50, 121, 24));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 91, 20));
        selectJson = new QPushButton(centralWidget);
        selectJson->setObjectName(QStringLiteral("selectJson"));
        selectJson->setGeometry(QRect(140, 90, 121, 24));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 90, 141, 16));
        merge = new QPushButton(centralWidget);
        merge->setObjectName(QStringLiteral("merge"));
        merge->setGeometry(QRect(150, 150, 75, 24));
        folder = new QLineEdit(centralWidget);
        folder->setObjectName(QStringLiteral("folder"));
        folder->setGeometry(QRect(270, 50, 113, 22));
        json = new QLineEdit(centralWidget);
        json->setObjectName(QStringLiteral("json"));
        json->setGeometry(QRect(270, 90, 113, 22));
        Merger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Merger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        menuMerger = new QMenu(menuBar);
        menuMerger->setObjectName(QStringLiteral("menuMerger"));
        Merger->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Merger);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Merger->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Merger);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Merger->setStatusBar(statusBar);

        menuBar->addAction(menuMerger->menuAction());

        retranslateUi(Merger);

        QMetaObject::connectSlotsByName(Merger);
    } // setupUi

    void retranslateUi(QMainWindow *Merger)
    {
        Merger->setWindowTitle(QApplication::translate("Merger", "Merger", 0));
        selectFolder->setText(QApplication::translate("Merger", "Parcourir", 0));
        label->setText(QApplication::translate("Merger", "Dossier source", 0));
        selectJson->setText(QApplication::translate("Merger", "Parcourir", 0));
        label_2->setText(QApplication::translate("Merger", "Fichier de destination", 0));
        merge->setText(QApplication::translate("Merger", "Fusionner", 0));
        menuMerger->setTitle(QApplication::translate("Merger", "Merger", 0));
    } // retranslateUi

};

namespace Ui {
    class Merger: public Ui_Merger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGER_H
