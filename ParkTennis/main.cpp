#include "loginwindow.h"
#include <circolotennistico.h>
#include <QApplication>
#include <QDebug>
#include <orario.h>

CircoloTennistico cir;

int main(int argc, char *argv[])
{
    CircoloTennistico* cir=new CircoloTennistico;
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();


    return a.exec();
}
