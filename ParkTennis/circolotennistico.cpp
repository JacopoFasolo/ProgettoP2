#include "circolotennistico.h"

CircoloTennistico::CircoloTennistico():loggedIn(0){}

void CircoloTennistico::tryLogIn(QString u,QString p){
    Utente* ut=i.trovaUtente(u);
    if(ut->getPassword()==p){
        loggedIn=ut;
        return;
    }
    else
        throw QString("Password Errata");
    throw QString("Credenziali Errate");

}

