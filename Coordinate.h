/**
 * @file Coordinate.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef COORDINATE
#define COORDINATE
#include <iostream>
#include <math.h>

/**
 * @brief 
 * 
 */
class Coordinate
{
private:
  float xCoord;
  float yCoord;

public:
  Coordinate(float x, float y);
  float getx();
  float gety();
  void setX(float x);
  void setY(float y);
};
#endif
