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
   Entity() : angle(Direction(0.0)), position(Position(0.0, 0.0)), velocity(Velocity(0.0, 0.0)) {}
   Position  getPosition() const { return position; }
   Velocity  getVelocity() const { return velocity; }
   Direction getAngle()    const { return angle;    }

   void setPosition(Position& pos) { position = pos; }
   void setVelocity(Velocity& vel) { velocity = vel; }
   void setAngle(Direction ang)       { angle = ang; }

   void onHit() {}

   virtual void draw(ogstream* pgout) {}
   virtual void move() {}
   

protected:
   Position  position;
   Velocity  velocity;
   Direction angle;
};

