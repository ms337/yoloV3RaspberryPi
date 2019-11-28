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
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../controller/FeedController.h"

using namespace std;
using namespace cv;

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
    try
    {
        QString qloops = ui->textEdit->toPlainText();
        bool loopBool;
        loops = qloops.toInt(&loopBool, 10);

        //If the text box is empty, use the default number of zones (3)
        if (loops == 0)
        {
            loops = 3;
        }
    }
    catch (...)
    {
    }

    //Runs n number of times depending on how many zones the user wanted to create
    for (int i = 0; i < loops && i < 30; i++)
    {

        //Opens the window
        ZoneList zonelist;
        zonelist.exec();

        QPainter painter(&image);
        painter.setPen(QPen(Qt::cyan, 5));

        //Gets the coordinates from the text box
        QString *coordsArr;
        coordsArr = zonelist.getCoords();

        int intCoords[8];

        for (int i = 0; i < 8; i++)
        {
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
void MainWindow::on_startStopButton_clicked()
{

    //using namespace cv;
    QPixmap image("./camera.png");
    bool isCamera;
    //int cameraIndex = 0;//ui->videoEdit->text().toInt(&isCamera);
    //VideoCapture video;
    /*if (isCamera)
    {   
        if (!video.open(cameraIndex))
        {
            QMessageBox::critical(this,
                "Camera Error",
                "Make sure you entered a correct camera index,"
                "<br>or that the camera is not being accessed by another program!");
            return;
        }
    }*/
    //else
    //{
    /*if (!video.open(ui->videoEdit->text().trimmed().toStdString()))
        {
            QMessageBox::critical(this,
                "Video Error",
                "Make sure you entered a correct and supported video file path,"
                "<br>or a correct RTSP feed URL!");
            return;
        } */
    //}
    /*Mat frame;
    while (video.isOpened())
    {
        video >> frame;
        if (!frame.empty())
        {
            
            QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            //image.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
            image = QPixmap::fromImage(qimg);
            ui->label->setPixmap(image);
        }
        qApp->processEvents();
    }*/

    FeedController client = FeedController();

    while (true)
    {

        Mat frame = client.getFeed();
        //imshow("Say Onion!", image);
        QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

        /*for (int x = 0; x < 10; ++x) {
            for (int y = 0; y < 10; ++y) {
                qimg.setPixel(x, y, qRgb(0, 0, 0));
            }
        }*/
        //QRgb value = qRgb(0, 0, 0);
        //qimg.setPixel(i, j, value);
        //cvtColor(qimg, qimg, cv::CV_BGR2RGB);

        image = QPixmap::fromImage(qimg.rgbSwapped());
        //image.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
        ui->label->setPixmap(image);
        qApp->processEvents();
        std::chrono::milliseconds timespan(33);
        std::this_thread::sleep_for(timespan);
    }
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
