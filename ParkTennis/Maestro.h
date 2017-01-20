#ifndef MAESTRO_H
#define MAESTRO_H

#ifndef AZIONIMAESTRO_H
#define AZIONIMAESTRO_H

#include <utente.h>

class Maestro: public Utente{
protected:
	class azioniMaestro:public azioni{
	public:
		virtual void prenota(Utente*, orario) const;
    	virtual void elimina(Utente*, orario) const;
    	virtual ~azioni();
    };
public:
	Maestro(Qstring,Qstring="12345");
	~Maestro();

};

#endif // AZIONIMAESTRO_H
#endif // MAESTRO_H