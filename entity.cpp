#include "entity.h"

/*************************************
 * Entity(Entity& rhs)
 * Copy constructor, taking another Entity
 **************************************/
Entity::Entity(Entity& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle    = rhs.angle;
   dead     = rhs.dead;
}


/***************************************************************
* Entity::move()
* Moves the entity based on it's current movement variables,
* Velocity and Position. Then updates these variables.
******************************************************************/
void Entity::move()
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
