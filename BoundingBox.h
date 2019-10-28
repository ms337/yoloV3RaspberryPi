#ifndef BOUNDINGBOX
#define BOUNDINGBOX
#include "Coordinate.h"
#include <iostream>
class BoundingBox{
private:
  Coordinate::Coordinate topleft;
  Coordinate::Coordinate topright;
  Coordinate::Coordinate bottomleft;
  Coordinate::Coordinate bottomRIght;
Public:
  Coordinate::Coordinate getTopLeft();
  Coordinate::Coordinate getTopRight();
  Coordinate::Coordinate getBottomLeft();
  Coordinate::Coordinate getBottomRight();
  void setTL(Coordinate::Coordinate tl);
  void setTR(Coordinate::Coordinate tr);
  void setBL(Coordinate::Coordinate bl);
  void setBR(Coordinate::Coordinate br);
}
