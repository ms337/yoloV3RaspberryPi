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


using namespace std;
using namespace cv;

FeedController::FeedController()
{
    VideoCapture feedCV;
    Mat frame;
    
    internalThread = new thread(&FeedController::updateFeedThread, this);
    
}

FeedController::~FeedController()
{
    // internalThread->interrupt();
    std::cout << "hey"<< std::endl;
    internalThread->join();
}

cv::Mat FeedController::getFeed()
{
    return this->frame;
}

void FeedController::updateFeedThread()
{
    
    if (!feedCV.open(0))
        exit(-1);

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
        
        
        
        imwrite("test.jpg", this->frame);
        //Mat image = imread("./test.jpg");
        //imshow("Say Onion!", image);
        
        
        // stop feedCVturing by pressing ESC
        //if (waitKey(10) == 27)
          //  break;
    }
}
