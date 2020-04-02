#include "adherent.h"
#include "ui_adherent.h"
#include <QMessageBox>
#include "gestion_adh.h"
#include "gestion_cad.h"
#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

adherent::adherent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adherent)
{
    ui->setupUi(this);
    this->setWindowTitle("GESTION DES ADHERENTS ET DES CADEAUX");
    this->setWindowIcon(QIcon("../PROJECT_NOUR_F/e-spirit.png"));
    ui->table_adherent->setModel(tmpadherent.afficher_adherent());
    ui->table_cadeau_2->setModel(tmpcadeau.afficher_cadeau());

}

adherent::~adherent()
{
    delete ui;
}

void adherent::on_Ajouter_adherent_2_clicked()
{
    QString nom_adherent = ui->ajouter_nom_adherent_2->text();
    QString id_adherent = ui->ajouter_id_adherent_2->text();
    QString prenom_adherent = ui->ajouter_prenom_adherent_2->text();
    QString numero_adherent = ui->ajouter_numero_adherent_2->text();
    QString email_adherent = ui->ajouter_email_adherent_2->text();
    QString nombre_pts_adherent = ui->Ajouter_nombrepts_adherent_2->text();

    gestion_adh ga(nom_adherent,id_adherent,prenom_adherent,numero_adherent,email_adherent,nombre_pts_adherent);
    bool test=ga.ajouter_adherent();

    if(test)
    {
        ui->table_adherent->setModel(tmpadherent.afficher_adherent());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un adherent"),QObject::tr("Adherent ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

}


QSqlQueryModel * gestion_adh::afficher_adherent()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM adherent");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points"));

    return model;
}


void adherent::on_supprimer_adherent_3_clicked()
{
    QString id_adherent = ui->supprimer_adherent->text();
    bool test = tmpadherent.supprimer_adherent(id_adherent);

    if(test)
    {
        ui->table_adherent->setModel(tmpadherent.afficher_adherent());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un adhérent"),
                        QObject::tr("Adhérent supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un adhérent"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }



void adherent::on_Ajouter_cadeau_2_clicked()
{
    QString id_cadeau = ui->Ajouter_id_cadeau_2->text();
    QString nom_cadeau = ui->ajouter_nom_cadeau_2->text();
    QString nb_pts_cadeau = ui->Ajouter_nombrepts_cadeau_2->text();
    QString quantite_cadeau = ui->Ajouter_quantite_cadeau_2->text();


    gestion_cad gc(id_cadeau,nom_cadeau,nb_pts_cadeau,quantite_cadeau);
    bool test=gc.ajouter_cadeau();

    if(test)
    {
        ui->table_cadeau_2->setModel(tmpcadeau.afficher_cadeau());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un cadeau"),QObject::tr("Cadeau ajoutee.\n""Click cancel to exit."),QMessageBox::Cancel);
    }
}


QSqlQueryModel * gestion_cad::afficher_cadeau()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM cadeau");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Points"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));

    return model;
}

void adherent::on_supprimer_cadeau_2_clicked()
{
    QString id_cadeau = ui->supprimer_cadeau->text();
    bool test = tmpcadeau.supprimer_cadeau(id_cadeau);

    if(test)
    {
        ui->table_cadeau_2->setModel(tmpcadeau.afficher_cadeau());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un cadeau"),
                        QObject::tr("Cadeau supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un cadeau"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void adherent::on_chercher_modif_adherent_clicked()
{

    QString id_adherent = ui->chercher_adherent->text();

        ui->table_Re_adherent->setModel(tmpadherent.afficher_Re_adherent(id_adherent));//refresh

}


void adherent::on_modifier_adherent_clicked()
{


        QString nom_adherent = ui->modifier_nom_adherent->text();
        QString id_adherent = ui->modifier_id_adherent->text();
        QString prenom_adherent = ui->modifier_prenom_adherent->text();
        QString numero_adherent = ui->modifier_numero_adherent->text();
        QString email_adherent = ui->modifier_email_adherent->text();
        QString nombre_pts_adherent= ui->modifier_pts_adherent->text();

    bool test=tmpadherent.modifier_adherent(nom_adherent,id_adherent,prenom_adherent,numero_adherent,email_adherent,nombre_pts_adherent);


    if (test)
      {
        ui->table_adherent->setModel(tmpadherent.afficher_adherent());//refresh
        ui->table_Re_adherent->setModel(tmpadherent.afficher_Re_adherent(id_adherent));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un adherent"),
                    QObject::tr("Adhérent modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un adherent"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}

void adherent::on_modifier_cadeau_clicked()
{

    QString id_cadeau = ui->modifier_id_cadeau->text();
    QString nom_cadeau = ui->modifier_nom_cadeau->text();
    QString nb_pts_cadeau = ui->modifier_pts_cadeau->text();
    QString quantite_cadeau = ui->modifier_quantite_cadeau->text();


bool test=tmpcadeau.modifier_cadeau(id_cadeau,nom_cadeau,nb_pts_cadeau,quantite_cadeau);


if (test)
  {

    ui->table_cadeau_2->setModel(tmpcadeau.afficher_cadeau());//refresh
    ui->table_Re_cadeau->setModel(tmpcadeau.afficher_Re_cadeau(id_cadeau));


QMessageBox::information(nullptr, QObject::tr("modifier un cadeau"),
                QObject::tr("Cadeau modifier.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("modifier un cadeau"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void adherent::on_chercher_cadeau_clicked()
{

    QString id_cadeau = ui->recherche_cadeau_id->text();

    ui->table_Re_cadeau->setModel(tmpcadeau.afficher_Re_cadeau(id_cadeau));//refresh

}

void adherent::on_Statistique_adherent_clicked()
{
    QString val = ui->chercher_stat->text(),b1;
        float stat1=tmpstat.Calculer_Tab_Stat(val);  //pourcentage des bus de la marque val en panne
        float stat2=100-stat1;      //pourcentage des bus de la marque val en panne
        ui->chercher_stat_2->setText("Supp a 20 pts");
        ui->chercher_stat_4->setText("Inf a 20 pts");
        ui->chercher_stat_3->setText(b1.setNum(stat1));
        ui->chercher_stat_5->setText(b1.setNum(stat2));

}

void adherent::on_tri_asc_clicked()
{
    ui->table_adherent->setModel(tmpadherent.afficher_tri_ID());

}

void adherent::on_tri_desc_clicked()
{
    ui->table_adherent->setModel(tmpadherent.afficher_tri_ID_DESC());
}

void adherent::on_tri_asc_cad_clicked()
{
    ui->table_cadeau_2->setModel(tmpcadeau.afficher_tri_CAD());
}

void adherent::on_tri_desc_cad_clicked()
{
    ui->table_cadeau_2->setModel(tmpcadeau.afficher_tri_CAD_DESC());
}
