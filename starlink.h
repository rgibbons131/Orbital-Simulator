/***********************************************************************
 * Heaader File:
 *    Starlink : Starlink satellite
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the starlink satellite entity
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Starlink : public Satellite
{
public:
   Starlink() : Satellite() {}
   Starlink(const Position& pos,const Velocity& vel,const float& a,const bool& dead) :
      Satellite(pos, vel, a, dead) {}
   void draw(ogstream* pgout)
   {
      pgout->drawStarlink(position, angle.getRadians());
   }
};

