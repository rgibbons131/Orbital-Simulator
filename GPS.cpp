#include "GPS.h"
/*************************************
 * GPS(GPS& rhs)
 * Copy constructor, taking another GPS
 **************************************/
GPS::GPS(GPS& rhs)
{
   position = rhs.position;
   velocity = rhs.velocity;
   angle = rhs.angle;
   dead = rhs.dead;
}
