#ifndef JOUEUR_H
#define JOUEUR_H
#include "classjoueur.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class joueur;
}

class joueur: public QDialog
{
    Q_OBJECT

public:
    explicit joueur(QWidget *parent = nullptr);
    ~joueur();

private slots:
    void on_Ajouter_joueur_clicked();

    void on_supprimer_joueur_clicked();

    void on_chercher_modif_joueur_clicked();


    void on_modifier_joueur_clicked();


    void on_Statistique_joueur_clicked();

    void on_tri_asc_clicked();

    void on_tri_desc_clicked();

private:
    Ui::joueur *ui;
    classJoueur tmpjoueur;

    /*statistique_adherent tmpstat;*/

};

#endif // JOUEUR_H
