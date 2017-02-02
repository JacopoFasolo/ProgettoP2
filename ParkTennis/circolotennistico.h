#ifndef CIRCOLOTENNISTICO_H
#define CIRCOLOTENNISTICO_H

#include <calendariogiornaliero.h>
#include <QString>
#include <iscritti.h>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>
#include <QString>
using namespace std;

class CircoloTennistico
{
public:
    CircoloTennistico();
    ~CircoloTennistico();
    CalendarioGiornaliero c;
    static Iscritti i;
    Utente* loggedIn;
    void tryLogIn(QString u, QString p);
    void saveIscritti(Iscritti*) const;
    void savePrenotazioni(CalendarioGiornaliero*) const;
    void iscriviGiocatore(QString& ,QString& );
    void iscriviMaestro(QString& ,QString& );
    //altre iscrivi se vengono aggiunti altri sottotipi di Utente
    void eliminaIscrizione(Utente*); //comportamente diverso in base al tipo di Utente che si vuole disiscrivere
    void aggiungiPrenotazione(Utente*,orario);
};

#endif // CIRCOLOTENNISTICO_H
