#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

class Client
{
private:
    zonesPa public : Client(/* args */);
    ~Client();
};

Client::Client(/* args */)
{
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

int main(int argc, char **argv)
{

    //  Client client = Client();
    // client.render();

    // client.createSession(zonesCollection, objectsCollection);
    VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if (!cap.open(0))
        return 0;
    for (;;)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty())
            break; // end of video stream
        imshow("this is you, smile! :)", frame);
        if (waitKey(10) == 27)
            break; // stop capturing by pressing ESC
    }
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;
}

int getFeed()
{
}