#pragma once
#include "entity.h"
#include "uiDraw.h"
#include "physics.h"
class Earth :
    public Entity
{
public:
   Earth() : Entity() 
   { 
      Position p;
      p.setMeters(0.0, 0.0);
      setPosition(p);
   }
   void move(const Interface* pUI) { setAngle(getEarthRotationSpeed() + angle.getRadians()); };
   void draw(ogstream* pgout)
   {
      pgout->drawEarth(position, angle.getRadians());
   }
   void onHit() {};
};

