#ifndef CIRCOLOTENNISTICO_H
#define CIRCOLOTENNISTICO_H

#include <calendariogiornaliero.h>
#include <iscritti.h>
#include <orario.h>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <QString>
#include <QtXml>
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
    static Iscritti* loadIscrizioni();
    CalendarioGiornaliero* loadPrenotazioni();
    void saveIscritti(Iscritti*) const;
    void savePrenotazioni(CalendarioGiornaliero*) const;
    static void iscriviGiocatore(QString ,QString ="12345");
    static void iscriviMaestro(QString ,QString ="12345");
    //altre iscrivi se vengono aggiunti altri sottotipi di Utente
    void eliminaIscrizione(Utente*); //comportamente diverso in base al tipo di Utente che si vuole disiscrivere
    void Prenota(Orario);
    void scorri()const;
};

#endif // CIRCOLOTENNISTICO_H
