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
#include "fragment.h"
#include "uiInteract.h"
class TestFragment : public UnitTest
{
public:
   void run()
   {
      testUpdateStatus();
      testDieOnLifespan0();
      testLiveOnLifespan1();
      report("Fragment");
   }
private:
   void testUpdateStatus()
   {
      //SETUP
      Fragment f;
      f.lifespan = 1;
      // Fragment do not utilize the interface, so even though it is passed, nothing should happen, thus the dummy
      DummyInterface* i = new DummyInterface();

      //EXERCISE
      f.statusUpdate(i);

      //VERIFY
      assertUnit(f.lifespan == 0);

      //TEARDOWN
      delete i;
   }


   void testDieOnLifespan0()
   {
      //SETUP
      Fragment f;
      f.lifespan = 1;
      DummyInterface* i = new DummyInterface();

      //EXERCISE
      f.move(i);

      //VERIFY
      assertUnit(f.lifespan == 0);
      assertUnit(f.dead == true);

      //CLEANUP
      delete i;

   }
   void testLiveOnLifespan1()
   {
      //SETUP
      Fragment f;
      f.lifespan = 2;
      DummyInterface* i = new DummyInterface();

      //EXERCISE
      f.move(i);

      //VERIFY
      assertUnit(f.lifespan == 1);
      assertUnit(f.dead == false);

      //CLEANUP
      delete i;

   }
};
