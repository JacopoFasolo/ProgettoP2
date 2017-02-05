#include "calendariogiornaliero.h"

Orario CalendarioGiornaliero::apertura=8;

Orario CalendarioGiornaliero::ultimaOraPrenotabile=23;

int CalendarioGiornaliero::nCampi=12;

Orario CalendarioGiornaliero::getApertura(){return apertura;}

Orario CalendarioGiornaliero::getUltimaOra(){return ultimaOraPrenotabile;}

int CalendarioGiornaliero::getNumCampi(){return nCampi;}

CalendarioGiornaliero::~CalendarioGiornaliero(){
    clear();
}

bool CalendarioGiornaliero::nessunaPrenotazione() const {
    return l.begin()==l.end();
}

Campo CalendarioGiornaliero::primoCampoDisponibile(Orario o) const {
    if(o<apertura || o>ultimaOraPrenotabile)
        throw QString("Orario non valido");
    list<OradiTennis*>::const_iterator cur=l.begin();
    if(nessunaPrenotazione() || (*cur)->getOrario()>o) //se la lista è vuota la 1a condizione è vera e la 2a non viene controllata, così non avro segmentation fault
        return Campo();
    else{
        list<OradiTennis*>::const_iterator next=l.begin();
        ++next;
        for(;cur!=l.end();++cur){
            if(next!=l.end()){
                if((*cur)->getOrario()<o && (*next)->getOrario()>o)
                    return Campo();
                if((*cur)->getOrario()==o && (*next)->getOrario()>o){
                    if((*cur)->getCampo().getNumero()<nCampi)
                        return ((*cur)->getCampo())+1;
                    else
                        throw QString("Nessun Campo Disponibile");
                }
                ++next;
            }
            else{
                if((*cur)->getOrario()<o)
                    return Campo();
                else{
                    if((*cur)->getCampo().getNumero()<nCampi)
                        return ((*cur)->getCampo())+1;
                    else
                        throw QString("Nessun Campo Disponibile");
                }
            }
        }
    }
}

void CalendarioGiornaliero::prenotaOra(Utente* u, Orario o) {
    Campo c;
        c=primoCampoDisponibile(o);
    OradiTennis* temp=0;
    if(dynamic_cast<Giocatore*>(u))
        temp=new Partita(u,c,o);
    else if(dynamic_cast<Maestro*>(u))
        temp=new Lezione(u,c,o);
    if(temp){
        list<OradiTennis*>::iterator cur=l.begin();
        if(nessunaPrenotazione() || (*cur)->getOrario()>o){  //crash a causa di cur->getOrario
            l.push_front(temp);
            return;
        }
        else{
            list<OradiTennis*>::iterator next=l.begin();
            ++next;
            bool inserito =false;
            for(;cur!=l.end() && !inserito;++cur){
                if(next!=l.end()){
                    if(((*cur)->getOrario()<o && (*next)->getOrario()>o) || ((*cur)->getOrario()==o && (*next)->getOrario()>o)){
                        l.insert(next,temp);
                        inserito=true;
                    }
                    ++next;
                }
            }
            if(!inserito)
                l.push_back(temp);
        }
    }
    else throw QString("Solo Giocatori o Maestri possono prenotare"); //o eventualmente altri sottotipi di Utente successivamente definiti
}

void CalendarioGiornaliero::scalaSuccessive(OradiTennis* o) {
    if(o){
        bool trovato=false;
        for(list<OradiTennis*>::iterator it=l.begin();it!=l.end();++it){
            if((*it)==o)
                trovato=true;
            if(trovato && (*it)->getOrario()==o->getOrario() && *it!=o)
                (*it)->scalaCampo();
            if(trovato && (*it)->getOrario()>o->getOrario())
                return;
        }
    }
}

void CalendarioGiornaliero::eliminaPrenotazione(OradiTennis* o){
    if(o){
        bool eliminato=false;
        list<OradiTennis*>::iterator it=l.begin();
        for(;it!=l.end() && !eliminato;++it){
            if(*it==o){
                scalaSuccessive(*it);
                delete *it;
                it=l.erase(it);
                --it;
                eliminato=true;
            }
        }
    }
}

void CalendarioGiornaliero::eliminaPartiteGiocatore(Utente* u) {
    if(u){
        list<OradiTennis*>::iterator it=l.begin();
        while(it!=l.end()){
            if(dynamic_cast<Giocatore*>((*it)->getUtente()) && (*it)->getUtente()->getUsername()==u->getUsername()){
                OradiTennis* temp=*it;
                it++;
                eliminaPrenotazione(temp);
            }
            else
                it++;
        }
    }
}

void CalendarioGiornaliero::eliminaTutteLezioni() {
    list<OradiTennis*>::iterator it=l.begin();
    while(it!=l.end()){
        if(dynamic_cast<Lezione*>(*it)){
            OradiTennis* temp=*it;
            ++it;
            eliminaPrenotazione(temp);
        }
        else
            ++it;
    }
}

int CalendarioGiornaliero::contaPartite() const {
    list<OradiTennis*>::const_iterator it=l.begin();
    int count=0;
    for(;it!=l.end();++it){
        if(dynamic_cast<Partita*>(*it))
            ++count;
    }
    return count;
}

int CalendarioGiornaliero::contaLezioni() const {
    list<OradiTennis*>::const_iterator it=l.begin();
    int count=0;
    for(;it!=l.end();++it){
        if(dynamic_cast<Lezione*>(*it))
            ++count;
    }
    return count;
}

double CalendarioGiornaliero::guadagnoGiornaliero() const {
    list<OradiTennis*>::const_iterator it=l.begin();
    double temp=0.00;
    for(;it!=l.end();++it){
        temp+=(*it)->prezzo();
    }
    return temp;
}

void CalendarioGiornaliero::clear(){
    for(list<OradiTennis*>::iterator it=l.begin();it!=l.end();++it){
        delete *it;
        it=l.erase(it);
        --it;
    }
}

void CalendarioGiornaliero::sostiuisciMaestro(Utente * p, Utente * s){
    if(p && s){
        for(list<OradiTennis*>::iterator it=l.begin();it!=l.end();++it){
            Lezione* temp=dynamic_cast<Lezione*>(*it);
            if((*it)->getUtente()->getUsername()==p->getUsername() && temp)
                temp->setMaestro(s);
        }
    }
}
