#include "oraditennis.h"

double OradiTennis::quotaFissa=5.00;

double OradiTennis::quotaLuce=1.00;

OradiTennis::OradiTennis(Utente* u, Campo d, orario p):user(u), c(d), o(p){
    luce=((o>=inizioLuce) ? true : false);
};

OradiTennis::~OradiTennis(){}

double OradiTennis::getQuotaFissa(){return quotaFissa;}

double OradiTennis::getQuotaLuce(){return quotaLuce;}

orario OradiTennis::inizioLuce=orario(18);

void OradiTennis::scalaCampo(){
    if(c!=Campo(1))
        --c;
}

double OradiTennis::prezzo() const{
    return ((luce) ? quotaLuce : 0) + quotaFissa + Campo::noleggioCampo();
}

Utente* OradiTennis::getUtente() const {return user;}

Campo OradiTennis::getCampo() const {return c;}

orario OradiTennis::getOrario() const {return o;}

