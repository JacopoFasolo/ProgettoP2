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

class PannelloUtente : public QWidget
{
    Q_OBJECT
public:
    explicit PannelloUtente(QWidget* parent = 0);

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
    void btnPrenotaclicked();
    void btnEliminaclicked();
    void btnDisiscriviticlicked();
    void btnLogOutclicked();
    void aggiornaTabella();
};

#endif // PANNELLOUTENTE_H
