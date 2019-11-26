#include "Zone.h"

Zone::Zone(BoundingBox box, std::string name){
  coordsBox = box;
  type = name;
}


std::string getType(){
  return type;
}

void setCoords(BoundingBox box){
  coordsBox = box;
}

void setType(std::string name){
  type = name;
}

Zone::~Zone()
{
}
