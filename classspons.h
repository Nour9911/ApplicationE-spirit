#ifndef CLASSSPONS_H
#define CLASSSPONS_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
class classspons
{
public:
    classspons();
    classspons(int,QString,int,QString);
      QString get_nom_spnsor();
      int get_id_s();
      QString get_dates();
      int get_dons();
      bool ajouter();
      bool existeAdmin();

              bool update(int, QString, int,QString);
      //bool modification(int,QString,int);
              QSqlQueryModel * afficher();
              QSqlQueryModel * afficher2(QString);
              bool supprimer(int);
                      void chercher();
                      void search();
                      QSqlQueryModel * afficher_tri_ID();
                      QSqlQueryModel * afficher_tri_ID_DESC();

private:
   QString nom_spnsor , dates;
   int  id_s,dons;


};

#endif // CLASSSPONS_H
