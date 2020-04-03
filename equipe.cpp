#include "equipe.h"
#include "ui_equipe.h"

#include <QMessageBox>
#include "joueur.h"

#include <QSqlQuery>
#include <QDebug>
#include <QVariant>

equipe::equipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::equipe)
{
    ui->setupUi(this);
    ui->table_equipe->setModel(tmpequipe.afficher_equipe());


}

equipe::~equipe()
{
    delete ui;
}

void equipe::on_Ajouter_equipe_clicked()
{
    QString nom = ui->ajouter_nom_equipe->text();
    QString id = ui->ajouter_id_equipe->text();

    QString  nom_entr = ui->ajouter_nom_en_equipe->text();


    classEquipe cl(id,nom,nom_entr);
    bool test=cl.ajouter_equipe();

    if(test)
    {
        ui->table_equipe->setModel(tmpequipe.afficher_equipe());
        QMessageBox::information(nullptr, QObject::tr("Ajouter une equipe"),QObject::tr("equipe ajoutee !!!.\n""Click cancel to exit."),QMessageBox::Cancel);
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

void equipe::on_supprimer_equipe_clicked()
{
    QString id = ui->supprimer_equipe->text();
    bool test = tmpequipe.supprimer_equipe(id);

    if(test)
    {
        ui->table_equipe->setModel(tmpequipe.afficher_equipe());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une equipe"),
                        QObject::tr("equipe supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipe"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }






void equipe::on_chercher_modif_equipe_clicked()
{

    QString id = ui->chercher_equipe->text();

        ui->table_Re_equipe->setModel(tmpequipe.afficher_Re_equipe(id));//refresh

}


void equipe::on_modifier_equipe_clicked()
{


        QString nom = ui->modifier_nom_equipe->text();
        QString id= ui->modifier_id_equipe->text();

        QString nom_en = ui->modifier_nom_en_equipe->text();


    bool test=tmpequipe.modifier_equipe(id,nom,nom_en);


    if (test)
      {
        ui->table_equipe->setModel(tmpequipe.afficher_equipe());//refresh
        ui->table_Re_equipe->setModel(tmpequipe.afficher_Re_equipe(id));//refresh

    QMessageBox::information(nullptr, QObject::tr("modifier une equipe"),
                    QObject::tr("equipe modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier une equipe"),
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

void equipe::on_tri_asc_clicked()
{
    ui->table_equipe->setModel(tmpequipe.afficher_tri_ID());

}

void equipe::on_tri_desc_clicked()
{
    ui->table_equipe->setModel(tmpequipe.afficher_tri_ID_DESC());
}
