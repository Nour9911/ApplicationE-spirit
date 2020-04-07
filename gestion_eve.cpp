#include "gestion_eve.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>

gestion_eve::gestion_eve()
{
  id_eve="";
  nom_eve="";

}

gestion_eve::gestion_eve( QString nom_eve, QString id_eve)
{
    this->nom_eve=nom_eve;
    this->id_eve=id_eve;

}

QString gestion_eve::get_nom_eve(){return nom_eve;}
QString gestion_eve::get_id_eve(){return id_eve;}
ent;}

bool gestion_eve::Ajouter_eve()
{
    QSqlQuery query;
    query.prepare("INSERT INTO evenement (nom_eve, id_eve)"
                  "VALUES (:nom_eve, :id_eve)");


    query.bindValue(":nom_eve",nom_eve);
    query.bindValue(":id_eve",id_eve);


    return query.exec();
}

bool gestion_eve::supprimer_even(QString id_Seve)
{
    QSqlQuery query;
    query.prepare("DELETE FROM evenement WHERE id_eve = :id_eve ");
    query.bindValue(":id_eve", id_Seve);

    return  query.exec();
}

bool gestion_eve::modifier_evene(QString nom_eve, QString id_eve)
{
    QSqlQuery query;


        query.prepare("UPDATE evenement SET nom_eve=:nom_even  WHERE id_eve=:id_eve");

        query.bindValue(":id_eve", id_eve);
        query.bindValue(":nom_eve", nom_eve);


        return    query.exec();
}

QSqlQueryModel * gestion_eve::afficher_Re_eve(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from evenement where id_eve= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

    return model;
}


bool gestion_eve::chercher_eve()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM evenement WHERE id_eve = :id_eve ");
    query.bindValue(":id_eve", id_Reve);

    return  query.exec(); */
}

QSqlQueryModel * gestion_eve:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from evenement order by id_eve");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

    return model;
}

QSqlQueryModel * gestion_eve:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from evenement order by id_eve desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));

    return model;
}
