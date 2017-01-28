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
private:
    Utente* user;
    Campo c;
    orario o;
    bool luce;
    static double quotaFissa;
    static double quotaLuce;
    static orario inizioLuce;
    void scalaCampo();
public:
    OradiTennis(Utente*, Campo =Campo(), orario =orario());
    virtual ~OradiTennis()=0;
    static double getQuotaFissa();
    static double getQuotaLuce();
    virtual double prezzo() const;
    Utente* getUtente() const;
    orario getOrario() const;
    Campo getCampo() const;



};

#endif // ORADITENNIS_H
