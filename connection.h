#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class connection
{
    QSqlDatabase db;
public:
    connection();
    bool ouvrircnx();
    void fermercnx();
};

#endif // CONNECTION_H
