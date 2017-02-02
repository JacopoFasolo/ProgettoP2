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
using std::list;


class CalendarioGiornaliero{
friend class CircoloTennistico;
private:
    list<OradiTennis*> l;
    static orario apertura;
    static orario ultimaOraPrenotabile;
    static int nCampi;
    void scalaSuccessive(OradiTennis*);
    Campo primoCampoDisponibile(orario o) const;
    void clear();
public:
    static orario getApertura();
    static orario getUltimaOra();
    static int getNumCampi();
    ~CalendarioGiornaliero();
    bool nessunaPrenotazione() const;
    void prenotaOra(Utente*, orario);
    void eliminaPrenotazione(OradiTennis*);
    void eliminaPartiteGiocatore(Utente*);
    void eliminaTutteLezioni();
    int contaPartite() const;
    int contaLezioni() const;
    double guadagnoGiornaliero() const;
    void sostiuisciMaestro(Utente*, Utente*);
};

#endif // CALENDARIOGIORNALIERO_H
