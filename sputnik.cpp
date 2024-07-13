#include "sputnik.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity*> Sputnik::die()
{
   vector<Entity*> vec;

   Fragment* sputFrag1 = new Fragment(position, velocity, 180.0, false);
   Fragment* sputFrag2 = new Fragment(position, velocity, 0.0, false);
   Fragment* sputFrag3 = new Fragment(position, velocity, 90.0, false);
   Fragment* sputFrag4 = new Fragment(position, velocity, -90.0, false);

   vec.push_back(&sputFrag1);
   vec.push_back(&sputFrag2);
   vec.push_back(&sputFrag3);
   vec.push_back(&sputFrag4);

   dead = true;
   return vec;
}