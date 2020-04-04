#include "classpub.h"
#include <QDebug>
#include <QString>
#include <QDate>

classpub::classpub()
{
    id_p=0;
     nom_pub="";
       duree =0;
     dated="";
     period=0;
    prix =0;
}



classpub::classpub(int id_p,QString nom_pub,int duree,QString dated,int period,int prix)
{
    this->id_p=id_p;
    this->nom_pub=nom_pub;
    this->duree=duree;
     this->dated=dated;
    this->period=period;
    this->prix=prix;
}

int classpub::get_id_p(){return  id_p;}
int classpub::get_duree(){return duree;}
QString classpub::get_nom_pub(){return nom_pub;}
QString classpub::get_dated(){return dated;}
int classpub::get_period(){return period;}
int classpub::get_prix(){return prix;}

bool classpub::existeAdminP()
{
    QSqlQuery query;
    QString n;
            query.exec("SELECT POSTE from PUB");
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



bool classpub::ajouterP()
{
 QSqlQuery query;

QString res= QString::number(id_p);
query.prepare("INSERT INTO PUB (ID_PUB, NOM_PUB, DUREE_PUB ,DATE_DEB,PERIOD_PUB ,PRIX_PUB ) "
                    "VALUES (:id_p, :nom_pub, :duree , :dated ,:period ,:prix )");
query.bindValue(":id_p", res);
query.bindValue(":nom_pub", nom_pub);
query.bindValue(":duree", duree);
query.bindValue(":dated", dated);
query.bindValue(":period", period);
query.bindValue(":prix", prix);

return    query.exec();
}

QSqlQueryModel * classpub::afficherP()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from PUB ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PUB"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PUB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE_PUB"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEB"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PERIOD_PUB"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX_PUB"));

    return model;
}

QSqlQueryModel * classpub::afficher2P(QString val)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from PUB where ID_PUB= '"+val+"'") ;
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PUB"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PUB"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE_PUB"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEB"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PERIOD_PUB"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX_PUB"));
    return model;
}

bool classpub::supprimerP(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from PUB where ID_PUB = :id_p");
query.bindValue(":id_p", res);
return    query.exec();
}

bool classpub::updatep(int id_p,QString nom_pub,int duree,QString dated ,int period,int prix)
{
  QSqlQuery query;

QString res= QString::number(id_p);
query.prepare("UPDATE PUB SET NOM_PUB= :nom_pub , DATE_DEB= :dated, DUREE_PUB=  :duree  , PERIOD_PUB= :period, PRIX_PUB=  :prix  WHERE ID_PUB= :id_p ")
                   ;
query.bindValue(":id_p", res);
query.bindValue(":nom_pub", nom_pub);
query.bindValue(":duree", duree);
query.bindValue(":dated", dated);
query.bindValue(":period", period);
query.bindValue(":prix", prix);

return    query.exec();
}

/*bool classpub::modification(int id_p,QString nom_pub,int duree)
{
    QSqlQuery query;
    QString  iden = QString::number(id_p);

    query.prepare("update pubOR set id_pPONSOR= :id_p, NOM_pubOR= :nom_pub,duree=  :duree)");

    query.bindValue(":nom_pub",nom_pub);
    query.bindValue(":id_p", iden);
    query.bindValue(":duree", duree);

    return    query.exec();
} */
void classpub::chercherP()
{
}


QSqlQueryModel * classpub:: afficher_tri_IDP()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from pub order by PRIX_PUB ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PUB"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PUB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE_PUB"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEB"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PERIOD_PUB"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX_PUB"));

    return model;
}

QSqlQueryModel * classpub:: afficher_tri_ID_DESCP()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from pub order by PRIX_PUB desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_PUB"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_PUB"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE_PUB"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_DEB"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("PERIOD_PUB"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRIX_PUB"));
    return model;
}
