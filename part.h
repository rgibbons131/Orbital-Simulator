/***********************************************************************
 * Header File:
 *    Fragment : The part class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents fragments within the simulation.
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Part : public Satellite
{
public:
   Part(void (*drawFunction)(const Position& center,const double& rotation), const double& radius) : Satellite() { drawFunc = drawFunction;};
   void (*drawFunc)(const Position& center,const double& rotation);
   void draw(ogstream* pgout)
   {
      drawFunc(position, angle.getRadians());
   };
};

