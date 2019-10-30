#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "objectlist.h"
#include "zonelist.h"
#include <QPixmap>
#include <QPainter>
#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QCloseEvent>
#include <QMessageBox>

#include "opencv2/opencv.hpp"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
    ui->graphicsView->scene()->addItem(&pixmap);
    //QPixmap image("./akul.png");

    //QPainter painter(&image);
    painter.setPen(QPen(Qt::cyan, 5));
    painter.drawLine(50, 50, 200, 200);
    painter.drawLine(200, 200, 200, 400);
    painter.drawLine(200, 400, 50, 400);
    painter.drawLine(50, 400, 50, 50);
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
    bool isCamera;
    int cameraIndex = ui->videoEdit->text().toInt(&isCamera);
    if (isCamera)
    {   
        if (!video.open(cameraIndex))
        {
            QMessageBox::critical(this,
                "Camera Error",
                "Make sure you entered a correct camera index,"
                "<br>or that the camera is not being accessed by another program!");
            return;
        }
    }
    else
    {
        if (!video.open(ui->videoEdit->text().trimmed().toStdString()))
        {
            QMessageBox::critical(this,
                "Video Error",
                "Make sure you entered a correct and supported video file path,"
                "<br>or a correct RTSP feed URL!");
            return;
        }   
    }
    Mat frame;
    while (video.isOpened())
    {
        video >> frame;
        if (!frame.empty())
        {
            
            QImage qimg(frame.data, frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
            pixmap.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()) );
        }
        qApp->processEvents();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ObjectList objlist;
    objlist.exec();
}

void MainWindow::on_pushButton2_clicked()
{
    ZoneList zonelist;
    zonelist.exec();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
	if (video.isOpened())
	{
		QMessageBox::warning(this,
			"Warning",
			"Stop the video before closing the application!");
		event->ignore();
	}
	else
	{
		event->accept();
	}
}

//QCamera camera = new QCamera;
