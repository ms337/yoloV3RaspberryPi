/**
 * @file Client.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef CLIENT
#define CLIENT

#include <opencv2/opencv.hpp>
#include "ZonesCollection.h"
#include "ObjectsCollection.h"
#include "Session.h"

/**
 * @brief 
 * 
 */
class Client
{
private:
    // ZonesCollection zonesCollection;
    // ObjectsCollection objectsCollection;
    cv::VideoCapture feedCV;

public:
    Client(/* args */);
    ~Client();
    void render();
    Session createSession(ZonesCollection zonesCollection, ObjectsCollection objectsCollection);
    int getData();
};
#endif