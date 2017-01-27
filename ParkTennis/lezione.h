#ifndef LEZIONE_H
#define LEZIONE_H

#include <oraditennis.h>

class Lezione:public OradiTennis
{
private:
    static double quotaMaestro;
public:
    Lezione(Utente*, Campo =Campo(), orario =orario());
    static double getQuotaMaestro();
    ~Lezione(){}
};

#endif // LEZIONE_H
