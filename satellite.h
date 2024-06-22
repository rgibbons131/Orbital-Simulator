#pragma once
#include "entity.h"
class Satellite : public Entity
{
public:
   Satellite() : Entity() {}
   Satellite(Position pos, Velocity vel, float a, bool dead) : Entity(pos, vel, a, dead) {}
   Satellite(Satellite& rhs);
   void onHit() {die();}       // Add fragment logic here later
   void die()   {dead = true;}

};

