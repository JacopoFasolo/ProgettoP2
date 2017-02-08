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
    ~CircoloTennistico();
    static CalendarioGiornaliero* c;
    static Iscritti* i;
    static Utente* loggedIn;
    static void tryLogIn(QString u, QString p);
    static Iscritti* loadIscrizioni();
    static CalendarioGiornaliero* loadPrenotazioni();
    void saveIscritti(Iscritti*) const;
    void savePrenotazioni(CalendarioGiornaliero*) const;
    static void iscriviGiocatore(QString ,QString ="12345");
    static void iscriviMaestro(QString ,QString ="12345");
    //altre iscrivi se vengono aggiunti altri sottotipi di Utente
    static void eliminaIscrizione(Utente*); //comportamente diverso in base al tipo di Utente che si vuole disiscrivere
    static void Prenota(Orario);
    void inizioGiornata();
};

#endif // CIRCOLOTENNISTICO_H
