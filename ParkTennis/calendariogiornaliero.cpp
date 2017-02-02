#include "calendariogiornaliero.h"

orario CalendarioGiornaliero::apertura=8;

orario CalendarioGiornaliero::ultimaOraPrenotabile=23;

int CalendarioGiornaliero::nCampi=12;

orario CalendarioGiornaliero::getApertura(){return apertura;}

orario CalendarioGiornaliero::getUltimaOra(){return ultimaOraPrenotabile;}

int CalendarioGiornaliero::getNumCampi(){return nCampi;}

CalendarioGiornaliero::~CalendarioGiornaliero(){
    clear();
}

bool CalendarioGiornaliero::nessunaPrenotazione() const {
    return l.begin()==l.end();
}

Campo CalendarioGiornaliero::primoCampoDisponibile(orario o) const {
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

void CalendarioGiornaliero::prenotaOra(Utente* u, orario o) {
    Campo c;
        c=primoCampoDisponibile(o);
    OradiTennis* temp=0;
    if(dynamic_cast<Giocatore*>(u))
        temp=new Partita(static_cast<Giocatore*>(u),c,o);
    else if(dynamic_cast<Maestro*>(u))
        temp=new Lezione(static_cast<Maestro*>(u),c,o);
    if(temp){
        list<OradiTennis*>::iterator cur=l.begin();
        if(nessunaPrenotazione() || (*cur)->getOrario()>o){
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
            l.push_back(temp);
        }
    }
    else throw QString("Solo Giocatori o Maestri possono prenotare"); //o eventualmente altri sottotipi di Utente successivamente definiti
}

void CalendarioGiornaliero::scalaSuccessive(OradiTennis* o) {
    if(o){
        list<OradiTennis*>::iterator it=l.begin();
        bool trovato=true;
        for(;it!=l.end();++it){
            if((*it)==o)
                trovato=true;
            if(trovato && (*it)->getOrario()==o->getOrario() && *it!=o)
                (*it)->scalaCampo();
            if(trovato && (*it)->getOrario()==o->getOrario())
                trovato=false;
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
                delete*it;
                l.erase(it);
                eliminato=false;
            }
        }
    }
}

void CalendarioGiornaliero::eliminaPartiteGiocatore(Utente* u) {
    if(u){
        list<OradiTennis*>::iterator it=l.begin();
        for(;it!=l.end();++it){
            if(dynamic_cast<Giocatore*>((*it)->getUtente()) && (*it)->getUtente()->getUsername()==u->getUsername()){
                eliminaPrenotazione(*it);
            }
        }
    }
}

void CalendarioGiornaliero::eliminaTutteLezioni() {
    list<OradiTennis*>::iterator it=l.begin();
    for(;it!=l.end();++it){
        if(dynamic_cast<Lezione*>(*it)){
            delete *it;
            it=l.erase(it);
            --it;
        }
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
    for(;it!=l.end(); ){
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
