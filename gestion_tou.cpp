#include "gestion_tou.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>

gestion_tou::gestion_tou()
{
  id_tour="";
  nom_tour="";
  date_tour="";
  fin_tour="";
  lieu_tour="";

}

gestion_tou::gestion_tou( QString nom_tour, QString id_tour, date date_tour, date fin_tour, QString lieu_tour)
{
    this->nom_tour=nom_tour;
    this->id_tour=id_tour;
    this->date_tour=date_tour;
    this->fin_tour=fin_tour;
    this->lieu_tour=lieu_tour;

}

QString gestion_tou::get_nom_tour(){return nom_tour;}
QString gestion_tou::get_id_tour(){return id_tour;}
QString gestion_tou::get_date_tour(){return date_tour;}
QString gestion_tou::get_fin_tour(){return fin_tour;}
QString gestion_tou::get_lieu_tour(){return lieu_tour;}


bool gestion_tou::ajouter_tourn()
{
    QSqlQuery query;
    query.prepare("INSERT INTO tournoi (nom_tour, id_tour, date_tour, fin_tour, lieu_tour)"
                  "VALUES (:nom_tour, :id_tour, :date_tour, :fin_tour, :lieu_tour)");


    query.bindValue(":nom_tour",nom_tour);
    query.bindValue(":id_tour",id_tour);
    query.bindValue(":date_tour",date_tour);
    query.bindValue(":fin_tour",fin_tour);
    query.bindValue(":lieu_tour",lieu_tour);


    return query.exec();
}

bool gestion_tou::supprimer_tourn(QString id_Stour)
{
    QSqlQuery query;
    query.prepare("DELETE FROM tournoi WHERE id_tour = :id_tour ");
    query.bindValue(":id_tour", id_Stour);

    return  query.exec();
}

bool gestion_tou::modifier_tourn(QString nom_tour, QString id_tour, DATE date_tour , DATE fin_tour ,QString lieu_tour)
{
    QSqlQuery query;


        query.prepare("UPDATE tournoi SET nom_tour=:nom_tour , date_tour=:date_tour, fin_tour=:fin_tour, lieu_tour=:lieu_tour  WHERE id_tour=:id_tour");

        query.bindValue(":id_tour", id_tour);
        query.bindValue(":nom_tour", nom_tour);
        query.bindValue(":date_tour", date_tour);
        query.bindValue(":fin_tour", fin_tour);
        query.bindValue(":lieu_tour", lieu_tour);



        return    query.exec();
}

QSqlQueryModel * gestion_tou::afficher_Re_tourn(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from tournoi where id_tour= '"+val+"'") ;
             setQuery("select lieu from lieu where id_lieu= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));


    return model;
}


bool gestion_tou::chercher_tourn()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM tournoi WHERE id_tour = :id_tour ");
    query.bindValue(":id_tour", id_Rtour);

    return  query.exec(); */
}

QSqlQueryModel * gestion_tou:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tournoi order by id_tour");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));

    return model;
}

QSqlQueryModel * gestion_tou:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from tournoi order by id_tournoi desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("date debut"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("date fin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("lieu"));
    return model;
}
