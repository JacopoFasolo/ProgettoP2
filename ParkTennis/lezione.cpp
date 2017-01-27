#include "lezione.h"

Lezione::Lezione(Utente* ut, Campo c, orario o): OradiTennis(ut,c,o){}

double Lezione::quotaMaestro=20.00;

double Lezione::getQuotaMaestro() {return quotaMaestro;}
