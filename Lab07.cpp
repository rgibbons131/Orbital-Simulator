/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
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
      
      //phaseStar = 0;

      //Ship
      ptShip.setMetersX(-36515195.13);
      ptShip.setMetersY(21082000.0);
      angleShip= 0.0;

      Velocity initialShipV = Velocity(0.0, 0.0);

      ship.setPosition(ptShip);
      ship.setVelocity(initialShipV);
      ship.setAngle(angleShip);

      entities.push_back(&ship);

      // Initial velocity
      angleEarth = 0.0;
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
   vector<Entity *> entities;


   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
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
   // accept input
   //

   // move by a little
   //if (pUI->isUp())
   //   pDemo->ptShip.addPixelsY(1.0);
   //if (pUI->isDown())
   //   pDemo->ptShip.addPixelsY(-1.0);
   //if (pUI->isLeft())
   //   pDemo->ptShip.addPixelsX(-1.0);
   //if (pUI->isRight())
   //   pDemo->ptShip.addPixelsX(1.0);


   //
   // perform all the game logic
   //

   // rotate the earth
   auto earthRotationSpeed = getEarthRotationSpeed();
   pDemo->angleEarth += earthRotationSpeed;

   for (int i = 0; i < pDemo->entities.size(); i++)
   {
      pDemo->entities[i]->move(pUI);
   }

   // Calculate height above Earth
   /*
   float height = getHeightAboveEarth(pDemo->gps.getPosition().getMetersX(), pDemo->gps.getPosition().getMetersY());

   
   // Calculate gravitational acceleration
   float gravity = getGravity(height);
   float gravityDirection = getDirectionOfGravityPull(pDemo->gps.getPosition().getMetersX(), pDemo->gps.getPosition().getMetersY());
   float accelX = getHorizontalAccel(gravityDirection, gravity);
   float accelY = getVerticalAccel(gravityDirection, gravity);

   // Update velocity
   Velocity newV = pDemo->gps.getVelocity();
   newV.addDx(accelX * TPF);
   newV.addDy(accelY * TPF);
   pDemo->gps.setVelocity(newV);

   // Update position
   float newX = pDemo->gps.getPosition().getMetersX() + pDemo->gps.getVelocity().getDx() * TPF;
   float newY = pDemo->gps.getPosition().getMetersY() + pDemo->gps.getVelocity().getDy() * TPF;
   Position newPosition = Position(newX, newY);;

   pDemo->gps.setPosition(newPosition);
   */

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);


   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
   for (int i = 0; i < pDemo->entities.size(); i++)
   {
      pDemo->entities[i]->draw(&gout);
   }

   // draw parts
   //pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
   //gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
   //gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
   //gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
   //pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
   //gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set

   //// draw fragments
   //pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);
   //pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   //pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   //gout.drawFragment(pt, pDemo->angleShip);

   //// draw a single star
   //gout.drawStar(pDemo->ptStar, pDemo->phaseStar);


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
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
