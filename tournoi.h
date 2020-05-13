#ifndef TOURNOI_H
#define TOURNOI_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class tournoi
{
public:
    tournoi();
    tournoi(QString,QString,QString,QString,QString,QString);

    QString get_Idt();
    QString get_nom_tr();
    QString get_dis_tr();
    QString get_typ_tr();
    QString get_date_tr();
    QString get_Id_evenement();


    bool ajouter_tour();
    QSqlQueryModel * afficher_tour();
    bool supprimer_tour(QString id);
    bool modifier_tour(QString, QString,QString, QString, QString);
    bool chercher_ticket();
    QSqlQueryModel * afficher_Re_tour(QString);
    QSqlQueryModel * afficher_tri_IDt();
    QSqlQueryModel * afficher_tri_IDt_DESC();
    QSqlQueryModel * refresh_Id_evenement();
    QSqlQueryModel * refresh_Idt();
    bool affecter_tour(QString,QString);
    QSqlQueryModel * afficher_dyna_tour(QString dt);


private:
    QString  Idt, nom_tr, dis_tr, typ_tr, date_tr, Id_evenement;

};
#endif // TOURNOI_H
