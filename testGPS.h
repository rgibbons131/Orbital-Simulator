/***********************************************************************
 * Header File:
 *    Test GPS : test the GPS class
 * Author:
 *    Richard, Taemour, Aria
 * Summary:
 *    All the unit tests for GPS
 ************************************************************************/
#pragma once
#include "unitTest.h"
#include "GPS.h"
#include "part.h"
#include "fragment.h"
class TestGPS : public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testConstructorStandard();
      testDie();
      report("GPS");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      GPS drg;
      //EXERCISE

      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.radius == 12.0);

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
      GPS drg(pos, vel, angle, dead, radius);
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
      GPS drg;

      //EXERCISE
      vector<Entity*> result = drg.die();
      //VERIFY
      assertUnit(result.size() == 5);
      //TEARDOWN
   }
};