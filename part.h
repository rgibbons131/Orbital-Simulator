/***********************************************************************
 * Header File:
 *    Fragment : The part class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents fragments within the simulation.
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Part : public Satellite
{
public:
   Part( const double& a, const double& radius, const Position& pos) : Satellite()
   { 
      this->setPosition(pos);
      this->position.addPixelsX(getHorizontalAccel(a, 4));
      this->position.addPixelsY(getVerticalAccel(a, 4));
      double kick = random(5000, 9000);
      this->velocity.addDx(getHorizontalAccel(a, kick));
      this->velocity.addDy(getVerticalAccel(a, kick));
   };
};

class GPSRight : public Part
{
public:
   GPSRight(const double& a, const double& radius, const Position& pos) : Part(a, radius, pos){}
   void draw(ogstream* gout)
   {
      gout->drawGPSRight(position, angle.getRadians());
   }

};

class GPSLeft : public Part
{
public:
   GPSLeft(const double& a, const double& radius, const Position& pos) : Part(a, radius, pos) {}
   void draw(ogstream* gout)
   {
      gout->drawGPSLeft(position, angle.getRadians());
   }
};
 
class GPSCenter : public Part
{
public:
   GPSCenter(const double& a, const double& radius, const Position& pos) : Part(a, radius, pos) {}
   void draw(ogstream* gout)
   {
      gout->drawGPSCenter(position, angle.getRadians());
   }
};