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
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Merger)
    {
        if (Merger->objectName().isEmpty())
            Merger->setObjectName(QStringLiteral("Merger"));
        Merger->resize(474, 300);
        Merger->setStyleSheet(QStringLiteral("background-color:rgb(9, 0, 83);"));
        centralWidget = new QWidget(Merger);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        selectFolder = new QPushButton(centralWidget);
        selectFolder->setObjectName(QStringLiteral("selectFolder"));
        selectFolder->setGeometry(QRect(380, 60, 71, 24));
        selectFolder->setStyleSheet(QLatin1String("background-color:#fff;\n"
"border-radius : 3px;"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 91, 20));
        label->setStyleSheet(QStringLiteral("color:#fff"));
        selectJson = new QPushButton(centralWidget);
        selectJson->setObjectName(QStringLiteral("selectJson"));
        selectJson->setGeometry(QRect(380, 100, 71, 24));
        selectJson->setStyleSheet(QLatin1String("background-color:#fff;\n"
"border-radius:3px;"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 141, 16));
        label_2->setStyleSheet(QStringLiteral("color:#fff"));
        merge = new QPushButton(centralWidget);
        merge->setObjectName(QStringLiteral("merge"));
        merge->setGeometry(QRect(380, 190, 71, 41));
        merge->setStyleSheet(QLatin1String("background-color:#fff;\n"
"border-radius:3px;"));
        folder = new QLineEdit(centralWidget);
        folder->setObjectName(QStringLiteral("folder"));
        folder->setGeometry(QRect(180, 60, 181, 22));
        folder->setStyleSheet(QStringLiteral("background-color:#fff"));
        json = new QLineEdit(centralWidget);
        json->setObjectName(QStringLiteral("json"));
        json->setGeometry(QRect(180, 100, 181, 22));
        json->setStyleSheet(QStringLiteral("background-color:#fff"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(130, 0, 211, 41));
        label_4->setStyleSheet(QLatin1String("color:#fff;\n"
"font-size : 30px;\n"
"font:\"Roboto\";"));
        Merger->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Merger);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 474, 21));
        Merger->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Merger);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Merger->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Merger);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Merger->setStatusBar(statusBar);

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
        label_4->setText(QApplication::translate("Merger", "Hermes Merger", 0));
    } // retranslateUi

};

namespace Ui {
    class Merger: public Ui_Merger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERGER_H
