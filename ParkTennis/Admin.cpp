#include <admin.h>

void Admin::azioniAdmin::prenota(Utente* u, orario o) const{  //DA COMPLETARE

}

void Admin::azioniAdmin::elimina(Utente* u, orario o) const{  //DA COMPLETARE

}

Admin::azioniAdmin::~azioniAdmin()=default;  //c++11

Admin::~Admin()= default;  //c++11

Admin::Admin(Qstring u,Qstring p):Utente(u,p),az(new azioniAdmin){};