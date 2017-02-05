#include "utente.h"

Utente::Utente(QString u, QString p):Username(u), Password(p){}

Utente::~Utente(){}

QString Utente::getUsername() const {return Username;}

QString Utente::getPassword() const {return Password;}
