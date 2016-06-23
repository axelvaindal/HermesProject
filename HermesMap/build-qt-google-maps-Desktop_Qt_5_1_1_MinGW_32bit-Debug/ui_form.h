/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QGridLayout *gridLayout;
    QWebView *webView;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lePostalAddress;
    QLabel *label_2;
    QSpinBox *zoomSpinBox;
    QPushButton *goButton;
    QListWidget *listGroup;
    QPushButton *buttonShowPoints;
    QLabel *label_4;
    QLabel *label_3;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(903, 672);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        webView = new QWebView(Form);
        webView->setObjectName(QStringLiteral("webView"));
        webView->setAutoFillBackground(false);
        webView->setUrl(QUrl(QStringLiteral("about:blank")));

        gridLayout->addWidget(webView, 1, 0, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lePostalAddress = new QLineEdit(Form);
        lePostalAddress->setObjectName(QStringLiteral("lePostalAddress"));

        horizontalLayout->addWidget(lePostalAddress);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        zoomSpinBox = new QSpinBox(Form);
        zoomSpinBox->setObjectName(QStringLiteral("zoomSpinBox"));
        zoomSpinBox->setMinimum(5);
        zoomSpinBox->setMaximum(30);
        zoomSpinBox->setSingleStep(1);
        zoomSpinBox->setValue(15);

        horizontalLayout->addWidget(zoomSpinBox);

        goButton = new QPushButton(Form);
        goButton->setObjectName(QStringLiteral("goButton"));

        horizontalLayout->addWidget(goButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listGroup = new QListWidget(Form);
        listGroup->setObjectName(QStringLiteral("listGroup"));
        listGroup->setMaximumSize(QSize(168, 16777215));
        listGroup->setLayoutDirection(Qt::LeftToRight);
        listGroup->setTextElideMode(Qt::ElideLeft);
        listGroup->setLayoutMode(QListView::SinglePass);

        gridLayout->addWidget(listGroup, 1, 1, 1, 1);

        buttonShowPoints = new QPushButton(Form);
        buttonShowPoints->setObjectName(QStringLiteral("buttonShowPoints"));

        gridLayout->addWidget(buttonShowPoints, 2, 1, 1, 1);

        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setScaledContents(false);

        gridLayout->addWidget(label_3, 3, 0, 1, 1, Qt::AlignBottom);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
        label->setText(QApplication::translate("Form", "Adresse :", 0));
        label_2->setText(QApplication::translate("Form", "Zoom", 0));
        goButton->setText(QApplication::translate("Form", "Go", 0));
        buttonShowPoints->setText(QApplication::translate("Form", "Afficher les points", 0));
        label_4->setText(QApplication::translate("Form", "Num\303\251ro de groupe/trajet :", 0));
        label_3->setText(QApplication::translate("Form", "<html><head/><body><p><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt;\">L\303\251gende des relev\303\251s : </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt; color:#00b050;\">Vert -&gt; RAS </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt;\">| </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt; color:#0070c0;\">Bleu -&gt; Humidit\303\251 </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt;\">| </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt; color:#ffc000;\">Jaune -&gt; Choc </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt;\">| </span><span style=\" font-family:'Calibri,sans-serif'; font-size:11pt; color:#ff0000;\">Rouge -&gt; Temp\303\251rature</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
