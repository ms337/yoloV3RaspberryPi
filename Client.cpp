#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "mainwindow.h"
#include <QApplication>

#include "ZonesCollection.h"
#include "Session.h"
#include "Client.h"

using namespace std;
using namespace cv;

Client::Client()
{
    // zonesCollection = ZonesCollection();
    // objectsCollection = ObjectsCollection();
    VideoCapture feedCV;

    if (!feedCV.open(0))
        exit(-1);
        
    for (;;)
    {
        Mat frame;
        feedCV >> frame;
        if (frame.empty())
            break; // end of video stream
        imshow("this is you, smile! :)", frame);
        imwrite("./camera.png",frame);
        if (waitKey(10) == 27)
            break; // stop feedCVturing by pressing ESC
    }
}

Client::~Client()
{
}

Session Client::createSession(ZonesCollection zonesCollection, ObjectsCollection objectsCollection)
{
    // if (zonesCollection.getCount() <= 0) || objectsCollection.getCount() <=0)
    //     {
    //         sess = Session(zonesCollection, objectsCollection);
    //     }
}

void Client::render()
{
}
