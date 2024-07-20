#pragma once

#include "position.h"
#include "uiDraw.h"

class StarTest;

class Star {
private:
   Position position;
   unsigned char phase;

public:
   friend StarTest;
   Star() : position(Position(generateRandomDouble(), generateRandomDouble())), phase(generateRandomPhase()) {}

   void twinkle() {phase++;}

   void draw(ogstream* pgout) { pgout->drawStar(position, phase); }
private:
   static double generateRandomDouble()       
   { 
      return (rand() % 2 == 0 ? 1.0 : -1.0) * static_cast<double>(rand()) / RAND_MAX * 60000000.0; 
   }
   static unsigned char generateRandomPhase() { return static_cast<unsigned char>(rand() % 256);        }
};