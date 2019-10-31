/**
 * @file mainwindow.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objectlist.h"
#include "zonelist.h"
#include <QPixmap>
#include <QPainter>

/**
 * @brief Construct a new Main Window:: Main Window object
 * 
 * @param parent 
 */
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
                               
                
{
    ui->setupUi(this);
    QPixmap image("./camera.png");
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
}

/**
 * @brief Destroy the Main Window:: Main Window object
 * 
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief 
 * 
 */
void MainWindow::on_pushButton_clicked()
{    
    QPixmap image("./camera.png");

    int loops = 3;
    try {
        QString qloops = ui->textEdit->toPlainText();
        bool loopBool;
        loops = qloops.toInt(&loopBool, 10);
        if (loops==0){
            loops=3;
        }
    }
    catch(...) {}
    std::cout << loops;
    for(int i=0;i<loops && i<30;i++){
        ZoneList zonelist;
        zonelist.exec();
    
        QPainter painter(&image);
        painter.setPen(QPen(Qt::cyan, 5));
        QString *coordsArr;
        coordsArr = zonelist.getCoords();
        
        int intCoords[8];
        
        for (int i = 0; i < 8; i++) {
            bool ok;
            intCoords[i] = coordsArr[i].toInt(&ok, 10);
        }
        painter.drawLine(intCoords[0], intCoords[1], intCoords[2], intCoords[3]);
        painter.drawLine(intCoords[2], intCoords[3], intCoords[6], intCoords[7]);
        painter.drawLine(intCoords[6], intCoords[7], intCoords[4], intCoords[5]);
        painter.drawLine(intCoords[4], intCoords[5], intCoords[0], intCoords[1]);
    }
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
}

/**
 * @brief 
 * 
 */
void MainWindow::on_pushButton2_clicked()
{
    ObjectList objlist;
    objlist.exec();
}
