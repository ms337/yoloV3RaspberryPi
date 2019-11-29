/**
 * @file histogram.cpp
 * @author Allen
 * @brief 
 * @version 0.1
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "histogram.h"
#include "ui_histogram.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief Construct a new Histogram:: Histogram object
 * 
 * @param parent 
 */
Histogram::Histogram(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::Histogram)
{
    ui->setupUi(this);

    DatabaseWriter *dbWriter = DatabaseWriter::getInstance();

    vector<struct myObj> vObj = dbWriter->getVector();

    /**
     * Input: hash table where key is object and value is an array of ints
     * Each array will be of length nZones (array index refers to which zone, content of array is occurences of object in zone)
     * Length of hash table is nObjects
    **/

    int nZones = dbWriter->getZones(); //get this through a getter function in mainwindow

    int nObjects = vObj.size(); //this is the number of structs
    int maxOccurrences = 10;

    QVector<QString> objects(nObjects);

    int countObjIndex = 0;
    for (auto found : vObj) //iterate over vector of structs
    {
        objects[countObjIndex] = QString::fromStdString(found.name);
        countObjIndex++;
    }

    //nZones is the number that you get when you specify how many zones you want in mainwindow
    QVector<double> datax(nZones);
    for (int i = 0; i < nZones; i++)
    {
        datax[i] = i + 1;
    }
    QVector<double> dataArr[nObjects];
    for (int i = 0; i < nObjects; i++)
    {
        QVector<double> datay(nZones);
        for (int j = 0; j < nZones; j++)
        {
            datay[j] = vObj[i].zones[j];
        }
        dataArr[i] = datay;
    }

        QCPBarsGroup *group = new QCPBarsGroup(ui->widget);

    for (int i = 0; i < nObjects; i++)
    {
        QCPBars *bars = new QCPBars(ui->widget->xAxis, ui->widget->yAxis);
        bars->setData(datax, dataArr[i]);
        bars->setBrush(QColor(rand() % 255, rand() % 255, rand() % 255, 50));
        bars->setPen(QColor(rand() % 255, rand() % 255, rand() % 255));
        bars->setWidth(1 / nObjects);
        bars->setBarsGroup(group);
        bars->setName(objects[i]);
    }

    ui->widget->legend->setVisible(true);
    ui->widget->xAxis->setRange(0, nZones + 1);
    ui->widget->xAxis->setLabel("Zone");
    ui->widget->yAxis->setRange(0, maxOccurrences + 1);
    ui->widget->yAxis->setLabel("Number of occurrences");
    //ui->widget->rescaleAxes();
    ui->widget->replot();
}
/**
 * @brief Destroy the Histogram:: Histogram object
 * 
 */

Histogram::~Histogram()
{
    delete ui;
}
