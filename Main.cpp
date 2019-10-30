#include "Client.h"
#include <stdio.h>
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    Client client = Client();
    client.render();

    return a.exec();
}
