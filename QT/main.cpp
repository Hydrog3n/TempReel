#include "chart.h"
#include "receiver.h"
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QApplication>
#include <QtWidgets>
#include <QtNetwork>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    Chart *chart = new Chart;
    chart->setTitle("°°---TEMPÉRATURE CPU EN °C---°°");
    chart->legend()->hide();
    chart->setAnimationOptions(QChart::AllAnimations);
    QChartView chartView(chart);
    chartView.setRenderHint(QPainter::Antialiasing);

    window.setCentralWidget(&chartView);
    window.resize(500, 500);
    window.show();
    return a.exec();
}
