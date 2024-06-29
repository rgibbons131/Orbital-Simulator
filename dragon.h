#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Dragon : public Satellite
{
public:
   Dragon() : Satellite() {}
   Dragon(Position pos, Velocity vel, float a, bool dead) :
      Satellite(pos, vel, a, dead) {}
   Dragon(Dragon& rhs);
   void draw(ogstream* pgout)
   {
      pgout->drawCrewDragon(position, angle.getRadians());
   }
};

