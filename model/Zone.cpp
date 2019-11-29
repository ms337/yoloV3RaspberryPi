/*!
   \file Zone.cpp
   \brief base class for Zones
   \author team9
*/
#include "Zone.h"
/*!
   \brief consturctor default
*/
Zone::Zone()
{
  zoneArray;
  type = "";
}

/*!
   \brief constructor that creates a full zone with the four endpoints and a name for the zone
*/
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
/*!
   \brief deconstructor
*/
Zone::~Zone()
{
}
/*!
   \brief gets the type for the zone
   \return string for the "type" of zone
*/
std::string Zone::getType()
{
  return type;
}
/*!
   \brief gets a list of all zones
   \return pointer to the array of int zones
*/
int *Zone::getZoneArray()
{
  return this->zoneArray;
}
/*!
   \brief sets the type for a zone
   \param string name for the zone
*/
void Zone::setType(std::string name)
{
  type = name;
}
