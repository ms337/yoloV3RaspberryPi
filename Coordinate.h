#ifndef COORDINATE
#define COORDINATE
#include <iostream>
#include <math.h>

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
