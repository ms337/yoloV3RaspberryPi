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
    internalThread = new thread(&FeedController::updateFeedThread, this);
    currentZoneIndex = -1;
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
    DatabaseWriter dbWriter = DatabaseWriter(this->zones);
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

        vector<tuple<int, int, int>> listOfClassesFound = model.getClassesAndMidpoints();
        dbWriter.write(listOfClassesFound);
        cout << "----------" << endl;
        for (auto x : listOfClassesFound)
        {
            cout << "tuples:" << endl;
            cout << "Id: " << get<0>(x) << "X, Y: " << get<1>(x) << ", " << get<2>(x) << endl;
        }
        cout << "----------" << endl;
        //Mat image = imread("./test.jpg");
        //imshow("Say Onion!", image);

        // stop feedCVturing by pressing ESC
        //if (waitKey(10) == 27)
        //  break;
    }
}

void FeedController::createZones(int array[8])
{
    currentZoneIndex++;
    Zone zone = Zone(array, to_string(currentZoneIndex));
    if (currentZoneIndex >= 30)
    {
        cerr << "Max limit of 30 Zones reached. Cannot add any more zones." << endl;
    }
    this->zones[currentZoneIndex] = zone;
}