#include "connection.h"

connection::connection()
{

}

bool connection::ouvrircnx()
{
   bool test=false;
   db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("Source_Projet2A");
   db.setUserName("nour");//inserer nom de l'utilisateur
   db.setPassword("nour");//inserer mot de passe de cet utilisateur

   if(db.open())

       test=true;
       else
           throw QString ("Erreur Paramétres");
       return  test;

}
void connection::fermercnx()
{
    db.close();
}