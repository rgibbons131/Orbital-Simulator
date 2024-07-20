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
#include "bullet.h"
class DreamChaser :
    public Satellite
{
public:
   DreamChaser() : Satellite(), thrust(false) { this->radius = 10; }
   DreamChaser(const Position & pos,const Velocity & vel,const float & a,const bool & dead, const double& radius = 10) :
      Satellite(pos, vel, a, dead, radius), thrust(false) {}
   //void move(const Interface* pUI);
   void draw(ogstream* pgout)
   {
      pgout->drawShip(position, angle.getRadians(), thrust);
   }
   bool isShooting()
   {
      bool temp = shooting;
      shooting = false;
      return temp;
   }
   Bullet* shoot()
   {
      Position p(position.getMetersX(), position.getMetersY());
      Velocity v(velocity);
      p.addPixelsX(getHorizontalAccel(angle.getRadians(), 19));
      p.addPixelsY(getVerticalAccel(angle.getRadians(), 19));
      v.addDx(getHorizontalAccel(angle.getRadians(),9000));
      v.addDy(getVerticalAccel(angle.getRadians(),9000));

      Bullet* bullet = new Bullet(p,v,angle.getRadians(),false);
      return bullet;
   }

protected:
   virtual void statusUpdate(const Interface* pUI);
   virtual vector<float>* getAccel(float gravity, float gravityDirection);

private:
   bool thrust;
   bool shooting;
};

