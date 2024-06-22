#pragma once
#include "position.h"
#include "velocity.h"
#include "direction.h"

class ogstream;
class TestEntity;



class Entity
{
public:
    
   friend TestEntity;
   Entity() : position(Position()), velocity(Velocity()), angle(0.0), dead(false){}
   Entity(Position pos, Velocity vel, float a, bool dead) : 
      position(pos), velocity(vel), angle(a), dead(dead){}
   Entity(Entity& rhs);
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   float    getAngle()    const { return angle;    }

   void setPosition(Position& pos) { position = pos; }
   void setVelocity(Velocity& vel) { velocity = vel; }
   void setAngle(Direction ang)       { angle = ang; }

   virtual void onHit() {}
   virtual void die() {}
   virtual void draw(ogstream* pgout) {}
   virtual void move() {}
   

protected:

   bool     dead;
   Position  position;
   Velocity  velocity;
   Direction angle;
};

