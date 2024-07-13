#include "hubble.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity*> Hubble::die()
{
   vector<Entity*> vec;
   double telescopeRad = 10.0;
   double computerRad = 7.0;
   double leftRad = 8.0;
   double rightRad = 8.0;

   HubbleTelescope* center = new HubbleTelescope
   ( 0.0, telescopeRad, position);
   HubbleComputer* computer = new HubbleComputer
   (180.0, computerRad, position);
   HubbleLeft* left = new HubbleLeft
   ( -90.0, leftRad, position);
   HubbleRight* right = new HubbleRight
   ( 90.0, rightRad, position);

   Fragment* hubbleFrag1 = new Fragment(position, velocity, 180, false);
   Fragment* hubbleFrag2 = new Fragment(position, velocity, 0, false);

   vec.push_back(center);
   vec.push_back(computer);
   vec.push_back(left);
   vec.push_back(right);
   vec.push_back(hubbleFrag1);
   vec.push_back(hubbleFrag2);

   dead = true;
   return vec;
}