#ifndef ORADITENNIS_H
#define ORADITENNIS_H

#include <campo.h>
#include <orario.h>
class Utente;
class Giocatore;
class Maestro;
class Admin;

class OradiTennis
{
    friend class CalendarioGiornaliero;
protected:
    Utente* user;
    Campo c;
    Orario o;
    bool luce;
    static double quotaFissa;
    static double quotaLuce;
    static Orario inizioLuce;
    void scalaCampo();
public:
    OradiTennis(Utente*, Campo =Campo(), Orario =Orario());
    virtual ~OradiTennis()=0;
    static double getQuotaFissa();
    static double getQuotaLuce();
    virtual double prezzo() const;
    Utente* getUtente() const;
    Orario getOrario() const;
    Campo getCampo() const;



};

#endif // ORADITENNIS_H
