#include "appender.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <iostream>
#include <QTextStream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QString fileLecture = "C:/test.txt";
    QFile fichierLecture(fileLecture);
    fichierLecture.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream fluxLecture(&fichierLecture);

    QString fileLecture2 = "C:/Qt.txt";
    QFile fichierLecture2(fileLecture2);
    fichierLecture2.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream fluxLecture2(&fichierLecture2);

    // Création d'un objet QFile
    QFile fileEcriture("C:/ecritureTest.txt");
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!fileEcriture.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return 0;
    }

    // Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream fluxEcriture(&fileEcriture);
    // On choisit le codec correspondant au jeu de caractère que l'on souhaite ; ici, UTF-8
    fluxEcriture.setCodec("UTF-8");
    // Écriture des différentes lignes dans le fichier
    QString content2 = fluxLecture2.readAll();
    QString content = fluxLecture.readAll();
    fluxEcriture.operator <<(content);
    fluxEcriture.operator <<(content2);
    Appender w;
    w.show();

    return a.exec();
}
