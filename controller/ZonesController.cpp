#include "ZonesController.h"

#include <string>

using namespace std;

ZonesController::ZonesController()
{
    zoneNo = 1;
    zonesColl = ZonesCollection();
}

ZonesController::~ZonesController()
{
}

void ZonesController::createZones(int array[8])
{
    Zone zone = Zone(array, to_string(zoneNo));
    zoneNo++;
    zonesColl.addZone(zone);
}