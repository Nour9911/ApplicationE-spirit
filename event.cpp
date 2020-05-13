#include "event.h"
#include "ui_event.h"
#include <QMessageBox>
#include "evenement.h"
#include "tournoi.h"
#include "match.h"
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

event::event(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::event)
{
    ui->setupUi(this);

    ui->table_eve->setModel(tmpevenement.afficher_evenement());
    ui->table_tour->setModel(tmptournoi.afficher_tour());
    ui->table_mat->setModel(tmpmatch.afficher_mat());





    QSqlQuery query;
    query.prepare("select Id_evenement from EVEN");
    if(query.exec())
        {
            while(query.next())
            {
                QString s = query.value(0).toString();//Récupère le résultat de la requête
                ui->combo_Id_evenement_2->addItem(s);


            }
        }
    query.prepare("select Idt from TOUR");
    if(query.exec())
        {
            while(query.next())
            {
                QString s = query.value(0).toString();//Récupère le résultat de la requête
                ui->combo_Idt_2->addItem(s);
                ui->combo_Idt_3->addItem(s);


            }
        }
    query.prepare("select Idm from MATCH");
    if(query.exec())
        {
            while(query.next())
            {
                QString s = query.value(0).toString();//Récupère le résultat de la requête
                ui->combo_Idm_1->addItem(s);

            }
        }


}

event::~event()
{
    delete ui;
}

