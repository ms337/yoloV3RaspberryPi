#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objectlist.h"
#include "zonelist.h"
#include <QPixmap>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
                                        
{
    ui->setupUi(this);
    QPixmap image("./akul.png");
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{    
    QPixmap image("./akul.png");

    ZoneList zonelist;
    zonelist.exec();
    
    QPainter painter(&image);
    painter.setPen(QPen(Qt::cyan, 5));

    QString *coordsArr[8];
    *coordsArr = zonelist.getCoords();
    
    int intCoords[8];
    
    for (int i = 0; i < 8; i++) {
        std::cout << coordsArr[i]->toStdString() << std::endl;
        bool ok;
        intCoords[i] = coordsArr[i]->toInt(&ok, 10);
        //std::cout << intCoords[i] << std::endl;
    }
    //painter.drawLine(intCoords[0], 50, 100, 150);

    //2 3 6 7 then 6 7 4 5 then 4 5 0 1
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
}

void MainWindow::on_pushButton2_clicked()
{
    ObjectList objlist;
    objlist.exec();
}

//QCamera camera = new QCamera;
