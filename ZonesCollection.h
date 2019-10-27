#ifndef ZONESCOLLECTION
#define ZONESCOLLECTION
#include "ZonesCollectionEntry.h"
#include <iostream>
class ZonesCollection
{
private:
  ZoneCollectionEntry[] listOfZone;
  int maxZonesAllowed;

public:
  ZoneCollectionEntry[] getListOfZones();
  int createZonePaneEntry();
  int removeZonePaneEntry();
};
#endif
