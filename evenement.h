#ifndef EVENEMENT_H
#define EVENEMENT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class evenement
{
public:
    evenement();
    evenement(QString,QString,QString);

    QString get_Id_evenement();
    QString get_Nom();
    QString get_Lieu();


    bool ajouter_evenement();
    QSqlQueryModel * afficher_evenement();
    bool supprimer_evenement(QString id);
    bool modifier_evenement(QString, QString, QString);
    bool chercher_evenement();
    QSqlQueryModel * afficher_Re_evenement(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();
    QSqlQueryModel * afficher_dyna_even(QString de);



private:
    QString  Id_evenement , Nom , Lieu;

};
#endif // EVENEMENT_H
