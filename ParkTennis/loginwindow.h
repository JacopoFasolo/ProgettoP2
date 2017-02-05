#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <circolotennistico.h>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QRadioButton>

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
    Ui::LoginWindow *ui;
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