void event::on_ajouter_even_clicked()
{
    bool verif_Id_evenemnt,verif_Nom,verif_Lieu;

    bool verifID=false;
    bool verifNOM=false;
    bool verifLIEU=false;



    verif_Id_evenemnt=true;
    verif_Nom=true;
    verif_Lieu=true;



    QString numbers = "0123456789";
    QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";

    QString Id_evenement = ui->ajouter_id_evenement->text();
    for(int i = 0; i < Id_evenement.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){
                      if(Id_evenement[i] == numbers[j]){
                          verifID = true;
                      }
                  }
                  if(verifID == false ){
                      verif_Id_evenemnt = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur id invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }
    QString Nom = ui->ajouter_nom->text();
    int v=0;
    for(int i = 0; i < Nom.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){
                      if(Nom[i] == numbers[j]){
                           v = v +1;
                      }
                      if (v == 0)
                                              verifNOM = true;
                      else if(v != 0)
                    verifNOM = false;
                  }
                  if(verifNOM == false ){
                      verif_Nom = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur Nom invalide.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }

    QString Lieu = ui->ajouter_lieu->text();
    for(int i = 0; i < Lieu.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){
                      if(Lieu[i] == numbers[j]){
                          v = v +1;

                      }
                      if (v == 0)
                          verifLIEU = true;
                      else if(v != 0)
                    verifLIEU = false;
                  }
                  if(verifLIEU == false ){
                      verif_Lieu = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur LIEU invalide.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }



    if((verif_Id_evenemnt == true)&&(verif_Nom == true) && (verif_Lieu == true)){
    evenement re(Id_evenement,Nom,Lieu);
    bool test=re.ajouter_evenement();

   if(test)
    {
        ui->combo_Id_evenement_2->setModel(tmptournoi.refresh_Id_evenement());
        ui->table_eve->setModel(tmpevenement.afficher_evenement());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une evenement"),QObject::tr("evenement ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
    }
}
}
QSqlQueryModel* evenement::afficher_evenement()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EVEN");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_evenement "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));


    return model;
}
void event::on_supprimer_even_clicked()
{
    QString id = ui->supprimer_even_2->text();
    bool test = tmpevenement.supprimer_evenement(id);

    if(test)
    {
        ui->table_eve->setModel(tmpevenement.afficher_evenement());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                        QObject::tr("Evenement supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }




void event::on_tri_asc_even_clicked()
{
    ui->table_eve->setModel(tmpevenement.afficher_tri_ID());

}

void event::on_tri_desc_even_clicked()
{
    ui->table_eve->setModel(tmpevenement.afficher_tri_ID_DESC());
}

void event::on_modifier_even_clicked()
{


        QString Id_evenement = ui->modifier_id_evenement->text();
        QString Nom = ui->modifier_nom->text();
        QString Lieu = ui->modifier_lieu->text();


    bool test=tmpevenement.modifier_evenement(Id_evenement,Nom,Lieu);


    if (test)
      {
        ui->table_eve->setModel(tmpevenement.afficher_evenement());//refresh
        ui->table_evee->setModel(tmpevenement.afficher_Re_evenement(Id_evenement));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un evenement "),
                    QObject::tr("Evenement modifiee.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
void event::on_chercher_modif_eve_clicked()
{

    QString id_evenement = ui->chercher_eve->text();

        ui->table_evee->setModel(tmpevenement.afficher_Re_evenement(id_evenement));//refresh

}
void event::on_ajouter_tour_clicked()
{
    bool verifIDt=false;
    bool verifNOM=false;

    bool verif_Idt=true;
    bool verif_nom_tr=true;

    QString numbers = "0123456789";
    QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";

    QString Id_evenement;
    QString Idt = ui->ajouter_idt->text();
    for(int i = 0; i < Idt.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){
                      if(Idt[i] == numbers[j]){
                          verifIDt = true;
                      }
                  }
                  if(verifIDt == false ){
                      verif_Idt = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur id invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }
    QString nom_tr = ui->ajouter_nom_tr->text();
    for(int i = 0; i < nom_tr.length(); i++){
                  for(int j = 0; j < alphab.length(); j++){
                      if(nom_tr[i] == alphab[j]){
                          verifNOM = true;
                      }
                  }
                  if(verifNOM == false ){
                      verif_nom_tr = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur nom invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }

    QString dis_tr = ui->ajouter_dis_tr->text();
    QString typ_tr = ui->ajouter_typ_tr->text();
    QString date_tr = ui->ajouter_date_tr->text();

     if((verif_Idt == true)&&(verif_nom_tr == true)){
    tournoi to(Idt,nom_tr,dis_tr,typ_tr,date_tr,Id_evenement);
    bool test=to.ajouter_tour();

    if(test)
    {
        ui->combo_Idt_2->setModel(tmptournoi.refresh_Idt());
        ui->table_tour->setModel(tmptournoi.afficher_tour());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un tournoi"),QObject::tr("tournoi ajoute.\n""Click cancel to exit."),QMessageBox::Cancel);
    }
}
}



QSqlQueryModel* tournoi::afficher_tour()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM TOUR");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_tournoi"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_tournoi"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_tournoi"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DICIPLINE_tournoi"));



    return model;
   }
void event::on_supprimer_tourn_clicked()
{
    QString ids = ui->supprimer_tour->text();
    bool test = tmptournoi.supprimer_tour(ids);

    if(test)
    {
        ui->table_tour->setModel(tmptournoi.afficher_tour());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un tournoi"),
                        QObject::tr("tournoi supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un tournoi"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }
void event::on_pushButton_clicked()
{
    QString Idt = ui->combo_Idt_2->currentText();
    QString Id_evenement = ui->combo_Id_evenement_2->currentText();


    bool test=tmptournoi.affecter_tour(Idt,Id_evenement);

    if(test)
    {
        ui->table_tour->setModel(tmptournoi.afficher_tour());
        QMessageBox::information(nullptr, QObject::tr("Affecter un tournoi"),QObject::tr("tournoi affecté.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

else
    QMessageBox::critical(nullptr, QObject::tr("Affecter un tournoi"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
void event::on_tri_asc_tour_clicked()
{
    ui->table_tour->setModel(tmptournoi.afficher_tri_IDt());

}

void event::on_tri_desc_tour_clicked()
{
    ui->table_tour->setModel(tmptournoi.afficher_tri_IDt_DESC());
}
void event::on_modifier_tour_clicked()
{



        QString Idt = ui->modifier_idt->text();
        QString nom_tr = ui->modifier_nom_tr->text();
        QString dis_tr = ui->modifier_dis_tr->text();
        QString typ_tr = ui->modifier_typ_tr->text();
        QString date_tr = ui->modifier_date_tr->text();


    bool test=tmptournoi.modifier_tour(Idt,nom_tr,dis_tr,typ_tr,date_tr);


    if (test)
      {
        ui->table_tour->setModel(tmptournoi.afficher_tour());//refresh
        ui->table_Re_tour->setModel(tmptournoi.afficher_Re_tour(Idt));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un tournoi"),
                    QObject::tr("tournoi modifie.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un ticket"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
void event::on_chercher_modif_tour_clicked()
{

    QString Idt = ui->chercher_res_2->text();

        ui->table_Re_tour->setModel(tmptournoi.afficher_Re_tour(Idt));//refresh

}

void event::on_chercher_eve_textChanged(const QString &arg1)
{
     ui->table_evee->setModel(tmpevenement.afficher_dyna_even(arg1));//refresh
}

void event::on_chercher_res_2_textChanged(const QString &arg1)
{
     ui->table_Re_tour->setModel(tmptournoi.afficher_dyna_tour(arg1));//refresh
}

void event::on_ajouter_mat_clicked()
{
    bool verifIDM=false;


    bool verif_Idm=true;


    QString numbers = "0123456789";
    QString alphab = "azertyuiopqsdfghjklmwxcvbnéàçAZERTYUIOPQSDFGHJKLMWXCVBN";

    QString Idt;
    QString Idm = ui->ajouter_idm->text();
    for(int i = 0; i < Idm.length(); i++){
                  for(int j = 0; j < numbers.length(); j++){
                      if(Idm[i] == numbers[j]){
                          verifIDM = true;
                      }
                  }
                  if(verifIDM == false ){
                      verif_Idm = false;
                      QMessageBox::information(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Erreur id invalide .\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

                      break;
                  }
              }


    QString  num_m= ui->ajouter_num_m->text();
    QString eq_h = ui->ajouter_eq_h->text();
    QString eq_a = ui->ajouter_eq_a->text();
    QString score = ui->ajouter_score->text();

     if((verif_Idm = true)){
    match to(Idm,num_m,eq_h,eq_a,score,Idt);
    bool test=to.ajouter_mat();

    if(test)
    {
       ui->combo_Idm_1->setModel(tmpmatch.refresh_Idm());
        ui->table_mat->setModel(tmpmatch.afficher_mat());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un match"),QObject::tr("match ajoute.\n""Click cancel to exit."),QMessageBox::Cancel);
    }
}
}

QSqlQueryModel* match::afficher_mat()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM MATCH");



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_MATCH"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EQUIPE_h"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Equipe_a"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("score"));






    return model;
   }
void event::on_supprimer_mat_clicked()
{
    QString id = ui->supprimer_mat_2->text();
    bool test = tmpmatch.supprimer_mat(id);

    if(test)
    {
        ui->table_mat->setModel(tmpmatch.afficher_mat());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un match"),
                        QObject::tr("match supprimer.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un match"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }
void event::on_pushButton_2_clicked()
{
    QString Idm = ui->combo_Idm_1->currentText();
    QString Idt = ui->combo_Idt_3->currentText();


    bool test=tmpmatch.affecter_mat(Idt,Idm);

    if(test)
    {
        ui->table_mat->setModel(tmpmatch.afficher_mat());
        QMessageBox::information(nullptr, QObject::tr("Affecter un match"),QObject::tr("match affecté.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

else
    QMessageBox::critical(nullptr, QObject::tr("Affecter un match"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
void event::on_tri_asc_mat_clicked()
{
    ui->table_mat->setModel(tmpmatch.afficher_tri_IDm());

}

void event::on_tri_desc_mat_clicked()
{
    ui->table_mat->setModel(tmpmatch.afficher_tri_IDm_DESC());
}
void event::on_modifier_mat_clicked()
{


        QString Idt = ui->modifier_idt_3->text();
        QString Idm = ui->modifier_idm->text();
        QString num_m = ui->modifier_num_m->text();
        QString eq_h = ui->modifier_eq_h->text();
        QString eq_a = ui->modifier_eq_a->text();
        QString score = ui->modifier_score->text();


    bool test=tmpmatch.modifier_mat(Idt,Idm,num_m,eq_h,eq_a,score);


    if (test)
      {
        ui->table_mat->setModel(tmpmatch.afficher_mat());//refresh
        ui->table_Re_mat->setModel(tmpmatch.afficher_Re_mat(Idm));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un match"),
                    QObject::tr("tournoi modifie.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un match"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
void event::on_chercher_modif_mat_clicked()
{

    QString Idm = ui->chercher_matt->text();

        ui->table_Re_mat->setModel(tmpmatch.afficher_Re_mat(Idm));//refresh

}

void event::on_chercher_matt_textChanged(const QString &arg1)
{
    ui->table_Re_mat->setModel(tmpmatch.afficher_dyna_mat(arg1));//refresh

}
