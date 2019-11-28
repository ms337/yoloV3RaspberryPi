#include "Zone.h"

Zone::Zone()
{
  zoneArray;
  type = "";
}

Zone::Zone(int array[8], std::string name)
{
  for (int i = 0; i < 8; i++)
  {
    zoneArray[i] = array[i];
  }

  type = name;
}

Zone::~Zone()
{
}

std::string Zone::getType()
{
  return type;
}

int *Zone::getZoneArray()
{
  return this->zoneArray;
}

void Zone::setType(std::string name)
{
  type = name;
}
