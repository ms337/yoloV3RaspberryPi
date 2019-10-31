/**
 * @file BoundingBox.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef BOUNDINGBOX
#define BOUNDINGBOX
#include "Coordinate.h"
#include <iostream>

/**
 * @brief 
 * 
 */
class BoundingBox
{
private:
  Coordinate topleft;
  Coordinate topright;
  Coordinate bottomleft;
  Coordinate bottomRIght;

public:
  Coordinate getTopLeft();
  Coordinate getTopRight();
  Coordinate getBottomLeft();
  Coordinate getBottomRight();
  void setTL(Coordinate tl);
  void setTR(Coordinate tr);
  void setBL(Coordinate bl);
  void setBR(Coordinate br);
};

#endif