#include "pannelloutente.h"

PannelloUtente::PannelloUtente(QDialog *parent) : QDialog(parent)
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
    connect(btnPrenota,SIGNAL(clicked()),this,SLOT(btnPrenotaclicked()));

    //sezione elimina
    lblElimina=new QLabel("Elimina Prenotazione",this);
    lblElimina->setGeometry(15,145,170,20);
    frmElimina=new QFrame(this);
    frmElimina->setGeometry(15,170,170,130);
    frmElimina->setFrameShadow(QFrame::Raised);
    frmElimina->setFrameShape(QFrame::StyledPanel);
    lblEliminaOrario=new QLabel("Orario :",frmElimina);
    lblEliminaOrario->setGeometry(15,15,60,20);
    spnEliminaOrario=new QSpinBox(frmElimina);
    spnEliminaOrario->setGeometry(80,13,75,25);
    spnEliminaOrario->setRange(CircoloTennistico::c->getApertura().getOra(),CircoloTennistico::c->getUltimaOra().getOra());
    lblEliminaCampo=new QLabel("Campo :",frmElimina);
    lblEliminaCampo->setGeometry(15,50,60,20);
    spnEliminaCampo=new QSpinBox(frmElimina);
    spnEliminaCampo->setGeometry(80,48,75,25);
    spnEliminaCampo->setRange(1,CircoloTennistico::c->getNumCampi());
    btnElimina=new QPushButton(tr("Eimina"),frmElimina);
    btnElimina->setGeometry(15,83,140,30);
    btnElimina->setCursor(QCursor(Qt::PointingHandCursor));
    connect(btnElimina,SIGNAL(clicked()),this,SLOT(btnEliminaclicked()));


    //sezione statistiche
    lblStat=new QLabel("Statistiche",this);
    lblStat->setGeometry(15,360,170,20);
    frmStat=new QFrame(this);
    frmStat->setGeometry(15,385,170,140);
    frmStat->setFrameShadow(QFrame::Raised);
    frmStat->setFrameShape(QFrame::StyledPanel);
    lblCountPartite=new QLabel("Numero Partite :",frmStat);
    lblCountPartite->setGeometry(15,10,140,20);
    lneCountPartite=new QLineEdit(frmStat);
    lneCountPartite->setGeometry(15,35,140,30);
    lblCountLezioni=new QLabel("Numero Lezioni :",frmStat);
    lblCountLezioni->setGeometry(15,70,140,20);
    lneCountLezioni=new QLineEdit(frmStat);
    lneCountLezioni->setGeometry(15,95,140,30);
    lneCountPartite->setText(QString::number(CircoloTennistico::c->contaPartite()));
    lneCountLezioni->setText(QString::number(CircoloTennistico::c->contaLezioni()));

    //sezione logout disiscriviti
    btnDisiscriviti=new QPushButton(tr("Disiscriviti"),this);
    btnDisiscriviti->setGeometry(15,540,170,32);
    btnDisiscriviti->setCursor(QCursor(Qt::PointingHandCursor));
    btnLogOut=new QPushButton(tr("Log Out"),this);
    btnLogOut->setGeometry(15,585,170,30);
    btnLogOut->setCursor(QCursor(Qt::PointingHandCursor));
    connect(btnDisiscriviti,SIGNAL(clicked()),this,SLOT(btnDisiscriviticlicked()));
    connect(btnLogOut,SIGNAL(clicked()),this,SLOT(btnLogOutclicked()));

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
    tblPrenotazioni->setColumnCount(5);
    setuptblPrenotazioni();
}

void PannelloUtente::showTime(){
    QTime time= QTime::currentTime();
    QString time_text=time.toString("hh:mm:ss");
    lcdOrario->display(time_text);
}

void PannelloUtente::btnPrenotaclicked(){
    if(CircoloTennistico::loggedIn && !dynamic_cast<Admin*>(CircoloTennistico::loggedIn)){
        try{
            Orario o=spnPrenota->value();
            CircoloTennistico::Prenota(o);
            lneCountPartite->setText(QString::number(CircoloTennistico::c->contaPartite()));
            lneCountLezioni->setText(QString::number(CircoloTennistico::c->contaLezioni()));
            aggiornaTabella();
            QMessageBox::information(this,"Prenotazione Effettutata","Prenotazione effettuata con Successo");
        }
        catch(QString x){
            QMessageBox::critical(this,"Errore Prenotazione",x);
        }
    }
}

void PannelloUtente::btnEliminaclicked(){
    if(CircoloTennistico::loggedIn && !dynamic_cast<Admin*>(CircoloTennistico::loggedIn)){
        Orario o=spnEliminaOrario->value();
        Campo c=spnEliminaCampo->value();
        try{
            CircoloTennistico::c->eliminaPrenotazione(CircoloTennistico::loggedIn,o,c);
            lneCountPartite->setText(QString::number(CircoloTennistico::c->contaPartite()));
            lneCountLezioni->setText(QString::number(CircoloTennistico::c->contaLezioni()));
            QMessageBox::information(this,"Prenotazione Eliminata","Prenotazione Eliminata con Successo");
            aggiornaTabella();
        }
        catch(QString x){
            QMessageBox::critical(this,"Errore eliminazione",x);
        }
    }
}

void PannelloUtente::btnDisiscriviticlicked(){
    CircoloTennistico::eliminaIscrizione(CircoloTennistico::loggedIn);
    close();
}

void PannelloUtente::btnLogOutclicked(){
    CircoloTennistico::loggedIn=0;
    close();
}

void PannelloUtente::aggiornaTabella(){
    if(!CircoloTennistico::c->nessunaPrenotazione()){
        tblPrenotazioni->setRowCount(0);
        for(list<OradiTennis*>::iterator it=CircoloTennistico::c->l.begin();it!=CircoloTennistico::c->l.end();++it){
            int count=tblPrenotazioni->rowCount();
            tblPrenotazioni->insertRow(count);
            if(dynamic_cast<Partita*>(*it))
                tblPrenotazioni->setItem(count,0,new QTableWidgetItem("Partita"));
            if(dynamic_cast<Lezione*>(*it))
                tblPrenotazioni->setItem(count,0,new QTableWidgetItem("Lezione"));
            //altri if in base al tipo
            tblPrenotazioni->setItem(count,1,new QTableWidgetItem((*it)->getUtente()->getUsername()));
            tblPrenotazioni->setItem(count,2,new QTableWidgetItem(QString::number((*it)->getOrario().getOra())));
            tblPrenotazioni->setItem(count,3,new QTableWidgetItem(QString::number((*it)->getCampo().getNumero())));
            if((*it)->getLuce())
                tblPrenotazioni->setItem(count,4, new QTableWidgetItem(QString("Attiva")));
        }
    }
    else
        tblPrenotazioni->setRowCount(0);
}

void PannelloUtente::setuptblPrenotazioni(){
    QStringList titoli;
    titoli<<"Tipo"<<"Username"<<"Ora"<<"Campo"<<"Luce";
    tblPrenotazioni->setHorizontalHeaderLabels(titoli);
    tblPrenotazioni->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    aggiornaTabella();

}

