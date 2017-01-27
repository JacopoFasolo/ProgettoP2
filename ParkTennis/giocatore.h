#ifndef GIOCATORE_H
#define GIOCATORE_H

#include <utente.h>

class Giocatore: public Utente{
public:
    virtual ~Giocatore();
    Giocatore(QString, QString="12345");

};

#endif // GIOCATORE_H
