#include "circolotennistico.h"

Iscritti* CircoloTennistico::loadIscrizioni(){
    QDomDocument documento;
    QFile file("iscritti.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Failed to open the file for reading.";
    else{
        if(!documento.setContent(&file))
            qDebug() << "Failed to load the file for reading.";
        file.close();
    }
    QDomElement root = documento.firstChildElement();
    QDomNodeList users = root.elementsByTagName("Utente");
    Iscritti* temp=new Iscritti; //già presente l'admin per costruzioine di default
    for (int i=0; i<users.count(); i++){
        QDomNode nodo = users.at(i);
        QDomElement utente = nodo.toElement();
        if (utente.attribute("tipo")!="Admin"){
            if (utente.attribute("tipo")=="Giocatore")
                temp->iscrivi(new Giocatore(utente.attribute("Username"),utente.attribute("Password")));
            if (utente.attribute("tipo")=="Maestro")
                temp->iscrivi(new Maestro(utente.attribute("Username"),utente.attribute("Password")));

            //altri if in base al tipo

        }
    }
    return temp;
}


Iscritti* CircoloTennistico::i=loadIscrizioni();

Utente* CircoloTennistico::loggedIn=0;

CalendarioGiornaliero* CircoloTennistico::loadPrenotazioni(){  // da chiamare dopo che è stata invocata loadIscritti sennò non saranno presenti Utenti iscritti a cui
    QDomDocument documento;
    QFile file("prenotazioni.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Failed to open the file for reading.";
    else{
        if(!documento.setContent(&file))
            qDebug() << "Failed to load the file for reading.";
        file.close();
    }
    QDomElement root = documento.firstChildElement();
    QDomNodeList pren = root.elementsByTagName("Ora");
    CalendarioGiornaliero* temp=new CalendarioGiornaliero;
    for (int i=0; i<pren.count(); i++){
        QDomNode nodo = pren.at(i);
        QDomElement p = nodo.toElement();
        QString un=p.attribute("Nominativo");
        Utente* us=CircoloTennistico::i->trovaUtente(un);
        if(us)
            temp->prenotaOra(us,Orario(p.attribute("Orario").toInt()));
    }
    return temp;
}

CalendarioGiornaliero* CircoloTennistico::c=loadPrenotazioni();

void CircoloTennistico::tryLogIn(QString u,QString p){
    Utente* ut=i->trovaUtente(u);
    if(ut && ut->getPassword()==p){
        loggedIn=ut;
        return;
    }
    throw QString("Errore Autenticazione");
}

void CircoloTennistico::saveIscritti(Iscritti* is) const {
    QFile file("iscritti.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Failed to open the file.";
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("Iscritti");
    for(list<Utente*>::iterator it=is->l.begin();it!=is->l.end();++it){
        writer.writeStartElement("Utente");
        if(dynamic_cast<Admin*>(*it))
            writer.writeAttribute("tipo","Admin");
        if(dynamic_cast<Giocatore*>(*it))
            writer.writeAttribute("tipo","Giocatore");
        if(dynamic_cast<Maestro*>(*it))
        //da aggiungere eventuali altri sottotipi di Utente
            writer.writeAttribute("tipo","Maestro");
        writer.writeAttribute("Username",(*it)->getUsername());
        writer.writeAttribute("Password",(*it)->getPassword());
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
}

void CircoloTennistico::savePrenotazioni(CalendarioGiornaliero* cal) const{
    QFile file("prenotazioni.xml");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug() << "Failed to open the file.";
    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument("1.0");
    writer.writeStartElement("Prenotazioni");
    for(list<OradiTennis*>::iterator it=cal->l.begin();it!=cal->l.end();++it){
        writer.writeStartElement("Ora");
        if(dynamic_cast<Partita*>(*it))
            writer.writeAttribute("tipo","Partita");
        if(dynamic_cast<Lezione*>(*it))
            writer.writeAttribute("tipo","Lezione");
        //da aggiungere eventuali altri sottotipi di OraDiTennis
        QString c=QString::number((*it)->getCampo().getNumero());
        QString o=QString::number((*it)->getOrario().getOra());
        writer.writeAttribute("Nominativo",(*it)->getUtente()->getUsername());
        writer.writeAttribute("Orario",o);
        writer.writeAttribute("Campo",c);
        writer.writeEndElement();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
}

CircoloTennistico::~CircoloTennistico(){
    loggedIn=0;
    saveIscritti(i);
    savePrenotazioni(c);
    //richiama inplicitamente i distruttori ridefiniti di Iscritti e CalendarioGiornaliero
}

void CircoloTennistico::iscriviGiocatore(QString u,QString p){
    i->iscrivi(new Giocatore(u,p));
}

void CircoloTennistico::iscriviMaestro(QString u,QString p){
    i->iscrivi(new Maestro(u,p));
}

void CircoloTennistico::eliminaIscrizione(Utente* u){
    if(u){
        if(dynamic_cast<Admin*>(u))
            throw QString("Admin non eliminabile");
        if(u==loggedIn)
            loggedIn=0;
        if(dynamic_cast<Maestro*>(u)){  // un maestro quando si disiscrive lascia le lezioni che aveva a carico ai colleghi maestri ancora iscritti, se è l'ultimo maestro rimanente annullo tutte le lezioni
            if(i->contaMaestri()==1){
                c->eliminaTutteLezioni();
                qDebug()<<"flag";
            }
            else{
                Utente* temp=i->trovaMaestroDiverso(u); //ho almeno 1 maestro a cui affidare le lezioni da coprire
                c->sostiuisciMaestro(u,temp);
            }
            i->eliminaUtente(u);
        }
        else if(dynamic_cast<Giocatore*>(u)){  //un giocatore quando si disiscrive annulla automaticamente le partite che aveva prenotato a suo nome
            c->eliminaPartiteGiocatore(u);
            i->eliminaUtente(u);
        }
        //altri if per evenuali altri tipi derivati da utente successivamente difiniti
    }
}

void CircoloTennistico::Prenota(Orario o){
    c->prenotaOra(loggedIn,o);
}

void CircoloTennistico::scorri() const {
    for(list<Utente*>::const_iterator it=i->l.begin();it!=i->l.end();++it)
        qDebug()<<(*it)->getUsername();
}

void CircoloTennistico::inizioGiornata(){
    c->clear();
}

