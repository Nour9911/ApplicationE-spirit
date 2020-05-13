#include "evenement.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>

evenement::evenement()
{
  Id_evenement="";
  Nom="";
  Lieu="";
}

evenement::evenement( QString Id_evenement, QString Nom, QString Lieu)
{
    this->Id_evenement=Id_evenement;
    this->Nom=Nom;
    this->Lieu=Lieu;

}

QString evenement::get_Id_evenement(){return Id_evenement;}
QString evenement::get_Nom(){return Nom;}
QString evenement::get_Lieu(){return Lieu;}

bool evenement::ajouter_evenement()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EVEN (Id_Evenement, Nom, Lieu)"
                  "VALUES (:Id_Evenement, :Nom, :Lieu)");


    query.bindValue(":Id_Evenement",Id_evenement);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Lieu",Lieu);

    return query.exec();
}

bool evenement::supprimer_evenement(QString id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EVEN WHERE Id_evenement = :id ");
    query.bindValue(":id",id);

    return  query.exec();
}


QSqlQueryModel * evenement:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVEN order by Id_evenement asc");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Evenement"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));

    return model;
}



QSqlQueryModel * evenement:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EVEN order by Id_evenement desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_Evenement"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));

    return model;
}


bool evenement::modifier_evenement(QString Id_evenement, QString Nom, QString Lieu)
{
    QSqlQuery query;


        query.prepare("UPDATE EVEN SET Nom=:Nom , Lieu=:Lieu  WHERE Id_evenement=:Id_evenement");

        query.bindValue(":Id_evenement", Id_evenement);
        query.bindValue(":Nom", Nom);
        query.bindValue(":Lieu", Lieu);



        return    query.exec();
}






QSqlQueryModel * evenement::afficher_Re_evenement(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("SELECT * from EVEN where Id_evenement= '"+val+"'") ;


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_evenement "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));


    return model;
}
bool evenement::chercher_evenement()
{
   /* QSqlQuery query;
    query.prepare("SELECT FROM EVEN WHERE id_evenement = :id_evenement ");
    query.bindValue(":id_evenement", id_evenement);

    return  query.exec(); */
}




QSqlQueryModel * evenement::afficher_dyna_even(QString de)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from EVEN where (EVEN.id_evenement LIKE '"+de+"%')");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_evenement "));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lieu"));

    return model;
}
