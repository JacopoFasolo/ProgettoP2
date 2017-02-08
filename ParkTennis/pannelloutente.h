#ifndef PANNELLOUTENTE_H
#define PANNELLOUTENTE_H

#include "circolotennistico.h"
#include <QWidget>
#include <QLCDNumber>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTableWidget>
#include <QWidget>
#include <QFrame>
#include <QTimer>
#include <QMessageBox>
#include <QHeaderView>
#include <QDialog>

class PannelloUtente : public QDialog
{
    Q_OBJECT
public:
    explicit PannelloUtente(QDialog* parent = 0);

signals:

protected:
    QFrame* frmPrenota;
    QLabel* lblPrenota;
    QSpinBox* spnPrenota;
    QPushButton* btnPrenota;
    QLabel* lblPrenotaOrario;

    QLabel* lblElimina;
    QFrame* frmElimina;
    QLabel* lblEliminaOrario;
    QSpinBox* spnEliminaOrario;
    QLabel* lblEliminaCampo;
    QSpinBox* spnEliminaCampo;
    QPushButton* btnElimina;

    QLabel* lblStat;
    QFrame* frmStat;
    QLineEdit* lneCountPartite;
    QLineEdit* lneCountLezioni;
    QLabel* lblCountPartite;
    QLabel* lblCountLezioni;

    QPushButton* btnDisiscriviti;
    QPushButton* btnLogOut;

    QTableWidget* tblPrenotazioni;

    QLabel* lblOrario;
    QLCDNumber* lcdOrario;

public slots:
    void showTime();
    virtual void btnPrenotaclicked();
    virtual void btnEliminaclicked();
    virtual void btnDisiscriviticlicked();
    void btnLogOutclicked();
    void aggiornaTabella();
    void setuptblPrenotazioni();
};

#endif // PANNELLOUTENTE_H
