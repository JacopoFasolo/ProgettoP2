#ifndef UTENTE_H
#define UTENTE_H

#ifndef AZIONI_H
#define AZIONI_H

#include <Qstring>
#include <calendarioGiornaliero>

class Utente
{
protected:
 	class azioni{
 	public:
 		virtual void prenota(Utente*, orario) const =0;
    	virtual void elimina(Utente*, orario) const =0;
    	virtual ~azioni() =0;
    };
    azioni* az;
private:
    Qstring Username;
    Qstring Password;
public:
    Utente(Qstring, Qstring="12345");
    virtual ~Utente()=0;
    Qstring getUsername() const;
    Qstring getPassword() const;

};

#endif // AZIONI_H
#endif // UTENTE_H
