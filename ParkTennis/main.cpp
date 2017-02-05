#include "mainwindow.h"
#include <circolotennistico.h>
#include <QApplication>
#include <QDebug>
#include <orario.h>

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

    CircoloTennistico cir;
    try{
        //cir.scorri();
        //cir.iscriviGiocatore("giorgio");
        //cir.iscriviMaestro("graz");
        //cir.scorri();
    }
    catch(QString x){
        qDebug()<<x;
    }

    //return a.exec();
}
