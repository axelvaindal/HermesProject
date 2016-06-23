#include "merger.hpp"
#include "ui_merger.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <iostream>
#include <QTextStream>
#include <QDirIterator>
#include <QPushButton>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>



using namespace std;

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

void Merger::on_selectFolder_clicked()
{
     // Ouverture de la boîte de dialogue, modale
    ui->folder->setText(QFileDialog::getExistingDirectory(ui->selectFolder, "Select Folder", "C:\\", QFileDialog::ShowDirsOnly | QFileDialog::HideNameFilterDetails));
}

void Merger::on_selectJson_clicked()
{
     // Création d'un objet QFile pour l'écriture
    ui->json->setText(QFileDialog::getSaveFileName(ui->selectJson, "Save File","C:\\","JSON (*.json)"));
}

void Merger::on_merge_clicked()
{
    merge();
}



void Merger::merge()
{
    QString selectedFolder =  ui->folder->text();
    QString selectedFile = ui->json->text();

    QRegularExpression reBegin = QRegularExpression("^(\\\{\\\"DATA\":\\\[){1}");
    QRegularExpression reEnd = QRegularExpression("(\\\]\\\}){1}$");

    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QStringList listFilter;
    listFilter << "*.txt";
    QDirIterator dirIterator(selectedFolder, listFilter ,QDir::Files);
    QFile writingFile(selectedFile);
    QTextStream writingStream(&writingFile);
    QTextStream readingStream;
    QString content;

    //Connecteur à la base de données
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);
    QNetworkRequest request(QUrl("http://couch:SuperDoudou31@couchdb.neometroplex.eu/test/"));
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply *)));
    request.setRawHeader("User-Agent", "Test");
    request.setRawHeader("X-Custom-User-Agent","Test");
    request.setRawHeader("Content-Type"," application/json");
    request.setRawHeader("Keep-Alive", "timeout=20 max=100");
    request.setRawHeader("Connection", "keep-alive");

    int size = 0;
    int posComma = 0;
    int posDate = 0;
    QString idGroup;

    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    writingStream.setCodec("UTF-8");

    if (!writingFile.open(QIODevice::WriteOnly | QIODevice::Text))
          return ;
    writingStream <<"[";
    // On parcoure le dossier pour fussioner l'ensemble des fichiers
    while(dirIterator.hasNext())
    {
        QFile readingFile(dirIterator.next());
        readingFile.open(QIODevice::ReadOnly | QIODevice::Text);
        readingStream.setDevice(&readingFile);
        content = readingStream.readAll();
        QByteArray json = content.toUtf8();
        manager->post(request, json);
        content.remove(reBegin);
        content.remove(reEnd);
        size = content.length();
        posComma = 0;
        posDate = 0;
        if(content.indexOf(QRegExp("(\\\"id\\\":){1}[0-9]{2,2}"),0,idGroup)==-1)
        {
            idGroup = "Invalid";
        }


        while(true)
        {
            content.replace(QRegExp("\\\"id\\\":"),"\"idGroup\":"+idGroup+",\"id\":");

            posDate = content.indexOf(QRegExp("((\"(d|D)ate(h|H)eure\":){1})([ ]{0,1})([^ \"]{1})"),posDate);
            posComma = content.indexOf(QRegExp("([0-9])+,([0-9])+"),posComma);
            if(posDate==-1 && posComma==-1)
            {
                break;
            }
            else if(posComma!=-1)
            {
                posComma = content.indexOf(",",posComma);
                content.replace(posComma,1,".");
            }

            else if(posDate!=-1)
            {
                content.replace(posDate,12,"\"DateHeure\":\"");
                posDate= content.indexOf(",",posDate);
                content.replace(posDate,1,"\",");
            }
        }
        writingStream <<(content);
        writingStream << ",";
        readingStream.flush();
    }
    writingStream <<"]";

    writingFile.close();

}

void Merger::replyFinished(QNetworkReply * reply)
{
    printf(reply->readAll());
}








