#include "classrev.h"
#include <QDebug>
#include <QString>
#include <QDate>

classrev::classrev()
{

    type=0;
     nom_rev="";
       sum =0;
       idr=0 ;
       ids=0 ;

}


classrev::classrev(QString nom_rev,int type,int sum, int idr,int ids)
{
    this->type=type;
    this->nom_rev=nom_rev;
    this->sum=sum;
     this->idr=idr;
    this->ids=ids;

}

int classrev::get_type(){return  type;}
int classrev::get_sum(){return sum;}
int classrev::get_idr(){return idr;}
int classrev::get_ids(){return ids;}
QString classrev::get_nom_rev(){return nom_rev;}


bool classrev::existeAdminr()
{
    QSqlQuery query;
    QString n;
            query.exec("SELECT POSTE from REVENUS");
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


QSqlQueryModel * classrev::afficherr()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("SELECT 'sponsor' , SPONSOR.NOM_SPONSOR, SPONSOR.DONS , SPONSOR.DATE_DONS FROM  SPONSOR INNER JOIN REVENUS ON (SPONSOR.ID_SPONSOR= REVENUS.ID_SPON) UNION SELECT 'pub' , PUB.NOM_PUB,   PUB.PRIX_PUB*PUB.PERIOD_PUB*PUB.DUREE_PUB , PUB.DATE_DEB FROM  PUB INNER JOIN REVENUS ON (PUB.ID_PUB= REVENUS.ID_PU)  ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REVENU"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_REVENU"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("SUM_TOTAL_REVENU"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE REVENU"));

    return model;
}

bool classrev::ajouterr(int idr)
{

  QSqlQuery query;

 QString res= QString::number(idr);
 query.prepare("INSERT INTO REVENUS (ID_SPON ) VALUES (:idr) ");
 query.bindValue(":idr", res);



 return    query.exec();

}

bool classrev::ajouterrr(int ids)
{

  QSqlQuery query;

 QString res= QString::number(ids);
 query.prepare("INSERT INTO REVENUS (ID_PU ) VALUES (:ids) ");
 query.bindValue(":ids", res);



 return    query.exec();

}

QSqlQueryModel * classrev::afficher2r(QString val)
{

    QSqlQueryModel * model= new QSqlQueryModel();
   // model->setQuery("SELECT 'sponsor' , SPONSOR.NOM_SPONSOR, SPONSOR.DONS , SPONSOR.DATE_DONS FROM  SPONSOR INNER JOIN REVENUS ON (SPONSOR.ID_SPONSOR= REVENUS.ID_SPON) UNION SELECT 'pub' , PUB.NOM_PUB, PUB.PRIX_PUB*PUB.PERIOD_PUB*PUB.DUREE_PUB , PUB.DATE_DEB FROM  PUB INNER JOIN REVENUS ON (PUB.ID_PUB= REVENUS.ID_PU) where NOM_SPONSOR= '"+val+"'" );

    model->setQuery("select 'sponsor' , SPONSOR.NOM_SPONSOR, SPONSOR.DONS , SPONSOR.DATE_DONS from SPONSOR where NOM_SPONSOR= '"+val+"' UNION SELECT 'pub' , PUB.NOM_PUB, PUB.PRIX_PUB*PUB.PERIOD_PUB*PUB.DUREE_PUB , PUB.DATE_DEB FROM  PUB  where NOM_PUB= '"+val+"'") ;

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REVENU"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_REVENU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("SUM_TOTAL_REVENU"));
    return model;
}


void classrev::chercherr()
{
}


QSqlQueryModel * classrev:: afficher_tri_IDr()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT 'sponsor' , SPONSOR.NOM_SPONSOR, SPONSOR.DONS , SPONSOR.DATE_DONS FROM  SPONSOR INNER JOIN REVENUS ON (SPONSOR.ID_SPONSOR= REVENUS.ID_SPON) UNION SELECT 'pub' , PUB.NOM_PUB,  PUB.PRIX_PUB*PUB.PERIOD_PUB*PUB.DUREE_PUB, PUB.DATE_DEB FROM  PUB INNER JOIN REVENUS ON (PUB.ID_PUB= REVENUS.ID_PU)  order by SUM_TOTAL_REVENU ASC " );

//model->setQuery("select * from REVENUS order by SUM_TOTAL_REVENU ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REVENU"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_REVENU"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("SUM_TOTAL_REVENU"));

    return model;
}

QSqlQueryModel * classrev:: afficher_tri_ID_DESCr()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from REVENUS order by SUM_TOTAL_REVENU desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("TYPE_REVENU"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_REVENU"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("SUM_TOTAL_REVENU"));
    return model;
}

bool  classrev::stat()
{ int n=1;
    if (n==1)
return true;
 else return false;

}

