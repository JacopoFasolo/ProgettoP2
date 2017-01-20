#ifndef ISCRITTI_H
#define ISCRITTI_H

#include <list>
#include <Utente.h>
using std::list;

class Iscritti{
private:
	list<Utente*> l;
public:
	void iscrivi(Utente*);
	Utente* trovaUtente(Qstring) const;


}

#endif // ISCRITTI_H