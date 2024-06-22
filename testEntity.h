#pragma once
#include "entity.h"
#include "position.h"
#include "velocity.h"
#include <cassert>
#include "unitTest.h"
#include "physics.h"
#include "constants.cpp"
class TestEntity : public UnitTest
{
public:
   void run()
   {
      testConstructor();
      testGetVelocityStandard();
      testSetVelocitySmall();
      testSetVelocityLargeNegative();
      testSetVelocityLargePositive();
      testGetPositionSmallDecimal();
      testSetPositionZero();
      testSetPositionTopRight();
      testSetPositionBottomLeft();
      testGetAngleZero();
      testSetAngleLargePositive();
      testSetAngleLargeNegative();
      testSetAngle2Pi();

      report("Entity");
   }


private:
   /*
   Constructor : default
   Input :
   output: angle=0.0
           velocity=0.0
           position=0.0
   */
   void testConstructor()
   {
      //SETUP
      Entity ent;
      //EXERCISE

      //VERIFY
      assertUnit(ent.angle == 0.0);
      assertUnit(ent.velocity.dx == 0.0);
      assertUnit(ent.velocity.dy == 0.0);
      assertUnit(ent.position.x = 0.0);
      assertUnit(ent.position.y = 0.0);

      //TEARDOWN

   }

   /*
   getVelocity : standard
   Input : velocity=10.0, 10.0
   output: 14.1421

   */

   void testGetVelocityStandard()
   {
      //SETUP
      Entity ent;
      Velocity vel;
      vel.dx = 10.0;
      vel.dy = 10.0;
      ent.velocity = vel;
      //EXERCISE
      double result = ent.getVelocity().getSpeed();
      //VERIFY
      assertUnit(result == 14.1421);
      //TEARDOWN

   }

   /*
   setVelocity : small decimal
   Input : 0.00001, 0.00001
   output: velocity= 0.0

   */
   void testSetVelocitySmall()
   {
      //SETUP
      Entity ent;
      Velocity vel;
      vel.dx = 0.001;
      vel.dy = 0.001;

      //EXERCISE
      ent.setVelocity(vel);
      //VERIFY
      assertUnit(ent.velocity == 0.0014);
      //TEARDOWN

   }

   /*
   setVelocity : large negative 
   Input : -10000.0, -10000.0
   output: velocity= 14142.1356

   */
   void testSetVelocityLargeNegative()
   {
      //SETUP
      Entity ent;
      Velocity vel;
      vel.dx = -10000.0;
      vel.dy = -10000.0;

      //EXERCISE
      ent.setVelocity(vel);
      //VERIFY
      assertUnit(ent.velocity == 14142.1356);
      //TEARDOWN

   }

   /*
   setVelocity : large positive
   Input : 10000.0
   output: velocity= 10000.0

   */
   void testSetVelocityLargePositive()
   {
      //SETUP
      Entity ent;
      Velocity vel;
      vel.dx = 10000.0;
      vel.dy = 10000.0;

      //EXERCISE
      ent.setVelocity(vel);
      //VERIFY
      assertUnit(ent.velocity == 14142.1356);
      //TEARDOWN

   }

   /*
   getPosition : small decimal
   Input : 0.001,0.001
   output: position = 0.001, 0.001

   */
   void testGetPositionSmallDecimal()
   {
      //SETUP
      Entity ent;
      Position pos;
      pos.x = 0.001;
      pos.y = 0.001;
      ent.position = pos;
      //EXERCISE
      Position result = ent.getPosition();
      //VERIFY
      assertUnit(result.x == 0.001);
      assertUnit(result.y == 0.001);
      //TEARDOWN

   }

   /*
   setPosition : zero
   Input : position = 0.0,0.0
   output: 0.0, 0.0

   */
   void testSetPositionZero()
   {
      //SETUP
      Entity ent;
      Position posI;
      posI.x = 0.001;
      posI.y = 0.001;
      ent.position = posI;
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;

      //EXERCISE
      ent.setPosition(pos);
      //VERIFY
      assertUnit(ent.position.x == 0.0);
      assertUnit(ent.position.y == 0.0);
      //TEARDOWN

   }

   /*
   setPosition : topRight
   Input : position = 1000.0, 1000.0
   output: 1000.0, 1000.0

   */
   void testSetPositionTopRight()
   {
      //SETUP
      Entity ent;
      Position pos;
      pos.x = 1000.0;
      pos.y = 1000.0;
      //EXERCISE
      ent.setPosition(pos);
      //VERIFY
      assertUnit(ent.position.x == 1000.0);
      assertUnit(ent.position.y == 1000.0);
      //TEARDOWN

   }

   /*
   setPosition : bottomLeft
   Input : position = -1000.0, -1000.0
   output: -1000.0, -1000.0

   */
   void testSetPositionBottomLeft()
   {
      //SETUP
      Entity ent;
      Position pos;
      pos.x = -1000.0;
      pos.y = -1000.0;
      //EXERCISE
      ent.setPosition(pos);
      //VERIFY
      assertUnit(ent.position.x == 1000.0);
      assertUnit(ent.position.y == 1000.0);
      //TEARDOWN

   }

   /*
   getAngle : zero
   Input : 0.0
   output: angle = 0.0

   */
   void testGetAngleZero()
   {
      //SETUP
      Entity ent;
      float angle = 0.0;
      ent.angle = angle;

      //EXERCISE
      auto result = ent.getAngle();
      //VERIFY
      assertUnit(result == 0.0);
      //TEARDOWN

   }

   /*
   setAngle : largePositive
   Input : 10000.0
   output: angle = 3.452

   */
   void testSetAngleLargePositive()
   {
      //SETUP
      Entity ent;
      //EXERCISE
      ent.setAngle(10000.0);
      //VERIFY
      assertUnit(ent.angle == 3.452);
      //TEARDOWN

   }

   /*
   setAngle : large Negative
   Input : -10000.0
   output: angle = 2.831

   */
   void testSetAngleLargeNegative()
   {
      //SETUP
      Entity ent;
      //EXERCISE
      ent.setAngle(-10000.0);
      //VERIFY
      assertUnit(ent.angle == 2.831);
      //TEARDOWN

   }

   /*
   setAngle : 2PI
   Input : 2 * PI
   output: angle = 0.0

   */
   void testSetAngle2Pi()
   {
      //SETUP
      Entity ent;
      //EXERCISE
      ent.setAngle(2.0 * M_PI);
      //VERIFY
      assertUnit(ent.angle == 0.0);
      //TEARDOWN

   }

};