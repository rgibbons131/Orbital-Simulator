#include "entity.h"

/*************************************
 * Entity(Entity& rhs)
 * Copy constructor, taking another Entity
 **************************************/
Entity::Entity(const Entity& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle    = rhs.angle;
   dead     = rhs.dead;
}


Entity& Entity::operator=(const Entity& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
   return *this;
}

/***************************************************************
* Entity::move()
* Moves the entity based on it's current movement variables,
* Velocity and Position. Then updates these variables.
******************************************************************/
void Entity::move(const Interface* pUI)
{
   float height = getHeightAboveEarth(position.getMetersX(), position.getMetersY());
   statusUpdate(pUI);

   // Calculate gravitational acceleration
   float gravity = getGravity(height);
   float gravityDirection = getDirectionOfGravityPull(position.getMetersX(), position.getMetersY());
   vector<float>* accel = getAccel(gravity, gravityDirection);

   float accelX = accel->operator[](0);
   float accelY = accel->operator[](1);
   delete accel;
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
