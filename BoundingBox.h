#ifndef BOUNDINGBOX
#define BOUNDINGBOX
#include <iostream>
#include "Coordinate.h"
class BoundingBox
{
private:
private:
  ivate : Coordinate topLeft;

public:
  inate bottomLef
      inate topRight;

public:
  inate bottomRight;

public:
  Coordinate getTL();
  Coordinate getTR();
  Coordinate getBL();
  Coordinate getBR();
  void setTL(Coordinate tl);
  void setTR(Coordinate tr);
};
#endif
