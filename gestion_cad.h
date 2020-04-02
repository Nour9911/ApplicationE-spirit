#ifndef GESTION_CAD_H
#define GESTION_CAD_H
#include <QString>
#include <QSqlQueryModel>

class gestion_cad
{
public:
    gestion_cad();
    gestion_cad(QString,QString,QString,QString);


    QString get_id_cadeau();
    QString get_nom_cadeau();
    QString get_nb_pts_cadeau();
    QString get_quantite_cadeau();

    bool ajouter_cadeau();
    QSqlQueryModel * afficher_cadeau();
    bool supprimer_cadeau(QString id_Scadeau);
    bool modifier_cadeau(QString, QString, QString ,QString);
    bool chercher_cadeau();
    QSqlQueryModel * afficher_Re_cadeau(QString);
    QSqlQueryModel * afficher_tri_CAD();
    QSqlQueryModel * afficher_tri_CAD_DESC();


private:
    QString  id_cadeau , nom_cadeau , nb_pts_cadeau , quantite_cadeau;

};

#endif // GESTION_CAD_H
