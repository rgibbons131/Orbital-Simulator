/***********************************************************************
 * Heaader File:
 *    Hubble : Hubble Satellite
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the Hubble satellite entity
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Hubble : public Satellite
{
public:
   Hubble() : Satellite() {}
   Hubble(Position pos, Velocity vel, float a, bool dead) :
      Satellite(pos, vel, a, dead) {}
   Hubble(Hubble& rhs);
   void draw(ogstream* pgout)
   {
      pgout->drawHubble(position, angle.getRadians());
   }
};

