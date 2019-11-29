
/**
 * @file Main.cpp
 * @author team9
 * @brief main function for the application
 * @version 0.1
 * @date 2019-10-31
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "controller/FeedController.h"
#include <stdio.h>
#include "view/mainwindow.h"
#include <QApplication>
#include "model/ModelOutput.h"
#include <sqlite3.h>

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

    // ModelOutput model = ModelOutput();

    std::cout << "hey" << std::endl;

    // client.render();

    return a.exec();
}
