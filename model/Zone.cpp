#include "Zone.h"
Zone::Zone()
{
  bBox = BoundingBox();
  type = "";
}
Zone::Zone(BoundingBox box, std::string name)
{
  bBox = box;
  type = name;
}

Zone::~Zone()
{
}

std::string Zone::getType()
{
  return type;
}

void Zone::setBbox(BoundingBox box)
{
  bBox = box;
}

BoundingBox Zone::getBbox(){
  return bBox;
}

void Zone::setType(std::string name)
{
  type = name;
}
