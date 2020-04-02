#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adherent.h"
#include "employe.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LOGIN");
    this->setWindowIcon(QIcon("../PROJECT_NOUR_F/e-spirit.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connecter_clicked()
{
    employe e;
    int mdp;
    QString username = ui->login_2->text();
    QString password = ui->mdp->text();

    if(e.existeAgent(ui->login_2->text(),ui->mdp->text())==1 || e.existeAgent(ui->login_2->text(),ui->mdp->text())==2)
    {
        mdp=e.existeAgent(ui->login_2->text(),ui->mdp->text());

        ui->login_2->clear();
        ui->mdp->clear();

        if (mdp!=1)
        {

            QMessageBox::information(this,"login","Username et mot de passe incorrects");

        }

    else if(mdp==2)
    {
            QMessageBox::information(this,"login","Agent des reservation");
            hide();
            class adherent a;
            a.setModal(true);
            a.exec();
    }
    }
        else
        {
        QMessageBox::information(this,"login","Agent des adhérents");
        hide();
        class adherent a;
        a.setModal(true);
        a.exec();

        }
}
