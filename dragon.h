/***********************************************************************
 * Heaader File:
 *    Dragon : Dragon satellite
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the Space X Crew Dragon satellite entity
 ************************************************************************/
#pragma once
#include "entity.h"
#include "satellite.h"
#include "uiDraw.h"

class TestDragon;

class Dragon : public Satellite
{
public:
   friend TestDragon;

   Dragon() : Satellite() {}
   Dragon(const Position & pos,const Velocity & vel,const float & a,const bool & dead, const double& radius = 0) :
      Satellite(pos, vel, a, dead, radius) {}
   void onHit() {};
   void draw(ogstream* pgout)
   {
      pgout->drawCrewDragon(position, angle.getRadians());
   }
};

