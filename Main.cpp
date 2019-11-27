
/**
 * @file Main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "controller/Client.h"
#include "controller/FeedController.h"
#include <stdio.h>
#include "view/mainwindow.h"
#include <QApplication>
#include "model/ModelOutput.h"

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char *argv[])
{

    //Creates the gui
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //Creates the camera feed window
    FeedController client = FeedController();
    client.getFeed();
    // ModelOutput model = ModelOutput();

    std::cout << "hey" << std::endl;

    // client.render();

    return a.exec();
}
