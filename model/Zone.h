/**
 * @file Zone.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2019-10-31
 *
 * @copyright Copyright (c) 2019
 *
 */
#ifndef ZONE
#define ZONE

#include <iostream>

/**
 * @brief
 *
 */
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
