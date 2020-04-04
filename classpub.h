#ifndef CLASSPUB_H
#define CLASSPUB_H
#include <QString>
#include <QSqlQuery>
#include <QDate>
#include <QSqlQueryModel>
class classpub
{
public:
    classpub();

    classpub(int,QString,int,QString,int,int);
      QString get_nom_pub();
      int get_id_p();
      QString get_dated();
      int get_period();
      int get_prix();
      int get_duree();

      bool ajouterP();
      bool existeAdminP();

              bool updatep(int, QString, int,QString,int,int);
      //bool modification(int,QString,int);
              QSqlQueryModel * afficherP();
              QSqlQueryModel * afficher2P(QString);
              bool supprimerP(int);
                      void chercherP();
                      void searchP();
                      QSqlQueryModel * afficher_tri_IDP();
                      QSqlQueryModel * afficher_tri_ID_DESCP();
                      QSqlQueryModel * stat();
                      QSqlQueryModel * stat1();
                      QSqlQueryModel * stat2();
                      QSqlQueryModel * stat3();
                      QSqlQueryModel * stat4();
                      QSqlQueryModel * stat5();
                      QSqlQueryModel * stat6();
                      QSqlQueryModel * stat7();
                      QSqlQueryModel * stat8();
                      QSqlQueryModel * stat9();
                      QSqlQueryModel * stat10();
private:
   QString nom_pub , dated ;
   int  id_p , prix , duree ,period ;


};


#endif // CLASSPUB_H
