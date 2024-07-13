/***********************************************************************
 * Header File:
 *    Test Sputnik : test the Sputnik class
 * Author:
 *    Richard, Taemour, Aria
 * Summary:
 *    All the unit tests for Sputnik
 ************************************************************************/
#pragma once
#include "unitTest.h"
#include "sputnik.h"
#include "part.h"
#include "fragment.h"
class TestSputnik : public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testConstructorStandard();
      testDie();
      report("Sputnik");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      Sputnik drg;
      //EXERCISE

      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.radius == 4.0);

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
      Sputnik drg(pos, vel, angle, dead, radius);
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
      Sputnik drg;

      //EXERCISE
      vector<Entity*> result = drg.die();
      //VERIFY
      assertUnit(result.size() == 4);
      //TEARDOWN
   }
};