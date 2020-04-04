#ifndef CLASSREV_H
#define CLASSREV_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>

class classrev
{
public:
    classrev();


    classrev(QString,int,int,int,int);
      QString get_nom_rev();

      int get_type();
      int get_sum();
int get_idr();
int get_ids();
      bool existeAdminr();

              bool updater(QString, int,int,int,int);
      //bool modification(int,QString,int);
              QSqlQueryModel * afficherr();
              QSqlQueryModel * afficher2r(QString);

                      void chercherr();
                      void searchr();
                      QSqlQueryModel * afficher_tri_IDr();
                      QSqlQueryModel * afficher_tri_ID_DESCr();

bool stat();
                     bool ajouterr(int);
                     bool ajouterrr(int);
private:
   QString nom_rev ;
   int  type , sum , idr ,ids ;

};

#endif // CLASSREV_H
