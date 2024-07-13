#include "GPS.h"
#include "part.h"
#include "fragment.h"
#include "uiDraw.h"

vector<Entity*> GPS::die()
{
   vector<Entity*> vec;
   double centerRad = 7.0;
   double leftRad = 8.0;
   double rightRad = 8.0;

   GPSCenter* center = new GPSCenter( 0.0, centerRad, position);
   GPSLeft* left = new GPSLeft( -90.0, leftRad, position);
   GPSRight* right= new GPSRight(90.0, rightRad, position);

   Fragment* GPSFrag1 = new Fragment(position, velocity, 180, false);
   Fragment* GPSFrag2 = new Fragment(position, velocity, 45, false);

   vec.push_back(center);
   vec.push_back(left);
   vec.push_back(right);
   vec.push_back(GPSFrag1);
   vec.push_back(GPSFrag2);

   dead = true;
   return vec;
}