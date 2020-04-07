#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "gestion_eve.h"
#include "statistique_eve.h"

namespace Ui {
class evenement;
}

class evenement : public QDialog
{
    Q_OBJECT

public:
    explicit evenement(QWidget *parent = nullptr);
    ~evenement();

private slots:
    void on_Ajouter_eve_clicked();

    void on_supprimer_even_clicked();

    void on_chercher_modif_eve_clicked();

    void on_modifier_evene_clicked();


    void on_Statistique_eve_clicked();

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

private:
    Ui::evenement *ui;
    gestion_adh tmpevenement;

    statistique_eve tmpstat;

};

#endif // EVENEMENT_H
