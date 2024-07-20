#include "dreamChaser.h"

void DreamChaser::statusUpdate(const Interface* pUI)
{
   if (pUI->isUp())
      thrust = true;
   else thrust = false;
   if (pUI->isLeft())
      angle.add(-.1);
   if (pUI->isRight())
      angle.add(.1);
   if (pUI->isSpace())
      shooting = true;
}

vector<float>* DreamChaser::getAccel(float gravity, float gravityDirection)
{
   float thrustAccelx = 0.0;
   float thrustAccely = 0.0;
   if (thrust)
   {
      thrustAccelx = getHorizontalAccel(angle.getRadians(), 2);
      thrustAccely = getVerticalAccel(angle.getRadians(), 2);
   }
   float accelX = getHorizontalAccel(gravityDirection, gravity);
   float accelY = getVerticalAccel(gravityDirection, gravity);
   accelX += thrustAccelx;
   accelY += thrustAccely;
   vector<float>* acel = new vector<float>{ accelX, accelY };
   return acel;
}