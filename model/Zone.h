/**
 * @file Zone.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2019-10-31
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef ZONE
#define ZONE
#include "BoundingBox.h"
#include <iostream>

/**
 * @brief
 *
 */
class Zone
{
private:
  BoundingBox coordsBox;
  std::string type;

public:
  Zone(BoundingBox box, std::string name);
  ~Zone();
  std::string getType();
  void setCoords(BoundingBox box);
  void setType(std::string name);
};
#endif
