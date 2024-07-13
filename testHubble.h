/***********************************************************************
 * Header File:
 *    Test Hubble : test the Hubble class
 * Author:
 *    Richard, Taemour, Aria
 * Summary:
 *    All the unit tests for Hubble
 ************************************************************************/
#pragma once
#include "unitTest.h"
#include "Hubble.h"
#include "part.h"
#include "fragment.h"
class TestHubble : public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testConstructorStandard();
      testDie();
      report("Hubble");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      Hubble drg;
      //EXERCISE

      //VERIFY
      assertUnit(drg.angle.radians == 0.0);
      assertUnit(drg.velocity.dx == 0.0);
      assertUnit(drg.velocity.dy == 0.0);
      assertUnit(drg.position.x == 0.0);
      assertUnit(drg.position.y == 0.0);
      assertUnit(drg.radius == 10.0);

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
      Hubble drg(pos, vel, angle, dead, radius);
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
      Hubble drg;

      //EXERCISE
      vector<Entity*> result = drg.die();
      //VERIFY
      assertUnit(result.size() == 5);
      //TEARDOWN
   }
};