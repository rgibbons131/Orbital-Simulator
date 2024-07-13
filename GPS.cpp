#include "GPS.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity> GPS::die(ogstream* pgout)
{
   vector<Entity> vec;
   double centerRad = 7.0;
   double leftRad = 8.0;
   double rightRad = 8.0;
   void (ogstream:: * drawCenter)(const Position & center, double rotation) = &ogstream::drawGPSCenter;
   void (ogstream:: * drawLeft)(const Position & center, double rotation, const Position & offset) = &ogstream::drawGPSLeft;
   void (ogstream:: * drawRight)(const Position & center, double rotation, const Position & offset) = &ogstream::drawGPSRight;

   Part center(drawCenter, 0.0, centerRad);
   Part left(drawLeft, -90.0, leftRad);
   Part right(drawRight,90.0, rightRad);

   Fragment GPSFrag1(position, velocity, 180, false);
   Fragment GPSFrag2(position, velocity, 0, false);

   vec.push_back(center);
   vec.push_back(left);
   vec.push_back(right);
   vec.push_back(GPSFrag1);
   vec.push_back(GPSFrag2);

   dead = true;
   return vec;
}