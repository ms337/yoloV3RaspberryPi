#ifndef BOUNDINGBOX
#define BOUNDINGBOX
#include "Coordinate.h"
#include <iostream>
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