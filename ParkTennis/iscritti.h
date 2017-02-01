#ifndef ISCRITTI_H
#define ISCRITTI_H

#include <list>
#include <utente.h>
#include <giocatore.h>
#include <maestro.h>
#include <admin.h>
using std::list;

class Iscritti{
private:
	list<Utente*> l;
    void clear();
    Utente* trovaMaestroDiverso(Utente*)const;
public:
	Iscritti();
    ~Iscritti();
	void iscrivi(Utente*);
    void iscriviGiocatore(QString& ,QString& );
    void iscriviMaestro(QString& ,QString& );
    //altre iscrivi se vengono aggiunti altri sottotipi di Utente
	void eliminaUtente(Utente*);
    void eliminaUtente(QString);  //per comodita
    Utente* trovaUtente(QString) const;
	list<Utente*> trovaMaestri() const;
    int contaMaestri() const;
};

#endif // ISCRITTI_H
