#ifndef GIOCATORE_H
#define GIOCATORE_H

#ifndef AZIONIGIOCATORE_H
#define AZIONIGIOCATORE_H

#include <utente.h>

class Giocatore: public Utente{
protected:
	class azioniGiocatore: public azioni{
		virtual void prenota (Utente*, orario) const;
		virtual void elimina (Utente*, orario) const;
		virtual ~Giocatore();
	};
public:
	~Giocatore();
	Giocatore(Qstring, Qstring="12345");

};

#endif // AZIONIGIOCATORE_H
#endif // GIOCATORE_H