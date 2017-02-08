#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <circolotennistico.h>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QRadioButton>
#include <pannelloutente.h>
#include <pannellogiocatore.h>
#include <pannellomaestro.h>
#include <pannelloadmin.h>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    QLineEdit* txtUsername;
    QLineEdit* txtPassword;
    QPushButton* btnAccedi;
    QPushButton* btnRegistrati;
    QPushButton* btnClear;
    QRadioButton* rbGiocatore;
    QRadioButton* rbMaestro;
    QLabel* Autore;


public slots:
    void testLogin();
    void Registra();

};

#endif // LOGINWINDOW_H
