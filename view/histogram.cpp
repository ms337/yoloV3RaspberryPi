#include "histogram.h"
#include "ui_histogram.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Histogram::Histogram(QWidget *parent) : QDialog(parent),
                                        ui(new Ui::Histogram)
{
    ui->setupUi(this);

    vector<struct myObj> vObj = ;

    cout << "PRINTING VECTOR: " << endl;
    for (struct myObj x : vObj)
    {
        cout << x.name << endl;
    }
    struct myObj obj;
    obj.name = "apple";
    for (int x = 0; x < 30; x++)
    {
        obj.zones[x] = x + 4;
    }

    vObj.push_back(obj);

    string line;
    ifstream inFile;
    inFile.open("./stats.txt", ifstream::in);

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            cout << line << '\n'
                 << endl;
        }
        inFile.close();
    }
    else
        cout << "lol didnt open" << endl;

    /**
     * Input: hash table where key is object and value is an array of ints
     * Each array will be of length nZones (array index refers to which zone, content of array is occurences of object in zone)
     * Length of hash table is nObjects
    **/

    int nZones = 5;             //get this through a getter function in mainwindow
    int nObjects = vObj.size(); //this is the number of structs
    int maxOccurrences = 10;

    QVector<QString> objects(nObjects);

    int countObjIndex = 0;
    for (auto found : vObj) //iterate over vector of structs
    {
        objects[countObjIndex] = QString::fromStdString(found.name);
        countObjIndex++;
    }
    /**objects[0] = "Person";
    objects[1] = "Banana";
    objects[2] = "Poo";
    objects[3] = "Butt";
    objects[4] = "Fart";
    objects[5] = "Dick";**/
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
            datay[j] = obj.zones[j]; //rand() % 10;
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

Histogram::~Histogram()
{
    delete ui;
}
