#include "starlink.h"
/*************************************
 * Starlink(Starlink& rhs)
 * Copy constructor, taking another Starlink
 **************************************/
Starlink::Starlink(Starlink& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}