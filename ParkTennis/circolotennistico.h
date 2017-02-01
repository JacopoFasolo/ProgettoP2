#ifndef CIRCOLOTENNISTICO_H
#define CIRCOLOTENNISTICO_H

#include <calendariogiornaliero.h>
#include <QString>
#include <iscritti.h>

class CircoloTennistico
{
public:
    CircoloTennistico();
    CalendarioGiornaliero c;
    static Iscritti i;
    Utente* loggedIn;
    void tryLogIn(QString u, QString p);
};

#endif // CIRCOLOTENNISTICO_H
