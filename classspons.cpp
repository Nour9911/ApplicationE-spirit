#include "classspons.h"
#include <QDebug>
#include <QString>
#include <QDate>

classspons::classspons()
{
    id_s=0;
     nom_spnsor="";
       dons =0;
     dates="";

}




classspons::classspons(int id_s,QString nom_spnsor,int dons,QString dates)
{
    this->id_s=id_s;
    this->nom_spnsor=nom_spnsor;
    this->dons=dons;
     this->dates=dates;
}

int classspons::get_id_s(){return  id_s;}
int classspons::get_dons(){return dons;}
QString classspons::get_nom_spnsor(){return nom_spnsor;}
QString classspons::get_dates(){return dates;}

bool classspons::existeAdmin()
{
    QSqlQuery query;
    QString n;
            query.exec("SELECT POSTE from SPONSOR");
            while (query.next())
            {
                n=query.value("POSTE").toString();
                if (n=="Admin")
                {
                    return true;
                }
            }
    return false;
}
bool classspons::ajouter()
{
 QSqlQuery query;

QString res= QString::number(id_s);
query.prepare("INSERT INTO SPONSOR (ID_SPONSOR, NOM_SPONSOR, DONS ,DATE_DONS) "
                    "VALUES (:id_s, :nom_spnsor, :dons , :dates)");
query.bindValue(":id_s", res);
query.bindValue(":nom_spnsor", nom_spnsor);
query.bindValue(":dons", dons);
query.bindValue(":dates", dates);



return    query.exec();
}

QSqlQueryModel * classspons::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SPONSOR ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DONS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DONS"));
    return model;
}

QSqlQueryModel * classspons::afficher2(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from SPONSOR where ID_SPONSOR= '"+val+"'") ;
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DONS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DONS"));

    return model;
}

void classspons::chercher()
{
}

bool classspons::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from SPONSOR where ID_SPONSOR = :id_s");
query.bindValue(":id_s", res);
return    query.exec();
}

bool classspons::update(int id_s,QString nom_spnsor,int dons,QString dates )
{
  QSqlQuery query;

QString res= QString::number(id_s);
query.prepare("UPDATE SPONSOR SET NOM_SPONSOR= :nom_spnsor , DATE_DONS= :dates, DONS=  :dons  WHERE ID_SPONSOR= :id_s ")
                   ;
query.bindValue(":id_s", res);
query.bindValue(":nom_spnsor", nom_spnsor);
query.bindValue(":dons", dons);
query.bindValue(":dates", dates);
return    query.exec();
}

/*bool classspons::modification(int id_s,QString nom_spnsor,int dons)
{
    QSqlQuery query;
    QString  iden = QString::number(id_s);

    query.prepare("update SPONSOR set ID_SPONSOR= :id_s, NOM_SPONSOR= :nom_spnsor,DONS=  :dons)");

    query.bindValue(":nom_spnsor",nom_spnsor);
    query.bindValue(":id_s", iden);
    query.bindValue(":dons", dons);

    return    query.exec();
} */



QSqlQueryModel * classspons:: afficher_tri_ID()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from SPONSOR order by DONS ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DONS"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DONS"));

    return model;
}

QSqlQueryModel * classspons:: afficher_tri_ID_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_SPONSOR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SPONSOR"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DONS"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DONS"));
    return model;
}

