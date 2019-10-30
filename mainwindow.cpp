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

    QPixmap image("/home/pi/Documents/test/akul.png");

    QPainter painter(&image);
    painter.setPen(QPen(Qt::cyan, 5));
    painter.drawLine(50, 50, 200, 200);
    painter.drawLine(200, 200, 200, 400);
    painter.drawLine(200, 400, 50, 400);
    painter.drawLine(50, 400, 50, 50);
    ui->label->setPixmap(image);
    ui->label->setScaledContents(true);
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

void on_pushButton_2_clicked()
{
    ;
}

//QCamera camera = new QCamera;
