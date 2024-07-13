/***********************************************************************
 * Header File:
 *    Fragment : The fragment class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents fragments within the simulation.
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"

class TestFragment;

class Fragment : public Satellite
{

public:
   friend TestFragment;
   Fragment() : Satellite() { this->radius = 2; }
   Fragment(const Position& pos, const Velocity& vel, const float& a, const bool& dead, const double& radius = 2) : Satellite(pos, vel, a, dead, radius) {}
   void onHit() { die(); }
   void draw(ogstream* pgout)
   {
      pgout->drawFragment(position, angle.getRadians());
   }
};

