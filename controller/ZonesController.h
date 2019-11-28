#ifndef ZONE_CONTROLLER
#define ZONE_CONTROLLER
#include "../model/Zone.h"
#include "../model/BoundingBox.h"
#include "../model/ZonesCollection.h"

class ZonesController
{
private:
    int zoneNo;
    ZonesCollection zonesColl;

public:
    ZonesController(/* args */);
    ~ZonesController();
    void createZones(int array[8]);
};
#endif