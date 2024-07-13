#include "dragon.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity*> Dragon::die()
{
   vector<Entity*> vec;
   double centerRad = 6.0;
   double leftRad = 6.0;
   double rightRad = 6.0;
   void (ogstream:: * drawCenter)(const Position & center, double rotation) = &ogstream::drawCrewDragonCenter;
   void (ogstream:: * drawLeft)(const Position & center, double rotation, const Position & offset) = &ogstream::drawCrewDragonLeft;
   void (ogstream:: * drawRight)(const Position & center, double rotation, const Position & offset) = &ogstream::drawCrewDragonRight;
   
   //Part center(0.0, centerRad);
   //Part left(-90.0, leftRad);
   //Part right(90.0, rightRad);

   Fragment dragFrag1(position, velocity, 180, false);
   Fragment dragFrag2(position, velocity, 0, false);

   //vec.push_back(&center);
   //vec.push_back(&left);
   //vec.push_back(&right);
   vec.push_back(&dragFrag1);
   vec.push_back(&dragFrag2);

   return vec;
}