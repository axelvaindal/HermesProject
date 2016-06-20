#include "merger.hpp"
#include "ui_merger.h"
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <iostream>
#include <QTextStream>
#include <QDirIterator>
#include <QPushButton>

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
    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QStringList listFilter;
    listFilter << "*.txt";
    QDirIterator dirIterator(selectedFolder, listFilter ,QDir::Files);
    QFile writingFile(selectedFile);
    QTextStream writingStream(&writingFile);
    QTextStream readingStream;
    QString content;

    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    writingStream.setCodec("UTF-8");

    if (!writingFile.open(QIODevice::WriteOnly | QIODevice::Text))
          return ;
    // On parcoure le dossier pour fussioner l'ensemble des fichiers
    while(dirIterator.hasNext())
    {
        QFile readingFile(dirIterator.next());
        readingFile.open(QIODevice::ReadOnly | QIODevice::Text);
        readingStream.setDevice(&readingFile);
        content = readingStream.readAll();
        writingStream <<(content);
        writingStream << endl;
        readingStream.flush();
    }
    writingFile.close();
}
