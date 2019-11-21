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
 * Set up the camera feed
 * 
 */
Client::Client()
{
    /*VideoCapture feedCV;

    if (!feedCV.open(0))
        exit(-1);
        
    for (;;)
    {
        Mat frame;
        feedCV >> frame;
        if (frame.empty())
            break; // end of video stream

        //Shows each frame
        imshow("Say Cheese!", frame);

        //Saves the frame to a file that the gui can access
        imwrite("./camera.png",frame);

        // stop feedCVturing by pressing ESC
        if (waitKey(10) == 27)
            break; 
    }*/
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
