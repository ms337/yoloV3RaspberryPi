#ifndef CLIENT
#define CLIENT

#include <opencv2/opencv.hpp>
#include "ZonesCollection.h"
#include "ObjectsCollection.h"
#include "Session.h"

class Client
{
private:
    ZonesCollection zonesCollection;
    ObjectsCollection objectsCollection;
    cv::VideoCapture feedCV;

public:
    Client(/* args */);
    ~Client();
    void render();
    Session createSession();
    cv::VideoCapture getFeed();
    int getData();
};
#endif