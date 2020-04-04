
#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

class Connection
{
public:
    Connection();
    bool createconnect();
};


#endif // CONNEXION_H
