#ifndef ZONE
#define ZONE
#include "BoundingBox.h"
#include <iostream>
class Zone
{
private:
  BoundingBox coords;
  std::string type;

public:
  std::string getType();
  void setCoords(BoundingBox box);
  void setType(std::string type);
};
#endif
