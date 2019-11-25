/**
 * @file ZonesCollectionEntry.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef ZONESCOLLECTIONENTRY
#define ZONESCOLLECTIONENTRY
#include "Zone.h"
#include <iostream>

/**
 * @brief 
 * 
 */
class ZonesCollectionEntry
{
private:
  Zone zone;
  // cv::viz::Color regionColour;

public:
  std::string getID();
  // cv::viz::Color getColour();
};
#endif
