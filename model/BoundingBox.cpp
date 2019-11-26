#include "BoundingBox.h"
BoundingBox::BoundingBox(Coordinate tl, Coordinate tr, Coordinate br, Coordinate bl){
  topleft = tl;
  topright = tr;
  bottomright = br;
  bottomleft = bl;
}

Coordinate getTopLeft(){
  return topleft;
}

Coordinate getTopRight(){
  return topright
}

Coordinate getBottomRight(){
  return bottomright;
}

Coordinate getBottomLeft(){
  return bottomleft;
}

oid setTL(Coordinate tl){
  topleft = tl;
}
void setTR(Coordinate tr){
  topright = tr
}
void setBR(Coordinate br){
  bottomright = br
}
void setBL(Coordinate bl){
  bottomleft = bl
}

BoundingBox::~BoundingBox()
{
}
