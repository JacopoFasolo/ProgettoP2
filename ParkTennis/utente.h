#ifndef UTENTE_H
#define UTENTE_H

#include <QString>
#include <orario.h>

class Utente
{
private:
    QString Username;
    QString Password;
public:
    Utente(QString, QString="12345");
    virtual ~Utente()=0;
    QString getUsername() const;
    QString getPassword() const;
};

#endif // UTENTE_H
