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
   
   DragonCenter* center = new DragonCenter
   (0.0, centerRad, position);
   DragonLeft* left = new DragonLeft
   (-90.0, leftRad, position);
   DragonRight* right = new DragonRight
   (90.0, rightRad, position);

   Fragment* dragFrag1 = new Fragment
   (position, velocity, 180, false);
   Fragment* dragFrag2 = new Fragment
   (position, velocity, 0, false);

   vec.push_back(center);
   vec.push_back(left);
   vec.push_back(right);
   vec.push_back(dragFrag1);
   vec.push_back(dragFrag2);

   return vec;
}