#ifndef GESTION_EVE_H
#define GESTION_EVE_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class gestion_eve
{
public:
    gestion_eve();
    gestion_eve(QString,QString);

    QString get_nom_eve();
    QString get_id_eve();


    bool ajouter_eve();
    QSqlQueryModel * afficher_eve();
    bool supprimer_eve(QString id_Seve);
    bool modifier_evene(QString, QString);
    bool chercher_eve();
    QSqlQueryModel * afficher_Re_eve(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();



private:
    QString  nom_eve , id_eve ;

};

#endif // GESTION_EVE_H
