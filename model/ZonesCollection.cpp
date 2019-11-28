#include "ZonesCollection.h"

using namespace std;

ZonesCollection::ZonesCollection()
{
    currentZoneIndex = -1;
    Zone zones[30];
    maxZonesAllowed = 30;
}

ZonesCollection::~ZonesCollection()
{
}

Zone *ZonesCollection::getListOfZones()
{
    return zones;
}

int ZonesCollection::getCurrentZoneIndex()
{
    return currentZoneIndex;
}
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
