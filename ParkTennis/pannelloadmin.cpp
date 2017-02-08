#include "pannelloadmin.h"

PannelloAdmin::PannelloAdmin(PannelloUtente *parent) : PannelloUtente(parent)
{
    //sezion prenota
    lblPrenota->setText("Prenota per Utente");
    lblPrenota->setGeometry(15,8,170,20);
    lnePrenota=new QLineEdit(frmPrenota);
    lnePrenota->setGeometry(15,15,140,30);
    frmPrenota->setGeometry(15,30,170,140);
    lblPrenotaOrario->setGeometry(15,65,60,20);
    spnPrenota->setGeometry(80,63,60,25);
    btnPrenota->setGeometry(15,95,140,30);

    //sezione elimina
    lblElimina->setGeometry(15,180,170,20);
    frmElimina->setGeometry(15,205,170,130);

    //sezione statistiche
    lblStat->setGeometry(15,340,170,20);
    frmStat->setGeometry(15,365,170,130);
    lblGuadagno=new QLabel("Guadagno :",frmStat);
    lblGuadagno->setGeometry(15,10,140,20);
    lneGuadagno=new QLineEdit(frmStat);
    lneGuadagno->setGeometry(15,32,140,25);
    lneGuadagno->setText(QString::number(CircoloTennistico::c->guadagnoGiornaliero()));
    lblCountPartite->setText("N Partite");
    lblCountPartite->setGeometry(15,65,80,20);
    lneCountPartite->setGeometry(100,63,55,25);
    lblCountLezioni->setText("N Lezioni");
    lblCountLezioni->setGeometry(15,95,80,20);
    lneCountLezioni->setGeometry(100,93,55,25);

    //sezione disiscrivi/logout
    lneDisiscrivi=new QLineEdit(this);
    lneDisiscrivi->setGeometry(15,505,170,30);
    btnDisiscriviti->setGeometry(15,545,170,30);
    btnDisiscriviti->setText("Disiscrivi");
}

void PannelloAdmin::btnPrenotaclicked(){
    if(lnePrenota->text().isEmpty())
        QMessageBox::critical(this,"Errore Prenotazione","Selezionare un Utente");
    else{
        Utente* u=CircoloTennistico::i->trovaUtente(lnePrenota->text());
        try{
            CircoloTennistico::c->prenotaOra(u,spnPrenota->value());
            lneCountPartite->setText(QString::number(CircoloTennistico::c->contaPartite()));
            lneCountLezioni->setText(QString::number(CircoloTennistico::c->contaLezioni()));
            lneGuadagno->setText(QString::number(CircoloTennistico::c->guadagnoGiornaliero()));
            aggiornaTabella();
            QMessageBox::information(this,"Prenotazione Effettutata","Prenotazione effettuata con Successo");
        }
        catch(QString x){
        QMessageBox::critical(this,"Errore Prenotazione",x);
        }
    }
}

void PannelloAdmin::btnEliminaclicked(){
    Orario o=spnEliminaOrario->value();
    Campo c=spnEliminaCampo->value();
    try{
        CircoloTennistico::c->AdminEliminaPrenotazione(o,c);
        lneCountPartite->setText(QString::number(CircoloTennistico::c->contaPartite()));
        lneCountLezioni->setText(QString::number(CircoloTennistico::c->contaLezioni()));
        lneGuadagno->setText(QString::number(CircoloTennistico::c->guadagnoGiornaliero()));
        QMessageBox::information(this,"Prenotazione Eliminata","Prenotazione Eliminata con Successo");
        aggiornaTabella();
    }
    catch(QString x){
        QMessageBox::critical(this,"Errore eliminazione",x);
    }
}

void PannelloAdmin::btnDisiscriviticlicked(){
    if(lneDisiscrivi->text().isEmpty())
        QMessageBox::critical(this,"Errore Disiscrizione","Selezionare un Utente");
    else{
        Utente* u=CircoloTennistico::i->trovaUtente(lneDisiscrivi->text());
        try{
            CircoloTennistico::eliminaIscrizione(u);
            aggiornaTabella();
            lneCountPartite->setText(QString::number(CircoloTennistico::c->contaPartite()));
            lneCountLezioni->setText(QString::number(CircoloTennistico::c->contaLezioni()));
            lneGuadagno->setText(QString::number(CircoloTennistico::c->guadagnoGiornaliero()));
            QMessageBox::information(this,"Disiscrizione Riuscita","Disiscrizione effettuata con Successo");
        }
        catch(QString x){
            QMessageBox::critical(this,"Errore",x);
        }
    }
}



