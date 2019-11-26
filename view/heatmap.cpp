#include "heatmap.h"
#include "ui_heatmap.h"

Heatmap::Heatmap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Heatmap)
{
    ui->setupUi(this);

    int nZones = 4;
    int nObjects = 5;

    QCPColorMap *colorMap = new QCPColorMap(ui->widget->xAxis, ui->widget->yAxis);

    colorMap->data()->setSize(nObjects, nZones);
    colorMap->data()->setRange(QCPRange(0, 2), QCPRange(0, 2));
    for (int x=0; x<nObjects; ++x)
      for (int y=0; y<nZones; ++y)
        colorMap->data()->setCell(x, y, y); //rand()%255
    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange(true);
    ui->widget->xAxis->setLabel("Objects");
    ui->widget->yAxis->setLabel("Zones");
    ui->widget->rescaleAxes();
    ui->widget->replot();
}

Heatmap::~Heatmap()
{
    delete ui;
}
