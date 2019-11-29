/**
 * @file Zone.h
 * @author team9
 * @brief header file to zone.cpp
 * @version 0.1
 * @date 2019-11-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */

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
