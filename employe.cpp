#include "employe.h"
#include <QDebug>

employe::employe()
{
 nomEmploye="";
 mdp="";
}

employe::employe(QString nomEmploye , QString mdp)
{
  this->nomEmploye=nomEmploye;
  this->mdp=mdp;
}


int employe::existeAgent(QString nomEmploye,QString mdp)
{
   QSqlQuery query;
   QString role;
   query.exec("SELECT MDP_EMPLOYE FROM EMPLOYE WHERE NOM_EMPLOYE='"+nomEmploye+"' AND MDP_EMPLOYE='"+mdp+"'");
   qDebug()<<"Nom employe"<<nomEmploye;
                //query.first();

   while (query.next())
   {
       role=query.value("mdp_employe").toString();
       qDebug()<<"Mot de passe"<<role;

       if(role=="Agent des adhérents")
           return 1;
       else
           return 0;
   }
  return 0;
}
