#include "connexion.h"
#include <exception>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projetA2");
db.setUserName("yasmine");//inserer nom de l'utilisateur
db.setPassword("yasmine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}


