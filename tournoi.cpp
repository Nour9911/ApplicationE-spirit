#include "tournoi.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>

tournoi::tournoi()
{

  Idt="";
  nom_tr="";
  dis_tr="";
  typ_tr="";
  date_tr="";
  Id_evenement="";
}

tournoi::tournoi( QString Idt, QString nom_tr, QString dis_tr, QString typ_tr, QString date_tr, QString Id_evenement)
{

    this->Idt=Idt;
    this->nom_tr=nom_tr;
    this->dis_tr=dis_tr;
    this->typ_tr=typ_tr;
    this->date_tr=date_tr;
    this->Id_evenement=Id_evenement;
}


QString tournoi::get_Idt(){return Idt;}
QString tournoi::get_nom_tr(){return nom_tr;}
QString tournoi::get_dis_tr(){return dis_tr;}
QString tournoi::get_typ_tr(){return typ_tr;}
QString tournoi::get_date_tr(){return date_tr;}
QString tournoi::get_Id_evenement(){return Id_evenement;}


bool tournoi::ajouter_tour()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TOUR (Idt, nom_tr, dis_tr, typ_tr, date_tr, Id_evenement)"
                  "VALUES (:Idt, :nom_tr, :dis_tr, :typ_tr, :date_tr, :Id_evenement)");



    query.bindValue(":Idt",Idt);
    query.bindValue(":nom_tr",nom_tr);
    query.bindValue(":dis_tr",dis_tr);
    query.bindValue(":typ_tr",typ_tr);
    query.bindValue(":date_tr",date_tr);
    query.bindValue(":Id_evenement",Id_evenement);


    return query.exec();
}
bool tournoi::supprimer_tour(QString ids)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TOUR WHERE Idt = :ids ");
    query.bindValue(":ids",ids);

    return  query.exec();
}

bool tournoi::affecter_tour(QString Idt, QString Id_evenement)
{
    QSqlQuery query;


        query.prepare("UPDATE TOUR SET Id_evenement=:Id_evenement WHERE Idt=:Idt");

        query.bindValue(":Idt", Idt);
        query.bindValue(":Id_evenement", Id_evenement);



        return    query.exec();
}

QSqlQueryModel * tournoi:: refresh_Id_evenement()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select Id_evenement from EVEN order by Id_evenement asc ");

    return model;
}

QSqlQueryModel * tournoi:: refresh_Idt()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select Idt from TOUR order by Idt asc ");

    return model;
}
QSqlQueryModel * tournoi:: afficher_tri_IDt()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TOUR order by Idt");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id_evenement "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Idt"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom_tr"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("dis_tr"));
model->setHeaderData(4,Qt::Horizontal, QObject::tr("typ_tr"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("date_tr"));
    return model;
}

QSqlQueryModel * tournoi:: afficher_tri_IDt_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from TOUR order by Idt desc ");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_tr"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dis_tr"));
model->setHeaderData(3,Qt::Horizontal, QObject::tr("typ_tr"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_tr"));
    return model;
}
bool tournoi::modifier_tour(QString Idt, QString nom_tr, QString dis_tr, QString typ_tr, QString date_tr)
{
    QSqlQuery query;


        query.prepare("UPDATE TOUR SET nom_tr=:nom_tr, dis_tr=:dis_tr, typ_tr=:typ_tr, date_tr=:date_tr WHERE Idt=:Idt");


        query.bindValue(":Idt", Idt);
        query.bindValue(":date_tr",date_tr);
        query.bindValue(":nom_tr", nom_tr);
        query.bindValue(":dis_tr",dis_tr);
        query.bindValue(":typ_tr",typ_tr);




        return    query.exec();
}
QSqlQueryModel * tournoi::afficher_Re_tour(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from TOUR where Idt= '"+val+"'") ;



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("discipline"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

    return model;
}

QSqlQueryModel * tournoi::afficher_dyna_tour(QString dt)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from TOUR where (TOUR.Idt LIKE '"+dt+"%')");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("discipline"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));

    return model;
}
