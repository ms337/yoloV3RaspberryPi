/**
 * @file Session.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef SESSION
#define SESSION
#include "ModelOutput.h"
#include "SessionData.h"
#include "TrackingEngine.h"

#include <iostream>

/**
 * @brief 
 * 
 */
class Session
{
private:
  int timeInterval;

public:
  ModelOutput runModel(cv::VideoCapture video);
  void buildSessionData();
};
#endif
