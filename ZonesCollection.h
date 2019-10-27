#ifndef ZONESCOLLECTION
#define ZONESCOLLECTION
#include "ZonesCollectionEntry.h"
#include <iostream>
class ZonesCollection{
private:
  ZonePaneEntry[] listOfZone;
  int maxZonesAllowed;
public:
  ZonePaneEntry[] getListOfZones();
  int createZonePaneEntry();
  int removeZonePaneEntry();
}
#endif
