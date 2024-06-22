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
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "test.h"
#include "physics.h"
#include "entity.h"
#include "GPS.h"
#include "satellite.h"
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
      ptGPS.setMetersX(0.0);
      ptGPS.setMetersY(42164000.0);

      angleShip = 0.0;
      angleGPS = 0.0;
      angleEarth = 0.0;
      //phaseStar = 0;


      // Initial velocity
      velocityX = -3100.0;
      velocityY = 0.0;
      Velocity initialGPSv = Velocity(-3100.0, 0.0);
      gps.setAngle(angleGPS);
      gps.setPosition(ptGPS);
      gps.setVelocity(initialGPSv);
   }
   float velocityX;
   float velocityY;
   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   GPS gps;

   unsigned char phaseStar;

   double angleShip;
   double angleEarth;
   double angleGPS;
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

   // Move the GPS
   // Starting velocity (x and y) = -3100.0 , 0.0
   // Need to track and increment velocity, position, and accelertation

   // Calculate height above Earth
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

   //
   // draw everything
   //

   Position pt;
   ogstream gout(pt);


   // draw the earth
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
   // draw satellites
   //gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
   //gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
   //gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
   //gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
   //gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   //gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
   pDemo->gps.draw(&gout);

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
