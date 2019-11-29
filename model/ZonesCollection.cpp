/*!
   \file ZonesCollection.cpp
   \brief used to manage the collection of Zones via ZonesController
   \author team9  
*/
#include "ZonesCollection.h"

using namespace std;
//constructor
ZonesCollection::ZonesCollection()
{
  //set current zone index, zones array, and max zones maxZonesAllowed
    currentZoneIndex = -1;
    Zone zones[30];
    maxZonesAllowed = 30;
}
//deconstructor
ZonesCollection::~ZonesCollection()
{
}
//getter method to return list of zones
Zone *ZonesCollection::getListOfZones()
{
    return zones;
}
//getter method to get current zone
int ZonesCollection::getCurrentZoneIndex()
{
    return currentZoneIndex;
}

//method to add zone to zones array and also check to make sure zones are not more than 30
int ZonesCollection::addZone(Zone zoneToAdd)
{
    currentZoneIndex++;
    if (currentZoneIndex >= maxZonesAllowed)
    {
        cout << "Cannot add more than 30 zones. " << endl;
        return -1;
    }
    zones[currentZoneIndex] = zoneToAdd;
}
