#include "gestion_cad.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>


gestion_cad::gestion_cad()
{
    id_cadeau="";
    nom_cadeau="";
    nb_pts_cadeau="";
    quantite_cadeau="";

}

gestion_cad::gestion_cad( QString id_cadeau, QString nom_cadeau, QString nb_pts_cadeau, QString quantite_cadeau)
{
    this->id_cadeau=id_cadeau;
    this->nom_cadeau=nom_cadeau;
    this->nb_pts_cadeau=nb_pts_cadeau;
    this->quantite_cadeau=quantite_cadeau;

}

QString gestion_cad::get_id_cadeau(){return id_cadeau;}
QString gestion_cad::get_nom_cadeau(){return nom_cadeau;}
QString gestion_cad::get_nb_pts_cadeau(){return nb_pts_cadeau;}
QString gestion_cad::get_quantite_cadeau(){return quantite_cadeau;}


bool gestion_cad::ajouter_cadeau()
{
    QSqlQuery query;
    query.prepare("INSERT INTO cadeau (id_cadeau, nom_cadeau, nb_pts_cadeau, quantite_cadeau)"
                  "VALUES (:id_cadeau, :nom_cadeau, :nb_pts_cadeau, :quantite_cadeau)");


    query.bindValue(":id_cadeau",id_cadeau);
    query.bindValue(":nom_cadeau",nom_cadeau);
    query.bindValue(":nb_pts_cadeau",nb_pts_cadeau);
    query.bindValue(":quantite_cadeau",quantite_cadeau);

    return query.exec();
}


bool gestion_cad::supprimer_cadeau(QString id_Scadeau)
{
    QSqlQuery query;
    query.prepare("DELETE FROM cadeau WHERE id_cadeau = :id_cadeau ");
    query.bindValue(":id_cadeau", id_Scadeau);

    return  query.exec();
}

bool gestion_cad::modifier_cadeau(QString id_cadeau, QString nom_cadeau, QString nb_pts_cadeau , QString quantite_cadeau)
{
    QSqlQuery query;


        query.prepare("UPDATE cadeau SET nom_cadeau=:nom_cadeau , nb_pts_cadeau=:nb_pts_cadeau, quantite_cadeau=:quantite_cadeau WHERE id_cadeau=:id_cadeau");

        query.bindValue(":id_cadeau", id_cadeau);
        query.bindValue(":nom_cadeau", nom_cadeau);
        query.bindValue(":nb_pts_cadeau", nb_pts_cadeau);
        query.bindValue(":quantite_cadeau", quantite_cadeau);



        return    query.exec();
}


QSqlQueryModel * gestion_cad::afficher_Re_cadeau(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("SELECT * FROM cadeau WHERE id_cadeau= '"+val+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Points"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));

    return model;
}


bool gestion_cad::chercher_cadeau()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM cadeau WHERE id_cadeau = :id_cadeau ");
    query.bindValue(":id_cadeau", id_Rcadeau);

    return  query.exec(); */
}

QSqlQueryModel * gestion_cad:: afficher_tri_CAD()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from cadeau order by nb_pts_cadeau asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Points"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    return model;
}

QSqlQueryModel * gestion_cad:: afficher_tri_CAD_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from cadeau order by nb_pts_cadeau desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Points"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantite"));
    return model;
}
