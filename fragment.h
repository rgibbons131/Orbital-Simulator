/***********************************************************************
 * Header File:
 *    Fragment : The fragment class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents fragments within the simulation.
 ************************************************************************/
#pragma once
#include "entity.h"
#include "uiDraw.h"

class TestFragment;

class Fragment : public Entity
{

public:
   friend TestFragment;
   Fragment() : Entity() {}
   Fragment(const Position& pos, const Velocity& vel, const float& a, const bool& dead) : Entity(pos, vel, a, dead) {}
   void onHit() { die(); }
   void die() { dead = true; }
   void draw(ogstream* pgout)
   {
      pgout->drawFragment(position, angle.getRadians());
   }
};

