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
#include "mainwindow.h"
#include <QApplication>

#include "ZonesCollection.h"
#include "Session.h"
#include "Client.h"

using namespace std;
using namespace cv;

/**
 * @brief Construct a new Client:: Client object
 * 
 */
Client::Client()
{
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


/**
 * @brief Destroy the Client:: Client object
 * 
 */
Client::~Client()
{
}


/**
 * @brief 
 * 
 * @param zonesCollection 
 * @param objectsCollection 
 * @return Session 
 */
Session Client::createSession(ZonesCollection zonesCollection, ObjectsCollection objectsCollection)
{
    
}


/**
 * @brief 
 * 
 */
void Client::render()
{
}
