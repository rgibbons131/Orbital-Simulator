#include "GPS.h"

GPS::GPS(GPS& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}
