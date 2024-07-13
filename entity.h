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



class Entity
{
public:
    
   friend TestEntity;
   Entity() : position(Position(0.0, 0.0)), velocity(Velocity(0.0, 0.0)), angle(0.0), dead(false){}
   Entity(const Position & pos,const Velocity & vel,const float & a,const bool & dead) : 
      position(pos), velocity(vel), angle(a), dead(dead){}
   Entity(const Entity& rhs);
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   Direction    getAngle()    const { return angle;    }

   void setPosition(const Position& pos) { position = pos; }
   void setVelocity(const Velocity& vel) { velocity = vel; }
   void setAngle(const Direction& ang)       { angle = ang; }

   Entity& operator= (const Entity& rhs);

   virtual void onHit() {}
   virtual vector<Entity> die() {
      vector<Entity> v;
      return v; 
   }
   virtual void draw(ogstream* pgout) {}
   virtual void move(const Interface* pUI);
   

protected:

   bool     dead;
   Position  position;
   Velocity  velocity;
   Direction angle;
};

