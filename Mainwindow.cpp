#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsor.h"
#include "connexion.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_login_clicked()
{
    login S;
    //int poste;
        QString username = ui->lineEdit_username->text();
        QString password = ui ->lineEdit_password->text();

       // if (S.verifierCompte(ui->lineEdit_username->text(),ui ->lineEdit_password->text())==2||S.verifierCompte(ui->lineEdit_username->text(),ui ->lineEdit_password->text())==1)
        if (S.verifierCompte(ui->lineEdit_username->text(),ui ->lineEdit_password->text())==1)
        {


                    ui->lineEdit_password->clear();
                    ui->lineEdit_username->clear();
             //   if (poste==0)
                {
                    QMessageBox::information(this, "login","Admin");
                    sponsor r;
                    r.setModal(true);
                    r.exec();
                } }


            else
            {
               QMessageBox::warning(this, "login","username and password are not correct");
            }
        }
