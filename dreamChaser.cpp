#include "dreamChaser.h"

void DreamChaser::move(const Interface* pUI)
{

   if (pUI->isUp())
      thrust = true;
   else thrust = false;
   if (pUI->isLeft())
      angle.add(-.1);
   if (pUI->isRight())
      angle.add(.1);

   float height = getHeightAboveEarth(position.getMetersX(), position.getMetersY());

   // Update thrust accel
   float thrustAccelx = 0.0;
   float thrustAccely = 0.0;
   if (thrust)
   {
      thrustAccelx = getHorizontalAccel(angle.getRadians(), 2);
      thrustAccely = getVerticalAccel(angle.getRadians(), 2);
   }
   // Calculate gravitational acceleration
   float gravity = getGravity(height);
   float gravityDirection = getDirectionOfGravityPull(position.getMetersX(), position.getMetersY());
   float accelX = getHorizontalAccel(gravityDirection, gravity);
   float accelY = getVerticalAccel(gravityDirection, gravity);
   accelX += thrustAccelx;
   accelY += thrustAccely;

   velocity.addDx(accelX * TPF / 2);
   velocity.addDy(accelY * TPF / 2);

   // Update position
   float newX = getDistance(position.getMetersX(), velocity.getDx(), TPF, accelX);
   float newY = getDistance(position.getMetersY(), velocity.getDy(), TPF, accelY);
   Position newPosition = Position(newX, newY);
   this->setPosition(newPosition);

   // Update velocity
   velocity.addDx(accelX * TPF / 2);
   velocity.addDy(accelY * TPF / 2);
}
