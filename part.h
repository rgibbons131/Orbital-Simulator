#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Part :
    public Satellite
{
public:
   Part(void (*drawFunction)(const Position& center, double rotation)) : Satellite() { drawFunc = drawFunction; };
   void (*drawFunc)(const Position& center, double rotation);
   void draw(ogstream* pgout)
   {
      drawFunc(position, angle.getRadians());
   };
};

