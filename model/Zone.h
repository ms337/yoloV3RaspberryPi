#ifndef ZONE
#define ZONE
#include <iostream>
//header file for zone.cpp

class Zone
{
private:
  int zoneArray[8];
  std::string type;

public:
  Zone();
  Zone(int zoneArray[8], std::string name);
  ~Zone();
  std::string getType();
  int *getZoneArray();
  void setType(std::string name);
};
#endif
