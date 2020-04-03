#ifndef CLASSENTRAINEUR_H
#define CLASSENTRAINEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>

class classEntraineur
{
private:
   QString id;
   QString nom;
   QString prenom;
 QString nom_equipe;
public:
    classEntraineur();
    classEntraineur(QString,QString,QString,QString);
    QString getId() {return id;}
    bool existeee(QString);
    QString getNom() {return nom;}
     QString getPrenom() {return prenom;}
   QString getNom_equipe() {return nom_equipe;}
    bool ajouter_entraineur();
    QSqlQueryModel * afficher_entraineur();
    bool supprimer_entraineur(QString id);
    bool modifier_entraineur(QString, QString, QString,QString );
    bool chercher_entraineur();
    QSqlQueryModel * afficher_Re_entraineur(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();

};

#endif // CLASSENTRAINEUR_H
