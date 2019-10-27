#ifndef BOUNDINGBOX
#define BOUNDINGBOX
#include <iostream>
class BoundingBox{
private:
  Coordinate topLeft;
  Coordinate bottomLeft;
  Coordinate topRight;
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
}
#endif
