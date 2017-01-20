#ifndef ADMIN_H
#define ADMIN_H

#ifndef AZIONIADMIN_H
#define AZIONIADMIN_H

#include <utente.h>

class Admin: public Utente{
protected:
	class azioniAdmin:azioni{
		virtual void prenota(Utente*, orario) const;
    	virtual void elimina(Utente*, orario) const;
    	virtual ~azioni();
	}
public:
	Admin(Qstring,Qstring="12345");
	~Admin();

};

#endif // AZIONIADMIN_H
#endif // ADMIN_H