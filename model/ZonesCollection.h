/*!
   \file ZonesCollection.h
   \brief header file for zones collection.cpp
   \author tema9
*/
//header file for ZonesCollection.cpp
#ifndef ZONESCOLLECTION
#define ZONESCOLLECTION

#include <iostream>
#include "Zone.h"

/**
 * @brief
 *
 */
class ZonesCollection
{
private:
  Zone zones[30];
  int currentZoneIndex;
  int maxZonesAllowed;

public:
  ZonesCollection();
  ~ZonesCollection();
  Zone *getListOfZones();
  int getCurrentZoneIndex();
  int addZone(Zone zoneToAdd);
  int removeZone(Zone zoneToAdd);
};
#endif
