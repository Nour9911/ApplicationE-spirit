#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   connec c;
   bool test= c.ouvrircnx();
   MainWindow w;
              if(test)
{
        w.show();


    }
          else
               QMessageBox::information(nullptr, QObject::tr("database is not open"),
                           QObject::tr("Echec de la connexion.\n""Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
