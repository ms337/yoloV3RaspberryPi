/*!
   \file ZonesController.cpp
   \brief manages the set of all zones
   \author team9
*/
#include "ZonesController.h"

#include <string>

using namespace std;
/*!
   \brief contsructor for zones controller
*/
ZonesController::ZonesController()
{
    zoneNo = 1;
    zonesColl = ZonesCollection();
}
/*!
   \brief decostuctor for ZonesController
*/
ZonesController::~ZonesController()
{
}
/*!
   \brief initiailizes a zone with all 8 coordinates
   \param an array holding 8 numbers which corresponds to 4 coordinates
   \return nothing
*/
void ZonesController::createZones(int array[8])
{
    Zone zone = Zone(array, to_string(zoneNo));
    zoneNo++;
    zonesColl.addZone(zone);
}
