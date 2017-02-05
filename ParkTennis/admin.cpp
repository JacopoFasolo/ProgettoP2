#include <admin.h>

Admin::Admin(QString u, QString p):Utente(u,p){}

Admin::~Admin(){}

Admin::Admin(const Admin& a):Utente(a.getUsername(),a.getPassword()){}
