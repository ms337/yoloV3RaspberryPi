<<<<<<< HEAD
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
=======
class ZonesCollection
{
private:
    /* data */
public:
    ZonesCollection(/* args */);
    ~ZonesCollection();
};

ZonesCollection::ZonesCollection(/* args */)
{
}

ZonesCollection::~ZonesCollection()
{
}
>>>>>>> d5003c5d29a2cfaec392146f288ac2a3c492964b
