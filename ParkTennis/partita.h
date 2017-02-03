#ifndef PARTITA_H
#define PARTITA_H

#include <oraditennis.h>


class Partita: public OradiTennis {
public:
    Partita(Utente*, Campo =Campo(), Orario =Orario());
    ~Partita(){};
};

#endif // PARTITA_H
