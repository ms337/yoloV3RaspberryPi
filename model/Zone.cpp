#include "Zone.h"
//default contructor for zone
Zone::Zone()
{
  zoneArray;
  type = "";
}

//constructor for zone that take into input array of 8 integers as well as a name for the zone
Zone::Zone(int array[8], std::string name)
{
  //copy the array to zone array
  for (int i = 0; i < 8; i++)
  {
    zoneArray[i] = array[i];
  }
  //set zone type with name given in parameter
  type = name;
}
//deconstructor for the zone
Zone::~Zone()
{
}
//getter method for type of zone
std::string Zone::getType()
{
  return type;
}
//getter method to return zone array
int *Zone::getZoneArray()
{
  return this->zoneArray;
}
//setter method  to rename zone type 
void Zone::setType(std::string name)
{
  type = name;
}
