#include "match.h"
#include <QDebug>
#include <QVariant>
#include <QSqlQuery>
match::match()
{

  Idm="";
  num_m="";
  eq_h="";
  eq_a="";
  score="";
  Idt="";
}
match::match( QString Idm, QString num_m, QString eq_h, QString eq_a, QString score, QString Idt)
{

    this->Idm=Idm;
    this->num_m=num_m;
    this->eq_h=eq_h;
    this->eq_a=eq_a;
    this->score=score;
    this->Idt=Idt;
}
QString match::get_Idm(){return Idm;}
QString match::get_num_m(){return num_m;}
QString match::get_eq_h(){return eq_h;}
QString match::get_eq_a(){return eq_a;}
QString match::get_score(){return score;}
QString match::get_Idt(){return Idt;}

bool match::ajouter_mat()
{
    QSqlQuery query;
    query.prepare("INSERT INTO MATCH (Idm, num_m, eq_h, eq_a, score, Idt)"
                  "VALUES (:Idm, :num_m, :eq_h, :eq_a, :score, :Idt)");



    query.bindValue(":Idm",Idm);
    query.bindValue(":num_m",num_m);
    query.bindValue(":eq_h",eq_h);
    query.bindValue(":eq_a",eq_a);
    query.bindValue(":score",score);
    query.bindValue(":Idt",Idt);


    return query.exec();
}
bool match::supprimer_mat(QString ids)
{
    QSqlQuery query;
    query.prepare("DELETE FROM MATCH WHERE Idm = :ids ");
    query.bindValue(":ids",ids);

    return  query.exec();
}
bool match::affecter_mat(QString Idt, QString Idm)
{
    QSqlQuery query;


        query.prepare("UPDATE MATCH SET Idt=:Idt WHERE Idm=:Idm");

        query.bindValue(":Idm", Idm);
        query.bindValue(":Idt", Idt);



        return    query.exec();
}


QSqlQueryModel * match:: refresh_Idt()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select Idt from TOUR order by Idt asc ");

    return model;
}

QSqlQueryModel * match:: refresh_Idm()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select Idm from MATCH order by Idm asc ");

    return model;
}
QSqlQueryModel * match:: afficher_tri_IDm()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATCH order by Idm");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt "));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_MATCH"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("EQUIPE_h"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Equipe_a"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("score"));
    return model;
}

QSqlQueryModel * match:: afficher_tri_IDm_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATCH order by Idm desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt "));
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_MATCH"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("EQUIPE_h"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Equipe_a"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("score"));
    return model;
}
bool match::modifier_mat(QString Idt, QString Idm, QString num_m, QString eq_h, QString eq_a, QString score)
{
    QSqlQuery query;


        query.prepare("UPDATE MATCH SET Idt=:Idt, num_m=:num_m, eq_h=:eq_h, eq_a=:eq_a, score=:score WHERE Idm=:Idm");

        query.bindValue(":Idt", Idt);
        query.bindValue(":Idm", Idm);
        query.bindValue(":num_m", num_m);
        query.bindValue(":eq_h",eq_h);
        query.bindValue(":eq_a",eq_a);
        query.bindValue(":score",score);



        return    query.exec();
}
QSqlQueryModel * match::afficher_Re_mat(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from MATCH where Idm= '"+val+"'") ;



    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_MATCH"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EQUIPE_h"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Equipe_a"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("score"));
    return model;
}
QSqlQueryModel * match::afficher_dyna_mat(QString dm)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->
            setQuery("select * from MATCH where (MATCH.Idm LIKE '"+dm+"%')");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Idt "));
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_MATCH"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM_MATCH"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("EQUIPE_h"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Equipe_a"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("score"));

    return model;
}
