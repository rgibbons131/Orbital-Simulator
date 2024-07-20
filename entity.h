/***********************************************************************
 * Header File:
 *    Entity : The entity class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents entities within the simulation.
 ************************************************************************/
#pragma once
#include <vector>
#include "position.h"
#include "velocity.h"
#include "direction.h"
#include "physics.h"
#include "uiInteract.h"

class ogstream;
class TestEntity;
class TestSatellite;



class Entity
{
public:
    
   friend TestEntity;
   Entity() : position(Position(0.0, 0.0)), velocity(Velocity(0.0, 0.0)), angle(0.0), dead(false), radius(0.0){}
   Entity(const Position & pos,const Velocity & vel,const float & a,const bool & dead, const double & radius=0) : 
      position(pos), velocity(vel), angle(a), dead(dead), radius(radius){}
   Entity(const Entity& rhs);
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   Direction    getAngle()    const { return angle;    }
   double   getRadius() const { return radius; }

   void setPosition(const Position& pos) { position = pos; }
   void setVelocity(const Velocity& vel) { velocity = vel; }
   void setAngle(const Direction& ang)      { angle = ang; }
   bool const isTouching(const Position& pos, double r) { return (r + radius > position.computeDistancePx(position, pos)); }
   bool const isDead() { return dead; }

   Entity& operator= (const Entity& rhs);

   virtual void onHit() { dead = true; }
   virtual vector<Entity *> die() {
      vector<Entity *> v;
      return v; 
   }
   virtual void statusUpdate() {}
   virtual void draw(ogstream* pgout) {}
   virtual void move(const Interface* pUI);
   

protected:

   bool     dead;
   Position  position;
   Velocity  velocity;
   Direction angle;
   double radius;
};

