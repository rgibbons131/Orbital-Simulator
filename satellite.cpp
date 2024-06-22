#include "satellite.h"

/*************************************
 * Satellite(Satellite& rhs)
 * Copy constructor, taking another Satellite
 **************************************/
Satellite::Satellite(Satellite& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}
