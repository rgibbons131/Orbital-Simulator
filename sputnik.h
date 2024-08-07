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

class TestSputnik;

class Sputnik : public Satellite
{
public:
   friend TestSputnik;
   Sputnik() : Satellite() { this->radius = 4; }
   Sputnik(const Position& pos,const Velocity& vel,const float& a,const bool& dead, const double& radius = 4) :
      Satellite(pos, vel, a, dead, radius) {}
   vector<Entity*> die();
   void draw(ogstream* pgout)
   {
      pgout->drawSputnik(position, angle.getRadians());
   }
};

