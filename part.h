/***********************************************************************
 * Header File:
 *    Fragment : The part class
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    Represents fragments within the simulation.
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiDraw.h"
class Part : public Satellite
{
public:
   Part(void (ogstream::* drawFunction)(const Position& center,double rotation), const double& radius) : Satellite() { drawFunc = drawFunction;};
   void (ogstream::* drawFunc)(const Position& center,double rotation);

   Part(void (ogstream::* drawFunctionOffset)(const Position& center, double rotation, const Position& offset), const double& radius) : Satellite() { drawFuncOffset = drawFunctionOffset; };
   void (ogstream::* drawFuncOffset)(const Position& center, double rotation, const Position& offset);

   void draw(ogstream* pgout)
   {
      if (drawFunc)
      {
         (pgout->*drawFunc)(position, angle.getRadians());
      }
      else if (drawFuncOffset)
      {
         (pgout->*drawFuncOffset)(position, angle.getRadians(), Position());
      }
   };
};

