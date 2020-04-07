#ifndef GESTION_TOU_H
#define GESTION_TOU_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class gestion_tou
{
public:
    gestion_tou();
    gestion_tou(QString,QString,date,date,QString);

    QString get_nom_tour();
    QString get_id_tour();
    QString get_date_tour();
    QString get_fin_date();
    QString get_lieu_tour();


    bool ajouter_tourn();
    QSqlQueryModel * afficher_tourn();
    bool supprimer_tourn(QString id_Stour);
    bool modifier_tourn(QString, QString, date ,date ,QString );
    bool chercher_tourn();
    QSqlQueryModel * afficher_Re_tourn(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();



private:
    QString  nom_tour , id_tour ,lieu_tour ;
    date     date_tour , fin_tour;

};

#endif // GESTION_TOU_H
