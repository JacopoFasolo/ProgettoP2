#ifndef PANNELLOADMIN_H
#define PANNELLOADMIN_H

#include <pannelloutente.h>

class PannelloAdmin : public PannelloUtente
{
    Q_OBJECT

protected:
    QLineEdit* lnePrenota;

    QLabel* lblGuadagno;
    QLineEdit* lneGuadagno;

    QLineEdit* lneDisiscrivi;
public:
    explicit PannelloAdmin(PannelloUtente* parent = 0);

signals:

public slots:
    virtual void btnPrenotaclicked();
    virtual void btnEliminaclicked();
    virtual void btnDisiscriviticlicked();
};

#endif // PANNELLOADMIN_H
