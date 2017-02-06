#ifndef CALENDARIOGIORNALIERO_H
#define CALENDARIOGIORNALIERO_H

#include <oraditennis.h>
#include <partita.h>
#include <lezione.h>
#include <orario.h>
#include <campo.h>
#include <list>
#include <utente.h>
#include <giocatore.h>
#include <maestro.h>
#include <admin.h>
#include <QString>
#include <QDebug>
using std::list;


class CalendarioGiornaliero{
friend class CircoloTennistico;
private:
    list<OradiTennis*> l;
    static Orario apertura;
    static Orario ultimaOraPrenotabile;
    static int nCampi;
    void scalaSuccessive(OradiTennis*);
    Campo primoCampoDisponibile(Orario o) const;
    void clear();
public:
    static Orario getApertura();
    static Orario getUltimaOra();
    static int getNumCampi();
    ~CalendarioGiornaliero();
    bool nessunaPrenotazione() const;
    void prenotaOra(Utente*, Orario);
    void eliminaPrenotazione(OradiTennis*);
    void eliminaPrenotazione(Utente*,Orario,Campo);
    void eliminaPartiteGiocatore(Utente*);
    void eliminaTutteLezioni();
    int contaPartite() const;
    int contaLezioni() const;
    double guadagnoGiornaliero() const;
    void sostiuisciMaestro(Utente*, Utente*);
};

#endif // CALENDARIOGIORNALIERO_H
