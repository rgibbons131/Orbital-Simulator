/*************************************************************
 * 1. Name:
 *      Orbital simulator
 * 2. Assignment Name:
 *      Lab 13: Orbit Simulator
 *  * Group Members:
 *    Richard, Taemour, Aria
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 *****************************************************************/
#pragma once
#include <cassert>      // for ASSERT
#include <vector>
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include "physics.h"
#include "entity.h"
#include "GPS.h"
#include "satellite.h"
#include "starlink.h"
#include "dragon.h"
#include "sputnik.h"
#include "hubble.h"
#include "dreamChaser.h"
#include "earth.h"
#include "star.h"
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight)
   {
      //GPS1
      ptGPS1.setMetersX(0.0);
      ptGPS1.setMetersY(26560000.0);
      angleGPS1 = 0.0;

      Velocity initialGPSv1 = Velocity(-3880.0, 0.0);

      gps1.setPosition(ptGPS1);
      gps1.setVelocity(initialGPSv1);
      gps1.setAngle(angleGPS1);

      entities.push_back(&gps1);

      //GPS2
      ptGPS2.setMetersX(23001634.72);
      ptGPS2.setMetersY(13280000.0);
      angleGPS2 = 0.0;

      Velocity initialGPSv2 = Velocity(-1940.0, 3360.18);

      gps2.setPosition(ptGPS2);
      gps2.setVelocity(initialGPSv2);
      gps2.setAngle(angleGPS2);

      entities.push_back(&gps2);

      //GPS3
      ptGPS3.setMetersX(23001634.72);
      ptGPS3.setMetersY(-13280000.0);
      angleGPS3 = 0.0;

      Velocity initialGPSv3 = Velocity(1940.00, 3360.18);

      gps3.setPosition(ptGPS3);
      gps3.setVelocity(initialGPSv3);
      gps3.setAngle(angleGPS3);

      entities.push_back(&gps3);

      //GPS4
      ptGPS4.setMetersX(0.0);
      ptGPS4.setMetersY(-26560000.0);
      angleGPS4 = 0.0;

      Velocity initialGPSv4 = Velocity(3880.0, 0.0);

      gps4.setPosition(ptGPS4);
      gps4.setVelocity(initialGPSv4);
      gps4.setAngle(angleGPS4);

      entities.push_back(&gps4);

      //GPS5
      ptGPS5.setMetersX(-23001634.72);
      ptGPS5.setMetersY(-13280000.0);
      angleGPS5 = 0.0;

      Velocity initialGPSv5 = Velocity(1940.00, -3360.18);

      gps5.setPosition(ptGPS5);
      gps5.setVelocity(initialGPSv5);
      gps5.setAngle(angleGPS5);

      entities.push_back(&gps5);

      //GPS6
      ptGPS6.setMetersX(-23001634.72);
      ptGPS6.setMetersY(13280000.0);
      angleGPS6 = 0.0;

      Velocity initialGPSv6 = Velocity(-1940.00, -3360.18);

      gps6.setPosition(ptGPS6);
      gps6.setVelocity(initialGPSv6);
      gps6.setAngle(angleGPS6);

      entities.push_back(&gps6);

      //Starlink
      ptStarlink.setMetersX(0.0);
      ptStarlink.setMetersY(-13020000.0);
      angleStarlink = 0.0;

      Velocity initialStarlinkV = Velocity(5800.0, 0.0);

      starlink.setPosition(ptStarlink);
      starlink.setVelocity(initialStarlinkV);
      starlink.setAngle(angleStarlink);

      entities.push_back(&starlink);

      //Sputnik
      ptSputnik.setMetersX(-36515095.13);
      ptSputnik.setMetersY(21082000.0);
      angleSputnik = 0.0;

      Velocity initialSputnikV = Velocity(2050.0, 2684.68);

      sputnik.setPosition(ptSputnik);
      sputnik.setVelocity(initialSputnikV);
      sputnik.setAngle(angleSputnik);

      entities.push_back(&sputnik);

      //Hubble
      ptHubble.setMetersX(0.0);
      ptHubble.setMetersY(-42164000.0);
      angleHubble = 0.0;

      Velocity initialHubbleV = Velocity(-3100.0, 0.0);

      hubble.setPosition(ptHubble);
      hubble.setVelocity(initialHubbleV);
      hubble.setAngle(angleHubble);

      entities.push_back(&hubble);

      //Dragon
      ptCrewDragon.setMetersX(0.0);
      ptCrewDragon.setMetersY(8000000.0);
      angleDragon = 0.0;

      Velocity initialDragonV = Velocity(-7900.0, 0.0);

      dragon.setPosition(ptCrewDragon);
      dragon.setVelocity(initialDragonV);
      dragon.setAngle(angleDragon);

      entities.push_back(&dragon);
      
      //stars

      for (int i = 0; i < 200; i++)
      {
         starVec.push_back(new Star());
      }

      //Ship
      ptShip.setPixelsX(-450);
      ptShip.setPixelsY(450);
      angleShip= 0.0;

      Velocity initialShipV = Velocity(0.0, 0.0);

      ship.setPosition(ptShip);
      ship.setVelocity(initialShipV);
      ship.setAngle(angleShip);

      entities.push_back(&ship);

      entities.push_back(&earth);
   }
   float velocityX;
   float velocityY;
   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS1;
   Position ptGPS2;
   Position ptGPS3;
   Position ptGPS4;
   Position ptGPS5;
   Position ptGPS6;
   Position ptStar;
   Position ptUpperRight;
   GPS      gps1;
   GPS      gps2;
   GPS      gps3;
   GPS      gps4;
   GPS      gps5;
   GPS      gps6;
   Starlink starlink;
   Sputnik  sputnik;
   Hubble   hubble;
   Dragon   dragon;
   DreamChaser ship;
   Earth earth;
   vector<Entity *> entities;
   Star* starList[200];
   vector<Star*> starVec;


   unsigned char phaseStar;

   double angleShip;
   double angleGPS1;
   double angleGPS2;
   double angleGPS3;
   double angleGPS4;
   double angleGPS5;
   double angleGPS6;
   double angleStarlink;
   double angleSputnik;
   double angleHubble;
   double angleDragon;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // perform all the game logic

   //Twinkle Stars
   for (int i = 0; i < pDemo->starVec.size(); i++) {
      pDemo->starVec[i]->twinkle();
   }

   // move all entities
   for (int i = 0; i < pDemo->entities.size(); i++)
   {
      pDemo->entities[i]->move(pUI);
   }
      
   // detect collisions
   for (int index1 = 0; index1 < pDemo->entities.size() - 1; index1++)
   {
      auto entity1 = pDemo->entities[index1];
      for (int index2 = index1 + 1; index2 < pDemo->entities.size(); index2++)
      {
         auto entity2 = pDemo->entities[index2];
         if (entity1->isTouching(entity2->getPosition(), entity2->getRadius()))
         {
            entity1->onHit();
            entity2->onHit();
         }
      }
   }

   // create new entities from collision
   vector<int> deadIndecies;
   vector<Entity*> newEntities;
   for (int index1 = 0; index1 < pDemo->entities.size(); index1++)
   {
      if (pDemo->entities[index1]->isDead())
      {
         vector<Entity *> currentEnt = pDemo->entities[index1]->die();
         deadIndecies.push_back(index1);
         for (int index2 = 0; index2 < currentEnt.size(); index2++)
         {
            newEntities.push_back(currentEnt[index2]);
         }
      }
   }

   for (int index2 = 0; index2 < newEntities.size(); index2++)
   {
      pDemo->entities.push_back(newEntities[index2]);
   }

   // create bullets
   if (pDemo->ship.isShooting())
   {
      Entity* bullet = pDemo->ship.shoot();
      pDemo->entities.push_back(bullet);
   }

   // kill dead entities
   for (int index = deadIndecies.size() - 1; index >=0; index--)
   {
      auto itr = pDemo->entities.begin();
      int dead = deadIndecies[index];
      pDemo->entities.erase( itr + dead);
      deadIndecies.pop_back();
   }

   Position pt;
   ogstream gout(pt);

   // draw all Entities


   for (int i = 0; i < pDemo->entities.size(); i++)
   {
      pDemo->entities[i]->draw(&gout);
   }

   for (int i = 0; i < pDemo->starVec.size(); i++) {
      pDemo->starVec[i]->draw(&gout);
   }
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Run Tests
   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Simulator",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
