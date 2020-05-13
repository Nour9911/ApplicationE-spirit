#ifndef MATCH_H
#define MATCH_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class match
{
public:
    match();
    match(QString,QString,QString,QString,QString,QString);

    QString get_Idm();
    QString get_num_m();
    QString get_eq_h();
    QString get_eq_a();
    QString get_score();
    QString get_Idt();


    bool ajouter_mat();
    QSqlQueryModel * afficher_mat();
    bool supprimer_mat(QString id);
    bool affecter_mat(QString,QString);
    QSqlQueryModel * afficher_tri_IDm();
    QSqlQueryModel * afficher_tri_IDm_DESC();
    QSqlQueryModel * refresh_Idt();
    QSqlQueryModel * refresh_Idm();
    bool modifier_mat(QString, QString, QString,QString, QString, QString);
    bool chercher_mat();
    QSqlQueryModel * afficher_Re_mat(QString);
    QSqlQueryModel * afficher_dyna_mat(QString dm);





private:
    QString  Idm, num_m, eq_h, eq_a, score, Idt;

};
#endif // MATCH_H
