#ifndef FEED_CONTROLLER
#define FEED_CONTROLLER
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include <tuple>
#include "../model/Zone.h"
#include "../model/DatabaseWriter.h"
class FeedController
{
private:
    cv::VideoCapture feedCV;
    std::thread *internalThread;
    cv::Mat frame;
    cv::Mat outFrame;
    Zone zones[30];
    int classesOfObjsSelected[10];
    int currentZoneIndex;
    std::string objects[80];
    int zonesDefinedCount;

public:
    FeedController(/* args */);
    ~FeedController();
    cv::Mat getFeed();
    void updateFeedThread();
    void createZones(int array[8]);
    void getObjectsSelected(int objectsSelected[10]);
    std::string *getObjectsAvailable();

    void setZonesCount(int zoneCount);
};
#endif
