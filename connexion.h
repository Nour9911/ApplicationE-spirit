#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class connec
{
     QSqlDatabase db;
public:
    connec();
    bool ouvrircnx();
    void fermercnx();
};
#endif // CONNEXION_H
