/***********************************************************************
 * Header File:
 *    Satellite : The satellite class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the satellite entities within the simulation.
 ************************************************************************/
#pragma once
#include "entity.h"
class Satellite : public Entity
{
public:
   Satellite() : Entity() {}
   Satellite(const Position& pos,const Velocity& vel,const float& a,const bool& dead) : Entity(pos, vel, a, dead) {}
   void onHit() {die();}       // Add fragment logic here later
   void die()   {dead = true;}

};

