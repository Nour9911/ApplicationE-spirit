#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"

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
void MainWindow::on_connecter_clicked()
{
    QMessageBox::information(this,"login","Agent des evenements");
    hide();
    class event a;
    a.setModal(true);
    a.exec();
}
