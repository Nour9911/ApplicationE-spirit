#include "tournoi.h"
#include "ui_tournoi.h"
#include <QMessageBox>
#include "gestion_tou.h"
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

tournoi::tournoi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tournoi)
{
    ui->setupUi(this);
    ui->table_tourn->setModel(tmptournoi.afficher_tourn());


}

tournoi::~tournoi()
{
    delete ui;
}

void tournoi::on_Ajouter_tourn_clicked()
{
    QString nom_tour = ui->ajouter_nom_tour->text();
    QString id_tour = ui->ajouter_id_tour->text();
    QString date_tour = ui->ajouter_date_tour->date();
     QString fin_tour = ui->ajouter_fin_tour->date();
    QString lieu_tour = ui->ajouter_lieu_tour->text();


    gestion_tou ga(nom_tour,id_tour,date_tour,fin_tour,lieu_tour);
    bool test=ga.ajouter_tourn();

    if(test)
    {
        ui->table_tourn->setModel(tmptournoi.afficher_tourn());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un tournoi"),QObject::tr("tournoi ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

}


QSqlQueryModel * gestion_tou::afficher_tourn()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM tournoi");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));



    return model;
}


void tournoi::on_supprimer_tourn_clicked()
{
    QString id_tour = ui->supprimer_tour->text();
    bool test = tmptournoi.supprimer_tour(id_tour);

    if(test)
    {
        ui->table_tourn->setModel(tmptournoi.afficher_tourn());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un tournoi"),
                        QObject::tr("tournoi supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un tournoi"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }





void tournoi::on_chercher_modif_tourn_clicked()
{

    QString id_tour = ui->chercher_tourn->text();

        ui->table_Re_tourn->setModel(tmptournoi.afficher_Re_tourn(id_tour));//refresh

}


void tournoi::on_modifier_tourn_clicked()
{

    QString nom_tour = ui->ajouter_nom_tour->text();
    QString id_tour = ui->ajouter_id_tour->text();
    QString date_tour = ui->ajouter_date_tour->date();
     QString fin_tour = ui->ajouter_fin_tour->date();
    QString lieu_tour = ui->ajouter_lieu_tour->text();

    bool test=tmptournoi.modifier_tourn(nom_tour,id_tour,date_tour,fin_tour,lieu_tour);


    if (test)
      {
        ui->table_tourn->setModel(tmptournoi.afficher_tourn());//refresh
        ui->table_Re_tourn->setModel(tmptournoi.afficher_Re_tourn(id_tour));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un tournoi"),
                    QObject::tr("Tournoi modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un tournoi"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}




void tournoi::on_tri_asc_clicked()
{
    ui->table_tourn->setModel(tmptournoi.afficher_tri_ID());

}

void tournoi::on_tri_desc_clicked()
{
    ui->table_tourn->setModel(tmptournoi.afficher_tri_ID_DESC());
}
