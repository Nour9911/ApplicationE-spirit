#include "entraineur.h"
#include "ui_entraineur.h"

#include <QMessageBox>


#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

entraineur::entraineur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entraineur)
{
    ui->setupUi(this);
    ui->table_entraineur->setModel(tmpentraineur.afficher_entraineur());


}

entraineur::~entraineur()
{
    delete ui;
}

void entraineur::on_Ajouter_entraineur_clicked()
{
    QString nom = ui->ajouter_nom_entraineur->text();
    QString id = ui->ajouter_id_entraineur->text();
    QString prenom=ui->ajouter_nom_entraineur_2->text();

    QString  nom_equipe = ui->ajouter_nom_entraineur_3->text();


    classEntraineur cl(id,nom,prenom,nom_equipe);
    bool test=cl.ajouter_entraineur();

    if(test)
    {
        ui->table_entraineur->setModel(tmpentraineur.afficher_entraineur());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une entraineur"),QObject::tr("entraineur ajoutee !!!.\n""Click cancel to exit."),QMessageBox::Cancel);
    }

}


/*QSqlQueryModel * classEquipe::afficher_equipe()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_EQUIPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_EQUIPE"));


    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ENTRAINEUR_EQUI"));



    return model;
}
*/

void entraineur::on_supprimer_entraineur_clicked()
{
    QString id = ui->supprimer_entraineur_2->text();
    bool test = tmpentraineur.supprimer_entraineur(id);

    if(test)
    {
        ui->table_entraineur->setModel(tmpentraineur.afficher_entraineur());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un entraineur"),
                        QObject::tr("entraineur supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un entraineur"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }






void entraineur::on_chercher_modif_entraineur_clicked()
{

    QString id = ui->chercher_entraineur->text();

        ui->table_Re_entraineur->setModel(tmpentraineur.afficher_Re_entraineur(id));//refresh

}


void entraineur::on_modifier_entraineur_clicked()
{


        QString nom = ui->modifier_nom_entraineur->text();
        QString id= ui->modifier_id_entraineur->text();
        QString prenom= ui->modifier_prenom_entraineur->text();
         QString nom_equipe = ui->modifier_nom_e_entraineur->text();


    bool test=tmpentraineur.modifier_entraineur(id,nom,prenom,nom_equipe);


    if (test)
      {
        ui->table_entraineur->setModel(tmpentraineur.afficher_entraineur());//refresh
        ui->table_Re_entraineur->setModel(tmpentraineur.afficher_Re_entraineur(id));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier un entraineur"),
                    QObject::tr("entraineur modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un entraineur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}





void entraineur::on_tri_asc_clicked()
{
    ui->table_entraineur->setModel(tmpentraineur.afficher_tri_ID());

}

void entraineur::on_tri_desc_clicked()
{
    ui->table_entraineur->setModel(tmpentraineur.afficher_tri_ID_DESC());
}
