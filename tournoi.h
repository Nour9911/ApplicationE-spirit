#ifndef TOURNOI_H
#define TOURNOI_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "gestion_tou.h"



namespace Ui {
class tournoi;
}

class tournoi : public QDialog
{
    Q_OBJECT

public:
    explicit tournoi(QWidget *parent = nullptr);
    ~tournoi();

private slots:
    void on_Ajouter_tourn_clicked();

    void on_supprimer_tourn_clicked();

    void on_chercher_modif_tourn_clicked();

    void on_modifier_tourn_clicked();

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

private:
    Ui::tournoi *ui;
    gestion_tou tmptournoi;



};

#endif // TOURNOI_H
