#include "dragon.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity> Dragon::die(ogstream* pgout)
{
   vector<Entity> vec;
   double centerRad = 6.0;
   void (ogstream:: *drawFunc)(const Position & center, double rotation) = &ogstream::drawCrewDragonCenter;

   Part center(drawFunc, centerRad);


   vec.push_back(center);
   return vec;
}