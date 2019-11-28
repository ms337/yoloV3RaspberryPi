
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
    

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    sqlite3_close(db);


    //Creates the camera feed window

    // ModelOutput model = ModelOutput();

    std::cout << "hey" << std::endl;

    // client.render();

    return a.exec();
}
