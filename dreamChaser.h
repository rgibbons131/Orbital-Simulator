/***********************************************************************
 * Header File:
 *    DreamChaser : The dream chaser class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents the dream chaser entity within the simulation
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class DreamChaser :
    public Satellite
{
public:
   DreamChaser() : Satellite(), thrust(false) {}
   DreamChaser(const Position & pos,const Velocity & vel,const float & a,const bool & dead, const double& radius = 0) :
      Satellite(pos, vel, a, dead, radius), thrust(false) {}
   void move(const Interface* pUI);
   void draw(ogstream* pgout)
   {
      pgout->drawShip(position, angle.getRadians(), thrust);
   }
private:
   bool thrust;
};

