#include "joueur.h"
#include "ui_joueur.h"

#include <QMessageBox>
#include "joueur.h"

#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

joueur::joueur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::joueur)
{
    ui->setupUi(this);
    ui->table_joueur->setModel(tmpjoueur.afficher_joueur());


}

joueur::~joueur()
{
    delete ui;
}

void joueur::on_Ajouter_joueur_clicked()
{
    QString nom = ui->ajouter_nom_joueur->text();
    QString id = ui->ajouter_id_joueur->text();
    QString prenom= ui->ajouter_prenom_joueur->text();
    QString nom_equipe = ui->ajouter_nom_e_joueur->text();
    QString  nom_entr = ui->ajouter_nom_en_joueur->text();


    classJoueur cl(nom,id,prenom,nom_equipe,nom_entr);
    bool test=cl.ajouter_joueur();

    if(test)
    {
        ui->table_joueur->setModel(tmpjoueur.afficher_joueur());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un joueur"),QObject::tr("Joueur ajoutee !!!.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

}


/*QSqlQueryModel * classJoueur::afficher_joueur()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM JOUEUR");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nom_equipe"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nom_entraineur"));


    return model;
}
*/

void joueur::on_supprimer_joueur_clicked()
{
    QString id = ui->supprimer_joueur_2->text();
    bool test = tmpjoueur.supprimer_joueur(id);

    if(test)
    {
        ui->table_joueur->setModel(tmpjoueur.afficher_joueur());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un joueur"),
                        QObject::tr("joueur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un joueur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }






void joueur::on_chercher_modif_joueur_clicked()
{

    QString id = ui->chercher_joueur->text();

        ui->table_Re_joueur->setModel(tmpjoueur.afficher_Re_joueur(id));//refresh

}


void joueur::on_modifier_joueur_clicked()
{


        QString nom = ui->modifier_nom_joueur->text();
        QString id= ui->modifier_id_joueur->text();
        QString prenom = ui->modifier_prenom_joueur->text();
        QString nom_eq = ui->modifier_nom_e_joueur->text();
        QString nom_en = ui->modifier_nom_en_joueur_2->text();


    bool test=tmpjoueur.modifier_joueur(id,nom,prenom,nom_eq,nom_en);


    if (test)
      {
        ui->table_joueur->setModel(tmpjoueur.afficher_joueur());//refresh
        ui->table_Re_joueur->setModel(tmpjoueur.afficher_Re_joueur(id));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un joueur"),
                    QObject::tr("joueur modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un joueur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}




/*void joueur::on_Statistique_joueur_clicked()
{
    QString val = ui->chercher_stat->text(),b1;
        float stat1=tmpstat.Calculer_Tab_Stat(val);  //pourcentage des bus de la marque val en panne
        float stat2=100-stat1;      //pourcentage des bus de la marque val en panne
        ui->chercher_stat_2->setText("Supp a 20 pts");
        ui->chercher_stat_4->setText("Inf a 20 pts");
        ui->chercher_stat_3->setText(b1.setNum(stat1));
        ui->chercher_stat_5->setText(b1.setNum(stat2));

}*/

void joueur::on_tri_asc_clicked()
{
    ui->table_joueur->setModel(tmpjoueur.afficher_tri_ID());

}

void joueur::on_tri_desc_clicked()
{
    ui->table_joueur->setModel(tmpjoueur.afficher_tri_ID_DESC());
}
