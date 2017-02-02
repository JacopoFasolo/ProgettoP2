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

void CircoloTennistico::iscriviGiocatore(QString& u,QString& p){
    if(!i.trovaUtente(u))
        i.iscrivi(new Giocatore(u,p));
}

void CircoloTennistico::iscriviMaestro(QString& u,QString& p){
    if(!i.trovaUtente(u))
        i.iscrivi(new Maestro(u,p));
}

void CircoloTennistico::eliminaIscrizione(Utente* u){
    if(u){
        if(dynamic_cast<Admin*>(u))
            throw QString("Admin non eliminabile");
        if(dynamic_cast<Maestro*>(u)){  // un maestro quando si disiscrive lascia le lezioni che aveva a carico ai colleghi maestri ancora iscritti, se è l'ultimo maestro rimanente annullo tutte le lezioni
            if(i.contaMaestri()==1)
                c.eliminaTutteLezioni();
            Utente* temp=i.trovaMaestroDiverso(u); //ho almeno 1 maestro a cui affidare le lezioni da coprire
            c.sostiuisciMaestro(u,temp);
            i.eliminaUtente(u);
        }
        if(dynamic_cast<Giocatore*>(u)){  //un giocatore quando si disiscrive annulla automaticamente le partite che aveva prenotato a suo nome
            c.eliminaPartiteGiocatore(u);
            i.eliminaUtente(u);
        }
        //altri if per evenuali altri tipi derivati da utente successivamente difiniti
    }
}

