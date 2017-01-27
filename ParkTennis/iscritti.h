#ifndef ISCRITTI_H
#define ISCRITTI_H

#include <list>
#include <utente.h>
#include <giocatore.h>
#include <maestro.h>
#include <admin.h>
using std::list;

class Iscritti{
friend class Utente;
friend class Giocatore;
friend class Maestro;
friend class Admin;
private:
	list<Utente*> l;
public:
	Iscritti();
	void iscrivi(Utente*);
    void iscriviGiocatore(QString& ,QString& );
    void iscriviMaestro(QString& ,QString& );
	void eliminaUtente(Utente*);
    void eliminaUtente(QString);
    Utente* trovaUtente(QString) const;
	list<Utente*> trovaMaestri() const;
    int contaMaestri() const;


};

#endif // ISCRITTI_H
