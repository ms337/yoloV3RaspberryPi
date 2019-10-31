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
    //Sets up gui
    ui->setupUi(this);

    //displays the first frame of the camera feed since the program began
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
 * Button Opens a window that allows zones to be entered
 * 
 */
void MainWindow::on_pushButton_clicked()
{    
    //Refreshes the camera
    QPixmap image("./camera.png");

    //Try/Catch block tries to get the number of the 
    //the user wishes to create
    int loops = 3;
    try {
        QString qloops = ui->textEdit->toPlainText();
        bool loopBool;
        loops = qloops.toInt(&loopBool, 10);

        //If the text box is empty, use the default number of zones (3)
        if (loops==0){
            loops=3;
        }
    }
    catch(...) {}

    //Runs n number of times depending on how many zones the user wanted to create
    for(int i=0;i<loops && i<30;i++){

        //Opens the window
        ZoneList zonelist;
        zonelist.exec();
    
        QPainter painter(&image);
        painter.setPen(QPen(Qt::cyan, 5));
        
        //Gets the coordinates from the text box
        QString *coordsArr;
        coordsArr = zonelist.getCoords();
        
        int intCoords[8];
        
        for (int i = 0; i < 8; i++) {
            bool ok;
            intCoords[i] = coordsArr[i].toInt(&ok, 10);
        }

        //Draws lines based on the 4 coordinates to make a zone
        painter.drawLine(intCoords[0], intCoords[1], intCoords[2], intCoords[3]);
        painter.drawLine(intCoords[2], intCoords[3], intCoords[6], intCoords[7]);
        painter.drawLine(intCoords[6], intCoords[7], intCoords[4], intCoords[5]);
        painter.drawLine(intCoords[4], intCoords[5], intCoords[0], intCoords[1]);
    }

    //Paint the lines on top of the image
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
