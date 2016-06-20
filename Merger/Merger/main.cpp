#include "merger.h"
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

    QPushButton button("");

    // Ouverture de la boîte de dialogue, modale
    QString selectedFolder = QFileDialog::getExistingDirectory(&button, "Select Folder", "C:\\", QFileDialog::ShowDirsOnly | QFileDialog::HideNameFilterDetails);

    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QStringList listFilter;
    listFilter << "*.txt";
    QDirIterator dirIterator(selectedFolder, listFilter ,QDir::Files);


    // Création d'un objet QFile pour l'écriture
    QString selectedFile = QFileDialog::getSaveFileName(&button, "Save File","C:\\","JSON (*.json)");
    QFile writingFile(selectedFile);

    QTextStream writingStream(&writingFile);
    QTextStream readingStream;
    QString content;

    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    writingStream.setCodec("UTF-8");

    if (!writingFile.open(QIODevice::WriteOnly | QIODevice::Text))
          return 0;
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
;
    }

    return 0;

}
