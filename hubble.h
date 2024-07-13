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

class TestHubble;

class Hubble : public Satellite
{
public:
   friend TestHubble;
   Hubble() : Satellite() { this->radius = 10; }
   Hubble(const Position& pos,const Velocity& vel,const float& a,const bool& dead, const double& radius = 10) :
      Satellite(pos, vel, a, dead, radius) {}
   vector<Entity*> die();
   void draw(ogstream* pgout)
   {
      pgout->drawHubble(position, angle.getRadians());
   }
};

