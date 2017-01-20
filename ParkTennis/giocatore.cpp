virtual void Giocatore::azioniGiocatore::prenota (Utente* u, orario o) const{  //DA COMPLETARE

}

virtual void Giocatore::azioniGiocatore::elimina (Utente* u, orario o) const{  //DA COMPLETARE

}

virtual Giocatore::azioniGiocatore::~azioniGiocatore()=default; //c++11

virtual Giocatore::~Giocatore()=default;  //c++11

Giocatore::Giocatore(Qstring u, Qstring p):Utente(u,p), az(new azioniGiocatore){};