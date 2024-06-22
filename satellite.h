#pragma once
#include "entity.h"
class Satellite : public Entity
{
   void onHit() {die();}       // Add fragment logic here later
   void die()   {dead = true;}

};

