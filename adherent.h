#ifndef ADHERENT_H
#define ADHERENT_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "gestion_adh.h"
#include "gestion_cad.h"
#include "statistique_adherent.h"

namespace Ui {
class adherent;
}

class adherent : public QDialog
{
    Q_OBJECT

public:
    explicit adherent(QWidget *parent = nullptr);
    ~adherent();

private slots:
    void on_Ajouter_adherent_2_clicked();

    void on_supprimer_adherent_3_clicked();

    void on_Ajouter_cadeau_2_clicked();

    void on_supprimer_cadeau_2_clicked();

    void on_chercher_modif_adherent_clicked();

    void on_modifier_adherent_clicked();

    void on_modifier_cadeau_clicked();

    void on_chercher_cadeau_clicked();

    void on_Statistique_adherent_clicked();

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

    void on_tri_asc_cad_clicked();

    void on_tri_desc_cad_clicked();

private:
    Ui::adherent *ui;
    gestion_adh tmpadherent;
    gestion_cad tmpcadeau;
    statistique_adherent tmpstat;

};

#endif // ADHERENT_H
