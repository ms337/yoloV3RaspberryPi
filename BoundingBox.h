#ifndef BOUNDINGBOX
#define BOUNDINGBOX
#include <iostream>
#include "Coordinate.h"
class BoundingBox{
private:
  Coordinate topLeft;
  Coordinate topRight;
  Coordinate bottomLeft;
  Coordinate bottomRight;
public:
  Coordinate getTL();
  Coordinate getTR();
  Coordinate getBL();
  Coordinate getBR();
  void setTL(Coordinate tl);
  void setTR(Coordinate tr);
  void setBL(Coordinate bl);
  void setBR(Coordinate br);

};
#endif
