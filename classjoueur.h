#ifndef CLASSJOUEUR_H
#define CLASSJOUEUR_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>

class classJoueur
{
private:
   QString id;
   QString nom,prenom;
    QString nom_equipe;
    QString nom_entr;
public:
    classJoueur();
    classJoueur(QString,QString,QString,QString,QString);
    QString getId() {return id;}
    bool existeee(int);
    QString getNom() {return nom;}
    QString getPrenom() {return prenom;}
    QString getNom_eq() {return nom_equipe;}
    QString getNom_entraineur() {return nom_entr;}
    bool ajouter_joueur();
    QSqlQueryModel * afficher_joueur();
    bool supprimer_joueur(QString id);
    bool modifier_joueur(QString, QString, QString ,QString ,QString);
    bool chercher_joueur();
    QSqlQueryModel * afficher_Re_joueur(QString);
    QSqlQueryModel * afficher_tri_ID();
    QSqlQueryModel * afficher_tri_ID_DESC();

};

#endif // CLASSJOUEUR_H
