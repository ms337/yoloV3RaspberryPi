/**
 * @file Coordinate.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-31
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Coordinate.h"

/**
 * @brief Construct a new Coordinate:: Coordinate object
 * 
 * @param x 
 * @param y 
 */
Coordinate::Coordinate(float x, float y)
{
  xCoord = x;
  yCoord = y;
};

/**
 * @brief 
 * 
 * @return float 
 */
float Coordinate::getx()
{
  return xCoord;
}

/**
 * @brief 
 * 
 * @return float 
 */
float Coordinate::gety()
{
  return yCoord;
}

/**
 * @brief 
 * 
 * @param x 
 */
void Coordinate::setX(float x)
{
  xCoord = x;
}

/**
 * @brief 
 * 
 * @param y 
 */
void Coordinate::setY(float y)
{
  yCoord = y;
}
