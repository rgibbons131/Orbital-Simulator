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
   Fragment() : Satellite(), lifespan(random(50, 100)), spin(random(0.0, 6.2)) { this->radius = 2; }
   Fragment(const Position& pos, const Velocity& vel, const float& a, const bool& dead, const double& radius = 2) : Satellite(pos, vel, a, dead, radius), lifespan(random(50, 100)), spin(random(0.0, 6.2)) 
   { 
      this->position.addPixelsX(getHorizontalAccel(a, 4));
      this->position.addPixelsY(getVerticalAccel(a, 4));
      double kick = random(5000, 9000);
      this->velocity.addDx(getHorizontalAccel(a, kick));
      this->velocity.addDy(getVerticalAccel(a, kick));
   }
   void onHit() { dead = true; }
   void draw(ogstream* pgout)
   {
      pgout->drawFragment(position, angle.getRadians());
   }
   void move(const Interface* pUI);
protected:
   int lifespan;
   double spin;
};

