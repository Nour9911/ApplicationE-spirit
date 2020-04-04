
#include "ui_sponsor.h"
#include <QMessageBox>
#include <QPixmap>
#include <QSound>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QPrintDialog>
#include <QPrinter>
#include <QDate>


pub::pub(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pub)
{
    ui->setupUi(this);
    ui->tabpub->setModel(tmppub.afficher());

 QColor fontBold; fontBold.setBlue(true);

 this->setWindowTitle("GESTION DES pub");
}

pub::~pub()
{
    delete ui;
}


void pub::on_pb_ajouterp_clicked()
{
    int id_p = ui->lineEdit_id_p->text().toInt();
    QString nom_pub = ui->lineEdit_nom->text();
    int duree = ui->lineEdit_duree->text().toInt();
    QString dated = ui->lineEdit_date_d->text();
     QString datef = ui->lineEdit_date_f->text();
    int prix = ui->lineEdit_prix->text().toInt();

  classpub S(id_p, nom_pub, duree, dated,datef ,prix);
  bool test=S.ajouter();
  if(test)
{ui->tabpub->setModel(tmppub.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un pub"),
                  QObject::tr("pub ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un pub"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void pub::on_pb_supprimerp_clicked()
{


int id_p = ui->lineEdit_id_p->text().toInt();
bool test=tmppub.supprimer(id_p);
if(test)
{ui->tabpub->setModel(tmppub.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un pub"),
                QObject::tr("pub supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void pub::on_updatep_clicked()
{

    int id_p = ui->lineEdit_id_4->text().toInt();
    QString nom_pub= ui->lineEdit_nom_4->text();
    int duree = ui->lineEdit_duree_2->text().toInt();
   QString dated = ui->lineEdit_date_d_2->text();
    QString datef = ui->lineEdit_date_f_2->text();
     int prix = ui->lineEdit_prix_2->text().toInt();

     bool test=tmppub.update(id_p,nom_pub,duree, dated,datef,prix);


    if(test)
    {ui->tabpub->setModel(tmppub.afficher());//refresh

        QMessageBox::information(nullptr, QObject::tr("Modifier un pub"),
                    QObject::tr("pub modifié.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
      {  QMessageBox::critical(nullptr, QObject::tr("Modifier Un pub"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}}

/*
void pub::on_update_clicked()
{

    classpubs  c;
    int id_p = ui->lineEdit_id_22->text().toInt();
    QString nom_pub = ui->lineEdit_nom_22->text();
    int duree = ui->lineEdit_duree_22->text().toInt();

    bool test=c.modification(id_p,nom_pub,duree);


    if(test)

    {

        ui->tabpub->setModel(tmppub.afficher());//refresh
                QMessageBox::information(nullptr, QObject::tr("Modifier un pub"),
                            QObject::tr("pub modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
         }

   else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Un pubs"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    }

*/





void pub::on_searchp_clicked()
{
    QString val = ui->lineEdit_nom_pub_22->text();

        ui->tabpub_2->setModel(tmppub.afficher2(val));
}


void pub::on_pdfp_clicked()
{
    QString strStream;
       QTextStream out(&strStream);

       const int rowCount = ui->tabpub->model()->rowCount();
       const int columnCount = ui->tabpub->model()->columnCount();
       out <<"<html>\n"
             "<head>\n"
              "<meta Content=\"Text/html; charset=Windows-1251\">\n"
           << "<title>ERP - COMmANDE LIST<title>\n "
           << "</head>\n"
           "<body bgcolor=#ffffff link=#5000A0>\n"

              "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
             "</br> </br>";
       // headers
       out << "<thead><tr bgcolor=#d6e5ff>";
       for (int column = 0; column < columnCount; column++)
           if (!ui->tabpub->isColumnHidden(column))
               out << QString("<th>%1</th>").arg(ui->tabpub->model()->headerData(column, Qt::Horizontal).toString());
       out << "</tr></thead>\n";

       // data table
       for (int row = 0; row < rowCount; row++) {
           out << "<tr>";
           for (int column = 0; column < columnCount; column++) {
               if (!ui->tabpub->isColumnHidden(column)) {
                   QString data =ui->tabpub->model()->data(ui->tabpub->model()->index(row, column)).toString().simplified();
                   out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
               }
           }
           out << "</tr>\n";
       }
       out <<  "</table>\n"
           "</body>\n"
           "</html>\n";

       QTextDocument *document = new QTextDocument();
       document->setHtml(strStream);

       QPrinter printer;

       QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
       if (dialog->exec() == QDialog::Accepted) {
           document->print(&printer);
       }

       delete document;
}


void pub::on_radioButton_5p_clicked()
{

       ui->tabpub->setModel(tmppub.afficher_tri_ID());
}

void pub::on_radioButton_6p_clicked()
{

       ui->tabpub->setModel(tmppub.afficher_tri_ID_DESC());
}
