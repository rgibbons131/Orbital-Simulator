#include "starlink.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity> Starlink::die(ogstream* pgout)
{
   vector<Entity> vec;
   double bodyRad = 2.0;
   double arrayRad = 4.0;

   void (ogstream:: * drawBody)(const Position & center, double rotation, const Position & offset) = &ogstream::drawStarlinkBody;
   void (ogstream:: * drawArray)(const Position & center, double rotation, const Position & offset) = &ogstream::drawStarlinkArray;

   Part body(drawBody, -90.0, bodyRad);
   Part link(drawArray, 90.0, arrayRad);

   Fragment linkFrag1(position, velocity, 180, false);
   Fragment linkFrag2(position, velocity, 0, false);

   vec.push_back(body);
   vec.push_back(link);
   vec.push_back(linkFrag1);
   vec.push_back(linkFrag2);

   dead = true;
   return vec;
}