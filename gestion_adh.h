#ifndef GESTION_ADH_H
#define GESTION_ADH_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class gestion_adh
{
public:
    gestion_adh();
    gestion_adh(QString,QString,QString,QString,QString,QString);

    QString get_nom_adherent();
    QString get_id_adherent();
    QString get_prenom_adherent();
    QString get_numero_adherent();
    QString get_email_adherent();
    QString get_nombre_pts_adherent();

    bool ajouter_adherent();
    QSqlQueryModel * afficher_adherent();
    bool supprimer_adherent(QString id_Sadherent);
    bool modifier_adherent(QString, QString, QString ,QString ,QString ,QString);
    bool chercher_adherent();
    QSqlQueryModel * afficher_Re_adherent(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();



private:
    QString  nom_adherent , id_adherent , prenom_adherent , numero_adherent , email_adherent , nombre_pts_adherent;

};

#endif // GESTION_ADH_H
