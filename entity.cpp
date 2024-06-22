#include "entity.h"

Entity::Entity(Entity& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle    = rhs.angle;
   dead     = rhs.dead;
}
