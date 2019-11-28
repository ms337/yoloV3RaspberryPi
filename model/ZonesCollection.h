/**
 * @file ZonesCollection.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
