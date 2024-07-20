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
#include "part.h"
class TestPart : public UnitTest
{
public:
   void run()
   {
      testConstructor();
      report("Part");
   }
private:
   void testConstructor()
   {
      //SETUP
      Position pos(0,0);
      float radius = 1;
      float a = 1;
      //EXERCISE and finish setup
      Part p(a, radius, pos);

      //VERIFY
      closeEnough(.0001,p.angle.getRadians() == a);
      // Velocity should be in this range
      assertUnit(p.velocity.getSpeed() >= 5000);
      assertUnit(p.velocity.getSpeed() <= 9000);

      //TEARDOWN
   }
};
