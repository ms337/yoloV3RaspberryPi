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
#include "ZonesCollectionEntry.h"
#include <iostream>

/**
 * @brief 
 * 
 */
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
