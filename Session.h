#ifndef SESSION
#define SESSION
#include "ModelOutput.h"
#include "SessionData.h"
#include "TrackingEngine.h"

#include <iostream>
class Session
{
private:
  int timeInterval;

public:
  ModelOutput runModel(cv::VideoCapture video);
  void buildSessionData();
};
#endif
