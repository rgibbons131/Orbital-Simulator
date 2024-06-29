#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Sputnik : public Satellite
{
public:
   Sputnik() : Satellite() {}
   Sputnik(Position pos, Velocity vel, float a, bool dead) :
      Satellite(pos, vel, a, dead) {}
   Sputnik(Sputnik& rhs);
   void draw(ogstream* pgout)
   {
      pgout->drawSputnik(position, angle.getRadians());
   }
};

