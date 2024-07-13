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
   Hubble(const Position& pos,const Velocity& vel,const float& a,const bool& dead, const double& radius = 0) :
      Satellite(pos, vel, a, dead, radius) {}
   void draw(ogstream* pgout)
   {
      pgout->drawHubble(position, angle.getRadians());
   }
};

