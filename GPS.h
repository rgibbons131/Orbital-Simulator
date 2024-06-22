#pragma once
#include "satellite.h"
#include "uiDraw.h"


class GPS : public Satellite
{
public:
   GPS() : Satellite() {}
   GPS(Position pos, Velocity vel, float a, bool dead) : 
      Satellite(pos, vel, a, dead) {}
   GPS(GPS& rhs);
   void draw(ogstream* pgout)
   {
      pgout->drawGPS(position, angle.getRadians());
   }
};

