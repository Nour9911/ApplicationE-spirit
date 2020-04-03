#ifndef CLASSEQUIPE_H
#define CLASSEQUIPE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>

class classEquipe
{
private:
   QString id;
   QString nom;
 QString nom_entr;
public:
    classEquipe();
    classEquipe(QString,QString,QString);
    QString getId() {return id;}
    bool existeee(int);
    QString getNom() {return nom;}
   QString getNom_entraineur() {return nom_entr;}
    bool ajouter_equipe();
    QSqlQueryModel * afficher_equipe();
    bool supprimer_equipe(QString id);
    bool modifier_equipe(QString, QString, QString );
    bool chercher_equipe();
    QSqlQueryModel * afficher_Re_equipe(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();

};

#endif // CLASSEQUIPE_H
