#include "sputnik.h"
/*************************************
 * Sputnik(Sputnik& rhs)
 * Copy constructor, taking another Sputnik
 **************************************/
Sputnik::Sputnik(Sputnik& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}