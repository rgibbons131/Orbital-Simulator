/***********************************************************************
 * Heaader File:
 *    Sputnik : Sputik satellite
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the Sputnik satellite entity
 ************************************************************************/
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

