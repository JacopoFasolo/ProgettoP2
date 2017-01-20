#include <Iscritti.h>

void Iscritti::iscrivi(Utente* u){
	l.push_back(u);
}

void Iscritti::eliminaUtente(Utente* u){
	bool eliminato=false;
	for(auto it=l.begin();it!=l.end() && !eliminato;++it){
		if((*it)->getUsername()==u.getUsername()){
			if(dynamic_cast<Admin*>(*it))
				throw Qstring("Non è possible eliminare Admin")
			else{
				delete (*it);
				it=l.erase(it);
				eliminato=true;
			}
		}
	}
	if(!eliminato)
		throw Qstring("utente non iscritto")
}


void Iscritti::eliminaUtente(Qstring u){
	bool eliminato=false;
	for(auto it=l.begin();it!=l.end() && !eliminato;++it){
		if((*it)->getUsername()==u){
			if(dynamic_cast<Admin*>(*it))
				throw Qstring("Non è possible eliminare Admin")
			else{
				delete (*it);
				it=l.erase(it);
				eliminato=true;
			}
		}
	}
	if(!eliminato)
		throw Qstring("utente non iscritto")
}




Utente* Iscritti::trovaUtente(Qstring u) const{  //c++11
	bool trovato=false;
	for(auto it=l.begin();it!=l.end() && !trovato;++it){
		if((*it)->getUsername()==u;)
			return *it;
	}
	return nullptr;
}

list<Utente*> Iscritti::trovaMaestri() const{  //c++11
	list<Utente*> temp;
	for(auto it=l.begin();it!=l.end() && !trovato;++it){
		if(dynamic_cast<Maestro*>(*it))
			temp.push_back(*it);
	}
	return temp;
}

}