#ifndef OBJECTTYPE
#define OBJECTTYPE

#include <iostream>

class ObjectType
{
private:
  int i;
  std::string object[80];
  std::string selectedObjects[4];

public:
  std::string getObject(std::string item);
  void addObject(std::string item);
};

#endif
