#include <iscritti.h>

Iscritti::Iscritti(){l.push_back(new Admin());}

void Iscritti::iscrivi(Utente* u){
    if(u && !trovaUtente(u->getUsername()) && !dynamic_cast<Admin*>(u))
        l.push_back(u);
    else
        throw QString("Errore Iscrizione");
}

void Iscritti::iscriviGiocatore(QString& u,QString& p){
    if(!trovaUtente(u))
        iscrivi(new Giocatore(u,p));
}

void Iscritti::iscriviMaestro(QString& u,QString& p){
    if(!trovaUtente(u))
        iscrivi(new Maestro(u,p));
}

void Iscritti::eliminaUtente(Utente* u){
    if(u){
        if(dynamic_cast<Admin*>(u))
            throw QString("Non è possible eliminare Admin");
        bool eliminato=false;
        for(list<Utente*>::iterator it=l.begin();it!=l.end() && !eliminato;++it){
            if((*it)->getUsername()==u->getUsername()){
                delete (*it);
                l.erase(it);
                eliminato=true;
            }
        }
        if(!eliminato)
            throw QString("utente non iscritto");
    }
}


void Iscritti::eliminaUtente(QString ut){
    Utente* u=trovaUtente(ut);
    eliminaUtente(u);
}





Utente* Iscritti::trovaUtente(QString u) const{  //c++11
	bool trovato=false;
    for(list<Utente*>::const_iterator it=l.begin();it!=l.end() && !trovato;++it){
        if((*it)->getUsername()==u){
			return *it;
			trovato=true;
		}
	}
    return 0;
}

list<Utente*> Iscritti::trovaMaestri() const{  //c++11
	list<Utente*> temp;
    for(list<Utente*>::const_iterator it=l.begin();it!=l.end();++it){
        if(dynamic_cast<const Maestro*>(*it))
			temp.push_back(*it);
	}
	return temp;
}

int Iscritti::contaMaestri() const{  //c++11
    int count=0;
    for(list<Utente*>::const_iterator it=l.begin();it!=l.end();++it){
        if(dynamic_cast<const Maestro*>(*it))
            count++;
    }
    return count;
}
