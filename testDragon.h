/***********************************************************************
 * Header File:
 *    Test Dragon : test the dragon class
 * Author:
 *    Richard, Taemour, Aria
 * Summary:
 *    All the unit tests for Dragon
 ************************************************************************/
#pragma once
#include "unitTest.h"
#include "dragon.h"
class TestDragon : public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testConstructorStandard();
      testOnHit();
      report("Dragon");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      Dragon drg;
      //EXERCISE

      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.radius = 0.0);

      //TEARDOWN
   }
   void testConstructorStandard()
   {
      //SETUP
      Position pos;
      Velocity vel;
      double angle = 0.0;
      bool dead = false;
      double radius = 0.0;

      //EXERCISE
      Dragon drg(pos, vel, angle, dead, radius);
      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.dead == false);
      assertUnit(drg.radius = 0.0);

      //TEARDOWN
   }
   void testDie()
   {
      //SETUP
      Dragon drg;

      //EXERCISE
      vector<Entity*> result = drg.die();
      //VERIFY
      assertUnit(result.size() == 5);
      assertUnit(result[0]. == &ogstream::drawCrewDragonCenter);
      //TEARDOWN
   }
};

