#include "Coordinate.h"

Coordinate::Coordinate (float x , float y){
  xCoord=x;
  yCoord=y;
};

float Coordinate::getx(){
  return xCoord;
}

float Coordinate::gety(){
  return yCoord;
}

void Coordinate::setX(float x){
  xCoord = x;
}
void Coordinate::setY(float y){
  yCoord = y;
}
