#include "statistique_adherent.h"
#include <QString>


statistique_adherent::statistique_adherent()
{
     QString  nom_adherent , id_adherent , prenom_adherent , numero_adherent , email_adherent , nombre_pts_adherent;
        QSqlQuery query;
        query.prepare("select * from adherent ");
        if(query.exec())
        {
                       do
                        {

                            nom_adherent=(query.value(0).toString());
                            id_adherent=(query.value(1).toString());
                            prenom_adherent=(query.value(2).toString());
                            numero_adherent=(query.value(3).toString());
                            email_adherent=(query.value(4).toString());
                            nombre_pts_adherent=(query.value(5).toString());


                            gestion_adh ga(nom_adherent,id_adherent,prenom_adherent,numero_adherent,email_adherent,nombre_pts_adherent);
                            Tab_Stat.push_back(ga);
                        }
                    while(query.next());
        }

}


QVector<gestion_adh>::iterator statistique_adherent::chercher_tab_stat(QString id_adherent)
{
    QVector<gestion_adh>::iterator it;
    for(it=Tab_Stat.begin();it!=Tab_Stat.end();it++)
    {
        if(it->get_id_adherent()==id_adherent){return it;}
    }
    return Tab_Stat.end();
}


bool statistique_adherent:: Ajouter_Tab_Stat(gestion_adh ga)
{
    if(chercher_tab_stat(ga.get_id_adherent())!=Tab_Stat.end()){return false;}
    else{Tab_Stat.push_back(ga);return true;}
}


bool statistique_adherent::Supprimer_Tab_Stat(QString id_adherent)
{
        QVector<gestion_adh>::iterator it=chercher_tab_stat(id_adherent);
        if(it==Tab_Stat.end()){return false;}
        else{Tab_Stat.erase(it);it--;return true;}
}

float statistique_adherent:: Calculer_Tab_Stat(QString nom_adherent)
{
 int cpt1=0,cpt2=0;
 QVector<gestion_adh>::iterator it1;
 for(it1=Tab_Stat.begin();it1!=Tab_Stat.end();it1++)
 {
     if(it1->get_nom_adherent()==nom_adherent)
     {
                if(it1->get_nombre_pts_adherent() <= 100 ){cpt1++;}
                else {cpt2++;}
     }

 }

if((cpt1+cpt2)!=0){return ((cpt1*100)/(cpt1+cpt2));}
else{return (0.0);}
}

