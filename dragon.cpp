#include "dragon.h"
/*************************************
 * Dragon(Dragon& rhs)
 * Copy constructor, taking another Dragon
 **************************************/
Dragon::Dragon(Dragon& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}