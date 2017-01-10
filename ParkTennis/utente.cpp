#include "utente.h"

Utente::Utente(Qstring u , Qstring p=):Username(u), Password(p){}

Utente::Utente(const Utente& u):Username(u.Username),Password(u.Password){}

Utente::getUsername() const {return Username;}

Utente::getPassword() const {return Password;}

