#include "starlink.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity*> Starlink::die()
{
   vector<Entity*> vec;
   double bodyRad = 2.0;
   double arrayRad = 4.0;


   StarLinkBody* body = new StarLinkBody
   ( -90.0, bodyRad, position);
   StarLinkArray* link = new StarLinkArray
   ( 90.0, arrayRad, position);

   Fragment* linkFrag1 = new Fragment
   (position, velocity, 180, false);
   Fragment* linkFrag2 = new Fragment
(position, velocity, 0, false);

   vec.push_back(body);
   vec.push_back(link);
   vec.push_back(linkFrag1);
   vec.push_back(linkFrag2);

   dead = true;
   return vec;
}