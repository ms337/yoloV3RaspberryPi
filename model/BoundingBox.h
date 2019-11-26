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
  Coordinate bottomright;
  Coordinate bottomleft;


public:
  BoundingBox();
  BoundingBox(Coordinate tl, Coordinate tr, Coordinate br, Coordinate bl);
  ~BoundingBox();
  Coordinate getTopLeft();
  Coordinate getTopRight();
  Coordinate getBottomRight();
  Coordinate getBottomLeft();
  void setTL(Coordinate tl);
  void setTR(Coordinate tr);
  void setBR(Coordinate br);
  void setBL(Coordinate bl);
};

#endif
