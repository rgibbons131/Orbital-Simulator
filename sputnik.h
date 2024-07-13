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
   Sputnik(const Position& pos,const Velocity& vel,const float& a,const bool& dead) :
      Satellite(pos, vel, a, dead) {}
   void draw(ogstream* pgout)
   {
      pgout->drawSputnik(position, angle.getRadians());
   }
};

