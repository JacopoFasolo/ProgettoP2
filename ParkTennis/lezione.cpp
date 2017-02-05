#include "lezione.h"

Lezione::Lezione(Utente* ut, Campo c, Orario o): OradiTennis(ut,c,o){}

double Lezione::quotaMaestro=20.00;

double Lezione::getQuotaMaestro() {return quotaMaestro;}

double Lezione::prezzo() const {
    return (OradiTennis::prezzo()+quotaMaestro);
}

void Lezione::setMaestro(Utente* u){
    if(u)
        user=u;  // usato in una situazione di condivisione controllata della memoria, la gestione della memoria viene fatta dalle funzioni chiamanti
}
