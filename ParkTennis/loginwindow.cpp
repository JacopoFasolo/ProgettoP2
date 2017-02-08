#include "loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(300,400);
    move(500,150);
    setWindowTitle("ParkTennis - Login");

    txtUsername=new QLineEdit("Username",this);
    txtPassword=new QLineEdit("Password",this);
    btnAccedi=new QPushButton(tr("Accedi"),this);
    btnRegistrati=new QPushButton(tr("Registrati"),this);
    btnClear=new QPushButton(tr("Resetta"),this);
    rbGiocatore= new QRadioButton("Giocatore",this);
    rbMaestro= new QRadioButton("Maestro",this);
    Autore=new QLabel(QString("<font color='black'>Jacopo Fasolo - 1099278</font>"),this);

    txtUsername->setGeometry(30,100,240,35);
    txtPassword->setGeometry(30,150,240,35);
    txtPassword->setEchoMode(QLineEdit::Password);
    btnClear->setGeometry(200,190,70,20);
    btnAccedi->setGeometry(45,230,210,35);
    btnRegistrati->setGeometry(45,280,210,35);
    rbGiocatore->setGeometry(45,320,100,15);
    rbGiocatore->setChecked(true);
    rbMaestro->setGeometry(165,320,100,15);
    Autore->setGeometry(60,370,180,25);
    connect(btnClear,SIGNAL(clicked()),txtUsername,SLOT(clear()));
    connect(btnClear,SIGNAL(clicked()),txtPassword,SLOT(clear()));
    connect(btnAccedi,SIGNAL(clicked()),this,SLOT(testLogin()));
    connect(btnRegistrati,SIGNAL(clicked()),this,SLOT(Registra()));
}

LoginWindow::~LoginWindow(){}

void LoginWindow::testLogin() {
    try{
        QString u=txtUsername->text();
        QString p=txtPassword->text();
        CircoloTennistico::tryLogIn(u,p);
        //devo chiamare
        //QMessageBox::information(0,"OK","Andata Bene");
        PannelloUtente* pu=new PannelloUtente();
        pu->show();
    }
    catch(QString x){
        QMessageBox::critical(0,"Errore Login",x);
    }
}

void LoginWindow::Registra() {
    try{
        QString u=txtUsername->text();
        QString p=txtPassword->text();
        if(rbGiocatore->isChecked())
            CircoloTennistico::iscriviGiocatore(u,p);
        else if(rbMaestro->isChecked())
            CircoloTennistico::iscriviMaestro(u,p);
        testLogin();
    }
    catch(QString x){
        QMessageBox::critical(0,"Errore Registrazione",x);
    }
}
