#ifndef ZONESCOLLECTION
#define ZONESCOLLECTION
#include "ZonesCollectionEntry.h"
#include <iostream>
class ZonesCollection
{
private:
  ZonesCollectionEntry *listOfZone;
  int maxZonesAllowed;

public:
  ZonesCollectionEntry *getListOfZones();
  int createZonePaneEntry();
  int removeZonePaneEntry();
};
#endif
