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
#include "histogram.h"
#include "heatmap.h"
#include "../controller/ZonesController.h"
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../controller/FeedController.h"

using namespace std;
using namespace cv;

int fourCoords[30][4];
int allCoords[30][4];
int nZones = 1; //default number of zones

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
    //Try/Catch block tries to get the number of the
    //the user wishes to create
    try
    {
        QString qloops = ui->textEdit->toPlainText();
        bool loopBool;
        nZones = qloops.toInt(&loopBool, 10);

        //If the text box is empty, use the default number of zones (1)
        if (nZones == 0)
        {
            nZones = 1;
        }
    }
    catch (...)
    {
    }

    ZonesController zoneController = ZonesController();

    //Runs n number of times depending on how many zones the user wanted to create
    for (int i = 0; i < nZones && i < 30; i++)
    {

        //Opens the window
        ZoneList zonelist;
        zonelist.exec();

        //Gets the coordinates from the text box
        QString *coordsArr;
        coordsArr = zonelist.getCoords();

        for (int j = 0; j < 4; j++)
        {
            bool ok;
            fourCoords[i][j] = coordsArr[j].toInt(&ok, 10);
        }

        for (int k = 0; k < nZones; k++) {
            allCoords[k][0] = fourCoords[k][0];
            allCoords[k][1] = fourCoords[k][1];
            allCoords[k][2] = fourCoords[k][2];
            allCoords[k][3] = fourCoords[k][1];
            allCoords[k][4] = fourCoords[k][2];
            allCoords[k][5] = fourCoords[k][3];
            allCoords[k][6] = fourCoords[k][0];
            allCoords[k][7] = fourCoords[k][3];
        }
        zoneController.createZones(allCoords[i]);
    }
}

/**
 * @brief
 *
 */
void MainWindow::on_startButton_clicked()
{
    FeedController client = FeedController();

    while (true)
    {
        Mat frame = client.getFeed();
        //imshow("Say Onion!", image);
        QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

        QPixmap image = QPixmap::fromImage(qimg.rgbSwapped());
        //image.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
        for (int i = 0; i < nZones; i++)
        {
            image = drawZones(image, fourCoords[i]);
        }
        ui->label->setPixmap(image);
        qApp->processEvents();
        std::chrono::milliseconds timespan(33);
        std::this_thread::sleep_for(timespan);
    }
}

QPixmap MainWindow::drawZones(QPixmap image, int intCoords[8])
{
    QPainter painter(&image);
    painter.setPen(QPen(Qt::red, 5));

    //Draws lines based on the coordinates to make a zone

    painter.drawLine(intCoords[0], intCoords[1], intCoords[2], intCoords[1]);
    painter.drawLine(intCoords[2], intCoords[1], intCoords[2], intCoords[3]);
    painter.drawLine(intCoords[2], intCoords[3], intCoords[0], intCoords[3]);
    painter.drawLine(intCoords[0], intCoords[3], intCoords[0], intCoords[1]);

    //Paint the lines on top of the image
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
    return image;
}

void MainWindow::on_histButton_clicked()
{
    Histogram histogram;
    histogram.exec();
}

void MainWindow::on_heatmapButton_clicked()
{
    Heatmap heatmap;
    heatmap.exec();
}

void MainWindow::on_pushButton2_clicked()
{
    ObjectList objlist;
    objlist.exec();
}
