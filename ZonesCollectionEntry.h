#ifndef ZONESCOLLECTIONENTRY
#define ZONESCOLLECTIONENTRY
#include "Zone.h"
#include <iostream>
class ZonesCollectionEntry{
private:
  Zone zone;
  cv::viz::Color regionColour;
public:
  std::String getID()
  cv::viz::Color getColour();
}
#endif
