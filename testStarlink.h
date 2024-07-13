/***********************************************************************
 * Header File:
 *    Test Starlink : test the Starlinkclass
 * Author:
 *    Richard, Taemour, Aria
 * Summary:
 *    All the unit tests for Starlink
 ************************************************************************/
#pragma once
#include "unitTest.h"
#include "starlink.h"
#include "part.h"
#include "fragment.h"
class TestStarlink : public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testConstructorStandard();
      testDie();
      report("Starlink");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      Starlink drg;
      //EXERCISE

      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.radius == 6.0);

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
      Starlink drg(pos, vel, angle, dead, radius);
      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.dead == false);
      assertUnit(drg.radius == 0.0);

      //TEARDOWN
   }
   void testDie()
   {
      //SETUP
      Starlink drg;

      //EXERCISE
      vector<Entity*> result = drg.die();
      //VERIFY
      assertUnit(result.size() == 4);
      //TEARDOWN
   }
};