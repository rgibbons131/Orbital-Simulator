/***********************************************************************
 * Heaader File:
 *    GPS : GPS Satellite
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the GPS satellite entity
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"


class GPS : public Satellite
{
public:
   GPS() : Satellite() {}
   GPS(const Position& pos,const Velocity& vel,const float& a,const bool& dead, const double& radius = 0) :
      Satellite(pos, vel, a, dead, radius) {}
   void draw(ogstream* pgout)
   {
      pgout->drawGPS(position, angle.getRadians());
   }
};

