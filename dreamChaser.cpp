#include "dreamChaser.h"

void DreamChaser::move()
{
   float height = getHeightAboveEarth(position.getMetersX(), position.getMetersY());

   // Calculate gravitational acceleration
   float gravity = getGravity(height);
   float gravityDirection = getDirectionOfGravityPull(position.getMetersX(), position.getMetersY());
   float accelX = getHorizontalAccel(gravityDirection, gravity);
   float accelY = getVerticalAccel(gravityDirection, gravity);

   // Update velocity
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
