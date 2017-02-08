#include "loginwindow.h"
#include <pannelloutente.h>
#include <circolotennistico.h>
#include <QApplication>
#include <QDebug>
#include <orario.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow w;

    //CircoloTennistico::iscriviGiocatore("Giorgio","12345");
    //CircoloTennistico::tryLogIn("Giorgio","12345");
    //CircoloTennistico::Prenota(8);
    w.show();


    return a.exec();
}
