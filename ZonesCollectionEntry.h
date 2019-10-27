#ifndef ZONESCOLLECTIONENTRY
#define ZONESCOLLECTIONENTRY
#include "Zone.h"
#include <iostream>

class ZonesCollectionEntry
{
private:
  Zone zone;
  viz::Color regionColour;

public:
  std::String getID();
  viz::Color getColour();
};
#endif
