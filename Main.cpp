
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
#include <stdio.h>
#include "view/mainwindow.h"
#include <QApplication>

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
    Client client = Client();
    client.render();

    return a.exec();
}
