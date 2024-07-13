/***********************************************************************
 * Header File:
 *    Test Satellite : test the satellite class
 * Author:
 *    Richard, Taemour, Aria
 * Summary:
 *    All the unit tests for Satellite
 ************************************************************************/
#pragma once
#include "unitTest.h"
#include "satellite.h"
class TestSatellite : public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testConstructorStandard();
      testDie();
      report("Satellite");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      Satellite sat;
      //EXERCISE

      //VERIFY
      assertUnit(sat.angle.radians == 0.0);
      assertUnit(sat.velocity.dx == 0.0);
      assertUnit(sat.velocity.dy == 0.0);
      assertUnit(sat.position.x == 0.0);
      assertUnit(sat.position.y == 0.0);
      assertUnit(sat.radius == 0.0);

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
      Satellite sat(pos, vel, angle, dead, radius);
      //VERIFY
      assertUnit(sat.angle.radians == 0.0);
      assertUnit(sat.velocity.dx == 0.0);
      assertUnit(sat.velocity.dy == 0.0);
      assertUnit(sat.position.x == 0.0);
      assertUnit(sat.position.y == 0.0);
      assertUnit(sat.dead == false);
      assertUnit(sat.radius == 0.0);

      //TEARDOWN
   }
   void testDie()
   {
      //SETUP
      Satellite sat;

      //EXERCISE
      sat.die();
      //VERIFY
      assertUnit(sat.dead == true);
      //TEARDOWN
   }
};

