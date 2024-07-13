#pragma once
#include "fragment.h"
#include "uiDraw.h"
class Bullet :
    public Fragment
{
public:
   Bullet(const Position& pos, const Velocity& vel, const float& a, const bool& dead, const double& radius = 1) : Fragment(pos, vel, a, dead, radius) { this->lifespan = 70; }
   void draw(ogstream* gout)
   {
      gout->drawProjectile(position);
   }
   vector<Entity*> die() {
      vector<Entity*> v;
      return v;
   };
};

