/***********************************************************************
 * Heaader File:
 *    Starlink : Starlink satellite
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the starlink satellite entity
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"

class TestStarlink;

class Starlink : public Satellite
{
public:
   friend TestStarlink;
   Starlink() : Satellite() { this->radius = 6; }
   Starlink(const Position& pos,const Velocity& vel,const float& a,const bool& dead, const double& radius = 6) :
      Satellite(pos, vel, a, dead, radius) {}
   vector<Entity*> die();
   void draw(ogstream* pgout)
   {
      pgout->drawStarlink(position, angle.getRadians());
   }
};

