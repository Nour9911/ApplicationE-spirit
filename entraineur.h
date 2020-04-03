#ifndef ENTRAINEUR_H
#define ENTRAINEUR_H

#include "classentraineur.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class entraineur;
}

class entraineur: public QDialog
{
    Q_OBJECT

public:
    explicit entraineur(QWidget *parent = nullptr);
    ~entraineur();

private slots:
    void on_Ajouter_entraineur_clicked();

    void on_supprimer_entraineur_clicked();

    void on_chercher_modif_entraineur_clicked();


    void on_modifier_entraineur_clicked();
       void on_tri_asc_clicked();

    void on_tri_desc_clicked();

private:
    Ui::entraineur *ui;
    classEntraineur tmpentraineur;



};
#endif // ENTRAINEUR_H
