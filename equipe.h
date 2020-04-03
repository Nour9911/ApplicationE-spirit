#ifndef EQUIPE_H
#define EQUIPE_H
#include "classequipe.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class equipe;
}

class equipe : public QDialog
{
    Q_OBJECT

public:
    explicit equipe(QWidget *parent = nullptr);
    ~equipe();

private slots:
    void on_Ajouter_equipe_clicked();

    void on_supprimer_equipe_clicked();

    void on_chercher_modif_equipe_clicked();


    void on_modifier_equipe_clicked();


    void on_Statistique_equipe_clicked();

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

private:
    Ui::equipe *ui;
    classEquipe tmpequipe;

    /*statistique_adherent tmpstat;*/

};

#endif // EQUIPE_H
