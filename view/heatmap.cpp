/**
 * @file heatmap.cpp
 * @author Allen Bao
 * @brief 
 * @version 0.1
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "heatmap.h"
#include "ui_heatmap.h"

using namespace std;

/**
 * @brief Construct a new Heatmap:: Heatmap object
 * 
 * @param parent 
 */
Heatmap::Heatmap(QWidget *parent) : QDialog(parent),
                                    ui(new Ui::Heatmap)
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
    int nObjects = vObj.size();        //this is the number of structs
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
            datay[j] = vObj[i].zones[j]; //rand() % 10;
        }
        dataArr[i] = datay;
    }

    QCPColorMap *colorMap = new QCPColorMap(ui->widget->xAxis, ui->widget->yAxis);
    colorMap->setInterpolate(false);

    colorMap->data()->setSize(nObjects, nZones);
    colorMap->data()->setRange(QCPRange(0, nObjects), QCPRange(0, nZones));
    colorMap->setDataRange(QCPRange(0, maxOccurrences));
    for (int x = 0; x < nObjects; x++)
    {
        for (int y = 0; y < nZones; y++)
        {
            colorMap->data()->setCell(x + 0.5, y + 0.5, dataArr[x][y]); //rand()%255
        }
    }
    colorMap->setGradient(QCPColorGradient::gpHot);
    ui->widget->xAxis->setLabel("Objects");
    ui->widget->yAxis->setLabel("Zones");

    QSharedPointer<QCPAxisTickerText> objTicker(new QCPAxisTickerText);
    for (int i = 0; i < nObjects; i++)
    {
        objTicker->addTick(i + 0.5, objects[i]);
    }
    ui->widget->xAxis->setTicker(objTicker);

    ui->widget->rescaleAxes();

    QCPColorScale *colorScale = new QCPColorScale(ui->widget);
    ui->widget->plotLayout()->addElement(0, 1, colorScale);
    colorScale->setGradient(QCPColorGradient::gpHot);
    colorScale->setDataRange(QCPRange(0, maxOccurrences));

    ui->widget->replot();
}

/**
 * @brief Destroy the Heatmap:: Heatmap object
 * 
 */
Heatmap::~Heatmap()
{
    delete ui;
}
