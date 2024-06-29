#include "hubble.h"
/*************************************
 * Hubble(Hubble& rhs)
 * Copy constructor, taking another Hubble
 **************************************/
Hubble::Hubble(Hubble& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}