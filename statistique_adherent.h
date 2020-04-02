#ifndef STATISTIQUE_ADHERENT_H
#define STATISTIQUE_ADHERENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVector>
#include <iterator>
#include <gestion_adh.h>

class statistique_adherent
{
public:
        QVector<gestion_adh>Tab_Stat;
    statistique_adherent();

    QVector<gestion_adh>::iterator chercher_tab_stat(QString);
    bool Ajouter_Tab_Stat(gestion_adh);
    bool Supprimer_Tab_Stat(QString);
    float Calculer_Tab_Stat(QString);

};

#endif // STATISTIQUE_ADHERENT_H
