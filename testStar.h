#pragma once
#include "unitTest.h"
#include "star.h"
class TestStar :
    public UnitTest
{
public:
   void run()
   {
      testDefaultConstructor();
      testTwinkle();
      report("Star");
   }
private:
   void testDefaultConstructor()
   {
      //SETUP
      Star star;
      Position pos = star.position;
      unsigned char phase = star.phase;
      //EXERCISE

      //VERIFY
      assertUnit(pos.x >= -60000000.0);
      assertUnit(pos.x <= 60000000.0);
      assertUnit(pos.y >= -60000000.0);
      assertUnit(pos.y <= 60000000.0);
      assertUnit(phase <= 256);
      assertUnit(phase >= 1);

      //TEARDOWN
   }
   void testTwinkle()
   {
      //SETUP
      Star star;
      unsigned char prePhase = star.phase;
      //EXERCISE
      star.twinkle();
      //VERIFY
      assertUnit(prePhase = star.phase + 1);

      //TEARDOWN
   }
};

