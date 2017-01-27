#ifndef ADMIN_H
#define ADMIN_H

#include <utente.h>

class Admin: public Utente{     //esiste un solo admin creato la prima volta con la costruzione di Iscritti
friend class Iscritti;
private:
    Admin(QString u ="Admin", QString p ="12345");
    ~Admin();
    Admin(const Admin&);
};

#endif // ADMIN_H
