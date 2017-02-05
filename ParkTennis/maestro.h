#ifndef MAESTRO_H
#define MAESTRO_H

#include <utente.h>

class Maestro: public Utente{
public:
    Maestro(QString,QString="12345");
    virtual ~Maestro();
};

#endif // MAESTRO_H
