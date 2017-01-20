#include <maestro.h>

void Maestro::azioniMaestro::prenota(Utente* u, orario o) const{  //DA COMPLETARE

}

void Maestro::azioniMaestro::elimina(Utente* u, orario o) const{  //DA COMPLETARE

}

Maestro::azioniMaestro::~azioniMaestro()=default;  //c++11

Maestro::~Maestro()= default;  //c++11

Maestro::Maestro(Qstring u,Qstring p):Utente(u,p),az(new azioniMaestro){};