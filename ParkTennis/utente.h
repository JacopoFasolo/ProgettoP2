#ifndef UTENTE_H
#define UTENTE_H

#include <Qstring>


class Utente
{
private:
    Qstring Username;
    Qstring Password;
public:
    Utente(Qstring, Qstring="12345");
    Utente(const Utente&);
    virtual ~Utente()=0;
    Qstring getUsername() const;
    Qstring getPassword() const;

};

#endif // UTENTE_H
