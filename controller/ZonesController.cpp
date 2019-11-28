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
    Coordinate topleft = Coordinate((float)array[0], (float)array[1]);
    Coordinate topRight = Coordinate((float)array[2], (float)array[3]);
    Coordinate botRight = Coordinate((float)array[4], (float)array[5]);
    Coordinate botLeft = Coordinate((float)array[6], (float)array[7]);

    BoundingBox bBox = BoundingBox(topleft, topRight, botRight, botLeft);

    Zone zone = Zone(bBox, to_string(zoneNo));
    zoneNo++;
    puts("Works");
}