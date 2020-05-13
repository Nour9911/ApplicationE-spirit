#include "connexion.h"
connec::connec()
{

}
bool connec::ouvrircnx()
{
    db=db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet");
    db.setUserName("louay");
    db.setPassword("louay");
    if(db.open())
        return true;

        return false ;
}
void connec::fermercnx()
{db.close();}
