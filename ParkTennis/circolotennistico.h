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
    void iscriviGiocatore(QString& ,QString& );
    void iscriviMaestro(QString& ,QString& );
    //altre iscrivi se vengono aggiunti altri sottotipi di Utente
    void eliminaIscrizione(Utente*); //comportamente diverso in base al tipo di Utente che si vuole disiscrivere

};

#endif // CIRCOLOTENNISTICO_H
