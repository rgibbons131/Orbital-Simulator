#include "hubble.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity> Hubble::die(ogstream* pgout)
{
   vector<Entity> vec;
   double telescopeRad = 10.0;
   double computerRad = 7.0;
   double leftRad = 8.0;
   double rightRad = 8.0;
   void (ogstream:: * drawTelescope)(const Position & center, double rotation, const Position & offset) = &ogstream::drawHubbleTelescope;
   void (ogstream:: * drawComputer)(const Position & center, double rotation, const Position & offset) = &ogstream::drawHubbleComputer;
   void (ogstream:: * drawLeft)(const Position & center, double rotation, const Position & offset) = &ogstream::drawHubbleLeft;
   void (ogstream:: * drawRight)(const Position & center, double rotation, const Position & offset) = &ogstream::drawHubbleRight;

   Part center(drawTelescope, 0.0, telescopeRad);
   Part computer(drawComputer, 180.0, computerRad);
   Part left(drawLeft, -90.0, leftRad);
   Part right(drawRight, 90.0, rightRad);

   Fragment hubbleFrag1(position, velocity, 180, false);
   Fragment hubbleFrag2(position, velocity, 0, false);

   vec.push_back(center);
   vec.push_back(left);
   vec.push_back(right);
   vec.push_back(hubbleFrag1);
   vec.push_back(hubbleFrag2);

   dead = true;
   return vec;
}