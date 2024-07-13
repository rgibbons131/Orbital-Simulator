#include "dragon.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity> Dragon::die(ogstream* pgout)
{
   vector<Entity> vec;
   double centerRad = 6.0;
   double leftRad = 6.0;
   double rightRad = 6.0;
   void (ogstream:: * drawCenter)(const Position & center, double rotation) = &ogstream::drawCrewDragonCenter;
   void (ogstream:: * drawLeft)(const Position & center, double rotation, const Position & offset) = &ogstream::drawCrewDragonLeft;
   void (ogstream:: * drawRight)(const Position & center, double rotation, const Position & offset) = &ogstream::drawCrewDragonRight;
   
   Part center(drawCenter, centerRad);
   Part left(drawLeft, leftRad);
   Part right(drawRight, rightRad);

   vec.push_back(center);
   vec.push_back(left);
   vec.push_back(right);
   return vec;
}