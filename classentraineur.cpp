#include "classentraineur.h"
#include <QSqlDatabase>
#include <QSql>
#include <QDebug>

classEntraineur::classEntraineur()
{

   id=nom=prenom=nom_equipe="";

}

classEntraineur::classEntraineur(QString id,QString nom,QString prenom,QString nom_equipe)
{

    this->id=id;
    this->nom=nom;
    this->prenom=prenom;

  this->nom_equipe=nom_equipe;

}


bool classEntraineur::ajouter_entraineur()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ENTRAINEUR (ID_ENTRAINEUR, NOM_ENTRAINEUR,PRENOM_ENTRAINEUR,NOM_EQUI_ENTRE)"
                  "VALUES (:id, :nom, :prenom,:nom_equipe)");


    query.bindValue(":ID_ENTRAINEUR",id);
    query.bindValue(":NOM_ENTRAINEUR",nom);
     query.bindValue(":PRENOM_ENTRAINEUR",prenom);
     query.bindValue(":NOM_EQUI_ENTRE",nom_equipe);


    return query.exec();
}

bool classEntraineur::supprimer_entraineur(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ENTRAINEUR WHERE ID_ENTRAINEUR = :id ");
    query.bindValue(":ID_ENTRAINEUR", id);

    return  query.exec();
}

bool classEntraineur::modifier_entraineur(QString id, QString nom,QString prenom,QString nom_equipe)
{
    QSqlQuery query;


        query.prepare("UPDATE ENTRAINEUR SET NOM_ENTRAINEUR=:nom,PRENOM_ENTRAINEUR=:prenom, ID_ENTRAINEUR=:id,NOM_EQUI_ENTRE=:nom_equipe WHERE ID_ENTRAINEUR=:id");

        query.bindValue(":id", id);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom",prenom);


        query.bindValue(":nom_equipe", nom_equipe);



        return    query.exec();
}

QSqlQueryModel * classEntraineur::afficher_Re_entraineur(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from ENTRAINEUR where ID_ENTRAINEUR= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_ENTRAINEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_ENTRAINEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENTRAINEUR"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_ENTRE"));


    return model;
}


QSqlQueryModel * classEntraineur::afficher_entraineur()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_ENTRAINEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_ENTRAINEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENTRAINEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_ENTRE"));



    return model;
}


//bool classEquipe::chercher_equipe()
//{
   /* QSqlQuery query;
    query.prepare("SELECT FROM JOUEUR WHERE ID_JOUEUR = :id ");
    query.bindValue(":id", ID_JOUEUR);

    return  query.exec(); */
//}

QSqlQueryModel * classEntraineur:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ENTRAINEUR order by ID_ENTRAINEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_ENTRAINEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_ENTRAINEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENTRAINEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_ENTRE"));



    return model;
}

QSqlQueryModel * classEntraineur:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from ENTRAINEUR order by ID_ENTRAINEUR desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_ENTRAINEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_ENTRAINEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_ENTRAINEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_ENTRE"));
    return model;
}

