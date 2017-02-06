#include "pannelloutente.h"

PannelloUtente::PannelloUtente(QWidget *parent) : QWidget(parent)
{

    QTimer* timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    setFixedSize(900,630);
    move(250,80);
    setWindowTitle("Pannello Utente");

    //sezione prenota
    lblPrenota=new QLabel("Prenota",this);
    lblPrenota->setGeometry(15,8,170,20);
    frmPrenota=new QFrame(this);
    frmPrenota->setGeometry(15,30,170,100);
    frmPrenota->setFrameShadow(QFrame::Raised);
    frmPrenota->setFrameShape(QFrame::StyledPanel);
    lblPrenotaOrario=new QLabel("Orario :",frmPrenota);
    lblPrenotaOrario->setGeometry(15,15,50,20);
    spnPrenota=new QSpinBox(frmPrenota);
    spnPrenota->setGeometry(80,12,75,25);
    spnPrenota->setRange(CircoloTennistico::c->getApertura().getOra(),CircoloTennistico::c->getUltimaOra().getOra());
    btnPrenota=new QPushButton(tr("Prenota"),frmPrenota);
    btnPrenota->setGeometry(15,55,140,30);
    btnPrenota->setCursor(QCursor(Qt::PointingHandCursor));

    //sezione statistiche
    lblStat=new QLabel("Statistiche",this);
    lblStat->setGeometry(15,150,170,20);
    frmStat=new QFrame(this);
    frmStat->setGeometry(15,175,170,150);
    frmStat->setFrameShadow(QFrame::Raised);
    frmStat->setFrameShape(QFrame::StyledPanel);
    lblCountPartite=new QLabel("Numero Partite :",frmStat);
    lblCountPartite->setGeometry(15,15,140,20);
    lneCountPartite=new QLineEdit(frmStat);
    lneCountPartite->setGeometry(15,40,140,30);
    lblCountLezioni=new QLabel("Numero Lezioni :",frmStat);
    lblCountLezioni->setGeometry(15,80,140,20);
    lneCountLezioni=new QLineEdit(frmStat);
    lneCountLezioni->setGeometry(15,105,140,30);

    //sezione logout disiscriviti
    btnDisiscriviti=new QPushButton(tr("Disiscriviti"),this);
    btnDisiscriviti->setGeometry(15,540,170,32);
    btnDisiscriviti->setCursor(QCursor(Qt::PointingHandCursor));
    btnLogOut=new QPushButton(tr("Log Out"),this);
    btnLogOut->setGeometry(15,585,170,30);
    btnLogOut->setCursor(QCursor(Qt::PointingHandCursor));

    //sezione orario
    lblOrario=new QLabel("Orario :",this);
    lblOrario->setGeometry(825,8,60,20);
    lcdOrario=new QLCDNumber(this);
    lcdOrario->setGeometry(735,30,150,30);
    lcdOrario->setDigitCount(8);
    lcdOrario->setSegmentStyle(QLCDNumber::Flat);

    //tabella
    tblPrenotazioni=new QTableWidget(this);
    tblPrenotazioni->setGeometry(200,70,685,544);

}

void PannelloUtente::showTime(){
    QTime time= QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    lcdOrario->display(time_text);
}

