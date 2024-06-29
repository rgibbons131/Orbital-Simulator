#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Starlink : public Satellite
{
public:
   Starlink() : Satellite() {}
   Starlink(Position pos, Velocity vel, float a, bool dead) :
      Satellite(pos, vel, a, dead) {}
   Starlink(Starlink& rhs);
   void draw(ogstream* pgout)
   {
      pgout->drawStarlink(position, angle.getRadians());
   }
};

