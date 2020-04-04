#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSql>
#include <QDebug>
#include <QApplication>
#include <connexion.h>
#include <login.h>
#include <classrev.h>
#include <classrev.h>
#include <QMessageBox>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Connection c;
    classrev r ;
    login l ;


bool test=c.createconnect();
if(test)
{w.show();

} else {}


if( l.verifierCompte("0", "0")==1)
{
bool test2=r.stat();
if(test2) {

    // Assign names to the set of bars used
    QBarSet *set0 = new QBarSet("sponsor");
    QBarSet *set1 = new QBarSet("pub");
    QBarSet *set2 = new QBarSet("revenus (pub et sponsor)");


    // Assign values for each bar
    *set0  << 28 << 34 << 31 << 38<< 28 << 31 << 31 << 33 << 34 << 35;
    *set1  << 28 << 34 << 31 << 33<< 25 << 31 << 28 << 30 << 30 << 30;
    *set2  << 28 << 34 << 31 << 33<< 29 << 24 << 25 << 31 << 30 << 32;


    // Add all sets of data to the chart as a whole
    // 1. Bar Chart
    QBarSeries *series = new QBarSeries();

    // 2. Stacked bar chart
    // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);


    // Used to define the bar chart to display, title
    // legend,
    QChart *chart = new QChart();

    // Add the chart
    chart->addSeries(series);

    // Set title
    chart->setTitle("Batting Avg by Year");

    // Define starting animation
    // NoAnimation, GridAxisAnimations, SeriesAnimations
    chart->setAnimationOptions(QChart::AllAnimations);

    // Holds the category titles
    QStringList categories;
    categories   << "2010" << "2011" << "2012"<<"2013"  << "2014" << "2015" << "2016" << "2017" << "2018" << "2019";

    // Adds categories to the axes
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();


    chart->setAxisX(axis, series);

    // 2. Stacked Bar chart
    // chart->setAxisY(axis, series);


    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);






    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Used to change the palette
    QPalette pal = qApp->palette();

    // Change the color around the chart widget and text
    pal.setColor(QPalette::Window, QRgb(0xff9999));
    pal.setColor(QPalette::WindowText, QRgb(0x660000));

    // Apply palette changes to the application
    qApp->setPalette(pal);

    // Customize the title font
        QFont font;
        font.setPixelSize(40);
        chart->setTitleFont(font);
        chart->setTitleBrush(QBrush(Qt::cyan));
        chart->setTitle("statistique revenus");

    QMainWindow window;

    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();



return a.exec();} }
else {return a.exec();}
}


