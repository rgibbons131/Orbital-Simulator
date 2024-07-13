/***********************************************************************
 * Header File:
 *    Entity : The entity class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents entities within the simulation.
 ************************************************************************/
#pragma once
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
   Entity(Position pos, Velocity vel, float a, bool dead) : 
      position(pos), velocity(vel), angle(a), dead(dead){}
   Entity(const Entity& rhs);
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   Direction    getAngle()    const { return angle;    }

   void setPosition(Position& pos) { position = pos; }
   void setVelocity(Velocity& vel) { velocity = vel; }
   void setAngle(Direction ang)       { angle = ang; }

   Entity& operator= (const Entity& rhs);

   virtual void onHit() {}
   virtual void die() {}
   virtual void draw(ogstream* pgout) {}
   virtual void move(const Interface* pUI);
   

protected:

   bool     dead;
   Position  position;
   Velocity  velocity;
   Direction angle;
};

