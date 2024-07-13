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
#include "part.h"


class TestDragon;

class Dragon : public Satellite
{
public:
   friend TestDragon;

   Dragon() : Satellite() { this->radius = 7; }
   Dragon(const Position & pos,const Velocity & vel,const float & a,const bool & dead, const double& radius = 7) :
      Satellite(pos, vel, a, dead, radius) {}
   void onHit() {};
   vector<Entity*> die();
   void draw(ogstream* pgout)
   {
      pgout->drawCrewDragon(position, angle.getRadians());
   }
};

