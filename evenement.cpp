#include "evenement.h"
#include "ui_evenement.h"
#include <QMessageBox>
#include "gestion_eve.h"

#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

evenement::evenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::evenement)
{
    ui->setupUi(this);
    ui->table_evene->setModel(tmpevenement.afficher_eve());


}

evenement::~evenement()
{
    delete ui;
}

void evenement::on_Ajouter_eve_clicked()
{
    QString nom_eve = ui->ajouter_nom_eve->text();
    QString id_eve = ui->ajouter_id_eve->text();


    gestion_eve ga(nom_eve,id_eve);
    bool test=ga.ajouter_eve();

    if(test)
    {
        ui->table_evene->setModel(tmpevenement.afficher_eve());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un evenement"),QObject::tr("evenement ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

}


QSqlQueryModel * gestion_eve::afficher_eve()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));


    return model;
}


void evenement::on_supprimer_even_clicked()
{
    QString id_eve = ui->supprimer_eve->text();
    bool test = tmpevenement.supprimer_eve(id_eve);

    if(test)
    {
        ui->table_evene->setModel(tmpevenement.afficher_eve());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un evenement"),
                        QObject::tr("evenement supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un evenement"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }










void evenement::on_chercher_modif_eve_clicked()
{

    QString id_eve = ui->chercher_eve->text();

        ui->table_Re_eve->setModel(tmpevenement.afficher_Re_eve(id_eve));//refresh

}


void evenement::on_modifier_evene_clicked()
{


        QString nom_eve = ui->modifier_nom_eve->text();
        QString id_eve = ui->modifier_id_eve->text();

    bool test=tmpevenement.modifier_evene(nom_eve,id_eve);


    if (test)
      {
        ui->table_evene->setModel(tmpevenement.afficher_eve());//refresh
        ui->table_Re_eve->setModel(tmpevenement.afficher_Re_eve(id_eve));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un evenement"),
                    QObject::tr("evenement modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un evenement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}




void evenement::on_Statistique_eve_clicked()
{
    QString val = ui->chercher_stat->text(),b1;
        float stat1=tmpstat.Calculer_Tab_Stat(val);  //pourcentage des bus de la marque val en panne
        float stat2=100%-stat1;      //pourcentage des bus de la marque val en panne
        ui->chercher_stat_2->setText("Supp a 20% pts");
        ui->chercher_stat_4->setText("Inf a 20% pts");
        ui->chercher_stat_3->setText(b1.setNum(stat1));
        ui->chercher_stat_5->setText(b1.setNum(stat2));

}

void evenement::on_tri_asc_clicked()
{
    ui->table_evene->setModel(tmpevenement.afficher_tri_ID());

}

void evenement::on_tri_desc_clicked()
{
    ui->table_evene->setModel(tmpevenement.afficher_tri_ID_DESC());
}
