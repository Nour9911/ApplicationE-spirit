#include "classequipe.h"
#include <QSqlDatabase>
#include <QSql>
#include <QDebug>

classEquipe::classEquipe()
{

   id=nom=nom_entr="";

}

classEquipe::classEquipe(QString id,QString nom,QString nom_entr)
{

    this->id=id;
    this->nom=nom;

    this->nom_entr=nom_entr;

}


bool classEquipe::ajouter_equipe()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EQUIPE (ID_EQUIPE, NOM_EQUIPE,ENTRAINEUR_EQUI)"
                  "VALUES (:id, :nom, :nom_entr)");


    query.bindValue(":ID_EQUIPE",id);
    query.bindValue(":NOM_EQUIPE",nom);

    query.bindValue(":ENTRAINEUR_EQUI",nom_entr);


    return query.exec();
}

bool classEquipe::supprimer_equipe(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE WHERE ID_EQUIPE = :id ");
    query.bindValue(":ID_EQUIPE", id);

    return  query.exec();
}

bool classEquipe::modifier_equipe(QString id, QString nom,QString nom_entr)
{
    QSqlQuery query;


        query.prepare("UPDATE EQUIPE SET NOM_EQUIPE=:nom , ID_EQUIPE=:id,ENTRAINEUR_EQUI=:nom_entr  WHERE ID_EQUIPE=:id");

        query.bindValue(":id", id);
        query.bindValue(":nom", nom);

        query.bindValue(":nom_entr", nom_entr);



        return    query.exec();
}

QSqlQueryModel * classEquipe::afficher_Re_equipe(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from EQUIPE where ID_EQUIPE= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_EQUIPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_EQUIPE"));


    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ENTRAINEUR_EQUI"));


    return model;
}


QSqlQueryModel * classEquipe::afficher_equipe()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_EQUIPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_EQUIPE"));


    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ENTRAINEUR_EQUI"));


    return model;
}


bool classEquipe::chercher_equipe()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM JOUEUR WHERE ID_JOUEUR = :id ");
    query.bindValue(":id", ID_JOUEUR);

    return  query.exec(); */
}

QSqlQueryModel * classEquipe:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EQUIPE order by ID_EQUIPE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_EQUIPE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_EQUIPE"));


model->setHeaderData(2, Qt::Horizontal, QObject::tr("ENTRAINEUR_EQUI"));


    return model;
}

QSqlQueryModel * classEquipe:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EQUIPE order by ID_EQUIPE desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_EQUIPE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_EQUIPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ENTRAINEUR_EQUI"));
    return model;
}

