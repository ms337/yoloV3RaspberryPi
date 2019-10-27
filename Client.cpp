#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ZonesCollection.h"
#include "ObjectsCollection.h"
#include "Session.h"

using namespace std;
using namespace cv;

class Client
{
private:
    ZonesCollection zonesCollection;
    ObjectsCollection objectsCollection;
    cv::VideoCapture feedCV;

public:
    Client(/* args */);
    ~Client();
};

Client::Client(/* args */)
{
    zonesCollection = ZonesCollection();
    objectsCollection = ObjectsCollection();
    feedCV = new VideoCapture();

    if (!feedCV.open(0))
        exit(-1);

    for (;;)
    {
        Mat frame;
        feedCV >> frame;
        if (frame.empty())
            break; // end of video stream
        imshow("this is you, smile! :)", frame);
        if (waitKey(10) == 27)
            break; // stop feedCVturing by pressing ESC
    }
}

Client::~Client()
{
}

Client::createSession(ZonesPane zonesCollection, ObjectsPane objectsCollection)
{
    if (zonesCollection.getCount() <= 0) || objectsCollection.getCount() <=0)
        {
            sess = Session(zonesCollection, objectsCollection);
        }
}

void Client::render()
{
}

VideoCapture *Client::getFeed()
{
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
}
