#include "utente.h"

Utente::Utente(Qstring u, Qstring p=):Username(u), Password(p),az(new azioni){}

Utente::getUsername() const {return Username;}

Utente::getPassword() const {return Password;}

