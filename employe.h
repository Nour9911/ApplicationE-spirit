#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class employe
{
public:
    employe();
    employe(QString,QString);
    QString get_nomEmploye;
    QString get_mdp;

    int existeAgent(QString,QString);


private:
    QString nomEmploye;
    QString mdp;
};

#endif // EMPLOYE_H
