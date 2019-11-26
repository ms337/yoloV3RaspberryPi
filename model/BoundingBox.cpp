#include "BoundingBox.h"
BoundingBox::BoundingBox(){
  topleft = Coordinate();
  topright = Coordinate();
  bottomright = Coordinate();
  bottomleft = Coordinate();
}
BoundingBox::BoundingBox(Coordinate tl, Coordinate tr, Coordinate br, Coordinate bl){
  topleft = tl;
  topright = tr;
  bottomright = br;
  bottomleft = bl;
}

BoundingBox::~BoundingBox()
{
}

Coordinate BoundingBox::getTopLeft(){
  return topleft;
}

Coordinate BoundingBox::getTopRight(){
  return topright;
}

Coordinate BoundingBox::getBottomRight(){
  return bottomright;
}

Coordinate BoundingBox::getBottomLeft(){
  return bottomleft;
}

void BoundingBox::setTL(Coordinate tl){
  topleft = tl;
}
void BoundingBox::setTR(Coordinate tr){
  topright = tr;
}
void BoundingBox::setBR(Coordinate br){
  bottomright = br;
}
void BoundingBox::setBL(Coordinate bl){
  bottomleft = bl;
}
