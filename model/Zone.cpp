#include "Zone.h"
Zone::Zone(){
  coordsBox = BoundingBox();
  type = "";
}
Zone::Zone(BoundingBox box, std::string name){
  coordsBox = box;
  type = name;
}

Zone::~Zone()
{
}

std::string Zone::getType(){
  return type;
}

void Zone::setCoords(BoundingBox box){
  coordsBox = box;
}

void Zone::setType(std::string name){
  type = name;
}
