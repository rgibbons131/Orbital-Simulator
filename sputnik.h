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
   Sputnik(const Position& pos,const Velocity& vel,const float& a,const bool& dead, const double& radius = 0) :
      Satellite(pos, vel, a, dead, radius) {}
   void draw(ogstream* pgout)
   {
      pgout->drawSputnik(position, angle.getRadians());
   }
};

