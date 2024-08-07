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

class TestSatellite;

class Satellite : public Entity
{
public:
   friend TestSatellite;
   Satellite() : Entity() {}
   Satellite(const Position& pos, const Velocity& vel, const float& a, const bool& dead, const double& radius = 0) : Entity(pos, vel, a, dead) { this->radius = radius; }
   void onHit() { dead = true; }       // Add fragment logic here later
};

