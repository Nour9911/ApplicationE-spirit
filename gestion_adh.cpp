#include "gestion_adh.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>

gestion_adh::gestion_adh()
{
  id_adherent="";
  nom_adherent="";
  prenom_adherent="";
  numero_adherent="";
  email_adherent="";
  nombre_pts_adherent="";
}

gestion_adh::gestion_adh( QString nom_adherent, QString id_adherent, QString prenom_adherent, QString numero_adherent, QString email_adherent, QString nombre_pts_adherent)
{
    this->nom_adherent=nom_adherent;
    this->id_adherent=id_adherent;
    this->prenom_adherent=prenom_adherent;
    this->numero_adherent=numero_adherent;
    this->email_adherent=email_adherent;
    this->nombre_pts_adherent=nombre_pts_adherent;
}

QString gestion_adh::get_nom_adherent(){return nom_adherent;}
QString gestion_adh::get_id_adherent(){return id_adherent;}
QString gestion_adh::get_prenom_adherent(){return prenom_adherent;}
QString gestion_adh::get_numero_adherent(){return numero_adherent;}
QString gestion_adh::get_email_adherent(){return email_adherent;}
QString gestion_adh::get_nombre_pts_adherent(){return nombre_pts_adherent;}

bool gestion_adh::ajouter_adherent()
{
    QSqlQuery query;
    query.prepare("INSERT INTO adherent (nom_adherent, id_adherent, prenom_adherent, numero_adherent, email_adherent, nombre_pts_adherent)"
                  "VALUES (:nom_adherent, :id_adherent, :prenom_adherent, :numero_adherent, :email_adherent, :nombre_pts_adherent)");


    query.bindValue(":nom_adherent",nom_adherent);
    query.bindValue(":id_adherent",id_adherent);
    query.bindValue(":prenom_adherent",prenom_adherent);
    query.bindValue(":numero_adherent",numero_adherent);
    query.bindValue(":email_adherent",email_adherent);
    query.bindValue(":nombre_pts_adherent",nombre_pts_adherent);

    return query.exec();
}

bool gestion_adh::supprimer_adherent(QString id_Sadherent)
{
    QSqlQuery query;
    query.prepare("DELETE FROM adherent WHERE id_adherent = :id_adherent ");
    query.bindValue(":id_adherent", id_Sadherent);

    return  query.exec();
}

bool gestion_adh::modifier_adherent(QString nom_adherent, QString id_adherent, QString prenom_adherent , QString numero_adherent ,QString email_adherent , QString nombre_pts_adherent)
{
    QSqlQuery query;


        query.prepare("UPDATE adherent SET nom_adherent=:nom_adherent , prenom_adherent=:prenom_adherent, numero_adherent=:numero_adherent, email_adherent=:email_adherent , nombre_pts_adherent= :nombre_pts_adherent  WHERE id_adherent=:id_adherent");

        query.bindValue(":id_adherent", id_adherent);
        query.bindValue(":nom_adherent", nom_adherent);
        query.bindValue(":prenom_adherent", prenom_adherent);
        query.bindValue(":numero_adherent", numero_adherent);
        query.bindValue(":email_adherent", email_adherent);
        query.bindValue(":nombre_pts_adherent", nombre_pts_adherent);


        return    query.exec();
}

QSqlQueryModel * gestion_adh::afficher_Re_adherent(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from adherent where id_adherent= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points"));

    return model;
}


bool gestion_adh::chercher_adherent()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM adherent WHERE id_adherent = :id_adherent ");
    query.bindValue(":id_adherent", id_Radherent);

    return  query.exec(); */
}

QSqlQueryModel * gestion_adh:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from adherent order by id_adherent asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points"));
    return model;
}

QSqlQueryModel * gestion_adh:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from adherent order by id_adherent desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Numero"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Points"));
    return model;
}
