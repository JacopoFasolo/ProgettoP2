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


class CalendarioGiornaliero
{
private:
    list<OradiTennis*> l;
    static orario apertura;
    static orario ultimaOraPrenotabile;
    static int nCampi;
    void scalaSuccessive(OradiTennis*);
    void clear();
public:
    CalendarioGiornaliero();
    static orario getApertura();
    static orario getUltimaOra();
    static int getNumCampi();
    Campo primoCampoDisponibile(orario o) const;
    bool nessunaPrenotazione() const;
    void prenotaOra(Utente*, orario);
    int contaPartite() const;
    int contaLezioni() const;
    double guadagnoGiornaliero() const;
};

#endif // CALENDARIOGIORNALIERO_H
