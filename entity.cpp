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
