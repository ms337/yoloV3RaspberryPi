#include "histogram.h"
#include "ui_histogram.h"
#include <iostream>
#include <string>

Histogram::Histogram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Histogram)
{
    ui->setupUi(this);

    QVector<double> datax = QVector<double>() << 1 << 2 << 3 << 4;
    QVector<double> dataArr[10];
    for (int i = 0; i < 3; i++) {
        QVector<double> datay = QVector<double>() << 0.6 << 0.5 << 0.3 << 0.15;
        dataArr[i] = datay;
    }

    QCPBarsGroup *group = new QCPBarsGroup(ui->widget);

    QVector<QString> zones(50);
    zones[0] = "Zone A";
    zones[1] = "Zone B";
    zones[2] = "Zone C";

    for (int i = 0; i < 3; i++) {
        QCPBars *bars = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
        bars->setData(datax, dataArr[i]);
        bars->setBrush(QColor(rand()%255, rand()%255, rand()%255, 50));
        bars->setPen(QColor(rand()%255, rand()%255, rand()%255));
        bars->setWidth(0.15);
        bars->setBarsGroup(group);
        bars->setName(zones[i]);
    }

    ui->widget->legend->setVisible(true);
    ui->widget->xAxis->setRange(0.1, 4.9);
    ui->widget->xAxis->setLabel("Zone");
    ui->widget->yAxis->setRange(0, 0.7);
    ui->widget->yAxis->setLabel("Number of occurences");
    ui->widget->replot();

}

Histogram::~Histogram()
{
    delete ui;
}
