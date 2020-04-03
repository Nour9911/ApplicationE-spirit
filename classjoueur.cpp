#include "classjoueur.h"


#include <QSqlDatabase>
#include <QSql>
#include <QDebug>



classJoueur::classJoueur()
{

   id=nom=prenom=nom_equipe=nom_entr="";

}

classJoueur::classJoueur(QString id,QString nom,QString prenom,QString nom_equipe,QString nom_entr)
{

    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->nom_equipe=nom_equipe;
    this->nom_entr=nom_entr;

}


bool classJoueur::ajouter_joueur()
{
    QSqlQuery query;
    query.prepare("INSERT INTO JOUEUR (ID_JOUEUR, NOM_JOUEUR, PRENOM_JOUEUR, NOM_EQUI,NOM_ENTRE_JOUEUR)"
                  "VALUES (:id, :nom, :prenom, :nom_equipe, :nom_entr)");


    query.bindValue(":ID_JOUEUR",id);
    query.bindValue(":NOM_JOUEUR",nom);
    query.bindValue(":PRENOM_JOUEUR",prenom);
    query.bindValue(":NOM_EQUI",nom_equipe);
    query.bindValue(":NOM_ENTRE_JOUEUR",nom_entr);


    return query.exec();
}

bool classJoueur::supprimer_joueur(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM JOUEUR WHERE ID_JOUEUR = :id ");
    query.bindValue(":ID_JOUEUR", id);

    return  query.exec();
}

bool classJoueur::modifier_joueur(QString id, QString nom, QString prenom , QString nom_equipe ,QString nom_entr)
{
    QSqlQuery query;


        query.prepare("UPDATE JOUEUR SET NOM_JOUEUR=:nom , PRENOM_JOUEUR=:prenom, ID_JOUEUR=:id, NOM_EQUI=:nom_equipe,NOM_ENTRE_JOUEUR=:nom_entr  WHERE ID_JOUEUR=:id");

        query.bindValue(":id", id);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":nom_equipe",nom_equipe);
        query.bindValue(":nom_entr", nom_entr);



        return    query.exec();
}

QSqlQueryModel * classJoueur::afficher_Re_joueur(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from JOUEUR where ID_JOUEUR= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_JOUEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_ENTRE_JOUEUR"));


    return model;
}


QSqlQueryModel * classJoueur::afficher_joueur()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("SELECT * FROM JOUEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_JOUEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_JOUEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_JOUEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_ENTRE_JOUEUR"));

    return model;
}


bool classJoueur::chercher_joueur()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM JOUEUR WHERE ID_JOUEUR = :id ");
    query.bindValue(":id", ID_JOUEUR);

    return  query.exec(); */
}

QSqlQueryModel * classJoueur:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from JOUEUR order by ID_JOUEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_JOUEUR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_JOUEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_JOUEUR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_ENTRE_JOUEUR"));

    return model;
}

QSqlQueryModel * classJoueur:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from JOUEUR order by ID_JOUEUR desc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM_JOUEUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_JOUEUR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_JOUEUR"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM_EQUI_JOUEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM_ENTRE_JOUEUR"));
    return model;
}

