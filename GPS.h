#pragma once
#include "satellite.h"
#include "uiDraw.h"


class GPS : public Satellite
{
   void draw(ogstream* pgout) 
   { pgout->drawGPS(position, angle); }
};

