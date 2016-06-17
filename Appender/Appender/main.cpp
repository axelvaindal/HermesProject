#include "appender.h"
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
    QApplication a(argc, argv);

    QPushButton button("Parcourir");

    button.show();



    // Ouverture de la boîte de dialogue, modale
    QString selectedFolder = QFileDialog::getExistingDirectory(&button, "Select Folder", "C:\\", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    // On vérifie que l'utilisateur a bien sélectionné un fichier
    // Si la chaîne est vide, c'est que l'utilisateur a cliqué sur annuler
    if(selectedFolder.isEmpty())
    {
        return 0;
    }

    // On déclare un QDirIterator dans lequel on indique que l'on souhaite parcourir un répertoire et ses sous-répertoires.
    // De plus, on spécifie le filtre qui nous permettra de récupérer uniquement les fichiers du type souhaité.
    QStringList listFilter;
    listFilter << "*.txt";

    QDirIterator dirIterator(selectedFolder, listFilter ,QDir::Files);

    // Variable qui contiendra tous les fichiers correspondant à notre recherche
    QStringList fileList;

    // Création d'un objet QFile
    QFile fileEcriture("C:/Test/ecritureTest2.json");
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!fileEcriture.open(QIODevice::WriteOnly | QIODevice::Text))
        return 0;

    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream fluxEcriture(&fileEcriture);
    QTextStream fluxLecture;
    QString content;
    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    fluxEcriture.setCodec("UTF-8");

    // Tant qu'on n'est pas arrivé à la fin de l'arborescence...
    while(dirIterator.hasNext())
    {
        QFile fichierLecture(dirIterator.next());
        fichierLecture.open(QIODevice::ReadOnly | QIODevice::Text);
        fluxLecture.setDevice(&fichierLecture);
        content = fluxLecture.readAll();
        fluxEcriture <<(content);
        fluxLecture.flush();
    }

    return a.exec();
}
