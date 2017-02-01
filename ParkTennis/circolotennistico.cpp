#include "circolotennistico.h"

CircoloTennistico::CircoloTennistico():loggedIn(0){}

Iscritti CircoloTennistico::i=Iscritti();

void CircoloTennistico::tryLogIn(QString u,QString p){
    Utente* ut=i.trovaUtente(u);
    if(ut && ut->getPassword()==p){
        loggedIn=ut;
        return;
    }
    throw QString("Errore Autenticazione");

}

