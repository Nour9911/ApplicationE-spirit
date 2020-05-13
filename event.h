#ifndef EVENT_H
#define EVENT_H
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "evenement.h"
#include "tournoi.h"
#include "match.h"

#include <QDialog>

namespace Ui {
class event;
}

class event : public QDialog
{
    Q_OBJECT

public:
    explicit event(QWidget *parent = nullptr);
    ~event();
private slots:

    void on_ajouter_even_clicked();

    void on_supprimer_even_clicked();

    void on_chercher_modif_eve_clicked();

    void on_modifier_even_clicked();

    void on_tri_asc_even_clicked();

    void on_tri_desc_even_clicked();

    void on_ajouter_tour_clicked();

    void on_supprimer_tourn_clicked();

    void on_chercher_modif_tour_clicked();

    void on_modifier_tour_clicked();

    void on_tri_asc_tour_clicked();

    void on_tri_desc_tour_clicked();

    void on_pushButton_clicked();

    void on_chercher_res_2_textChanged(const QString &arg1);

    void on_chercher_eve_textChanged(const QString &arg1);

    void on_ajouter_mat_clicked();

    void on_supprimer_mat_clicked();

    void on_pushButton_2_clicked();
    void on_tri_asc_mat_clicked();

        void on_tri_desc_mat_clicked();
        void on_modifier_mat_clicked();
         void on_chercher_modif_mat_clicked();

         void on_chercher_matt_textChanged(const QString &arg1);

private:
    Ui::event *ui;
    evenement tmpevenement;
    tournoi tmptournoi;
    match tmpmatch;
};

#endif // EVENT_H
