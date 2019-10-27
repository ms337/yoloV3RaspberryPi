#ifndef CLIENT
#define CLIENT

#include <opencv2/opencv.hpp>

class Client
{
private:
    ZonesPane zonesCollection;
    ObjectsPane objectsCollection;
    cv::VideoCapture feedCV;

public:
    Client(/* args */);
    ~Client();
    render();
    Session createSession();
    getData();
};
