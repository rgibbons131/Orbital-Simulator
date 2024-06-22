#pragma once
#include "position.h"
#include "velocity.h"


class TestEntity;



class Entity
{
public:

   friend TestEntity;
   Position getPosition() const { return position; }
   Velocity getVelocity() const { return velocity; }
   float    getAngle()    const { return angle;    }

   void setPosition(Position& pos) { position = pos; }
   void setVelocity(Velocity& vel) { velocity = vel; }
   void setAngle(float ang)       { angle = ang; }


protected:
   Position position;
   Velocity velocity;
   float    angle;
};

