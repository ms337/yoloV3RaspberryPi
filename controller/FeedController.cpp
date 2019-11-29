/**
 * @file Client.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <thread>
#include "FeedController.h"
#include "../model/ModelOutput.h"

using namespace std;
using namespace cv;

FeedController::FeedController()
{
    VideoCapture feedCV;
    Mat frame;
    Mat outFrame;
    Zone zones[30];
    zonesDefinedCount;

    for (int i = 0; i < 10; i++)
    {
        this->classesOfObjsSelected[i] = -1;
    }

    //
    internalThread = new thread(&FeedController::updateFeedThread, this);
    currentZoneIndex = -1;
    string objects[80] = {"person", "bicycle", "car", "motorcycle", "airplane", "bus", "train", "truck", "boat", "traffic light", "fire hydrant", "stop_sign", "parking meter", "bench", "bird", "cat", "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella", "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat", "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup", "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli", "carrot", "hot dog", "pizza", "doughnut", "cake", "chair", "couch", "potted plant", "bed", "dining table", "toilet", "tv", "laptop", "mouse", "remote", "keyboard", "cell phone", "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors", "teddy bear", "hair dryer", "toothbrush"};
}

FeedController::~FeedController()
{
    // internalThread->interrupt();
    std::cout << "hey" << std::endl;
    internalThread->join();
}

cv::Mat FeedController::getFeed()
{
    return this->outFrame;
}

void FeedController::updateFeedThread()
{

    if (!feedCV.open(0))
        exit(-1);

    ModelOutput model = ModelOutput();
    this->dbWriter = DatabaseWriter::getInstance();

    int frameCount = 0;
    for (;;)
    {
        feedCV >> this->frame;
        //if (frame.empty()) {
        //  break; // end of video stream
        //}
        //Shows each frame
        //virtual double fps = feedCV.get(cv.CAP_PROP_FPS);
        //std::cout << fps<< std::endl;
        //imshow("Say Cheese!", frame);

        // imwrite("test.jpg", this->frame);
        model.run(this->frame, &(this->outFrame));

        if (frameCount == 30)
        {
            vector<tuple<int, int, int>> listOfClassesFound = model.getClassesAndMidpoints();
            dbWriter->write(listOfClassesFound, this->zones, this->classesOfObjsSelected);
            // cout << "----------" << endl;
            // for (auto x : listOfClassesFound)
            // {
            //     cout << "tuples:" << endl;
            //     cout << "Id: " << get<0>(x) << "X, Y: " << get<1>(x) << ", " << get<2>(x) << endl;
            // }
            // cout << "----------" << endl;
            frameCount = 0;
        }

        frameCount++;
    }
}

void FeedController::createZones(int array[8])
{
    this->currentZoneIndex++;
    Zone zone = Zone(array, to_string(this->currentZoneIndex + 1));
    if (this->currentZoneIndex >= 30)
    {
        cerr << "Max limit of 30 Zones reached. Cannot add any more zones." << endl;
    }
    this->zones[this->currentZoneIndex] = zone;
}

void FeedController::getObjectsSelected(int objectsSelected[10])
{

    for (int i = 0; i < 10; i++)
    {
        cout << "ObjectLabelNo: " << objectsSelected[i] << endl;
        this->classesOfObjsSelected[i] = objectsSelected[i];
    }
}

string *FeedController::getObjectsAvailable()
{
    return this->objects;
}

void FeedController::setZonesCount(int zoneCount)
{
    this->zonesDefinedCount = zoneCount;
    cout << "FEEDC NZOMES: " << endl;
    cout << this->zonesDefinedCount << endl;
    this->dbWriter->setNZones(zoneCount);
}