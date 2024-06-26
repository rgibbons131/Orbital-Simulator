#pragma once
#include "physics.h"

class TestEntity;

class Direction
{
protected:
   double radians;
   double degrees = 0;
   double dirDx = 0;
   double dirDy = 0;
	
   double normalizeDegrees(double radian) const;
	double convertToDegrees(double radians) const;
	double convertToRadians(double degrees) const;
	
public:
   friend TestEntity;
   double normalize(double radian) const;
   bool closeEnough(double value, double test, double tolerance) {
	   double difference = value - test;
		return ((difference >= -tolerance) && (difference <= tolerance));
	}

   // Constructors
   Direction() : radians(0.0) {}
   Direction(double rad) : radians(normalize(rad)){}
   // Getters
   double getRadians() const { return radians; }
   double getDegrees() const { return radians * (180.0 / M_PI); }
   double getNormalizedDegrees() const { 
      return normalizeDegrees(radians * (180.0 / M_PI)); }
   double getDx() const { return dirDx; }
   double getDy() const { return dirDy; }
   // Click methods
   void clickUp() { normalize(radians += 0.003); }
   void clickDown() { normalize(radians -= 0.003); }
   void clickLeft() { normalize(radians += 0.05); }
   void clickRight() { normalize(radians -= 0.05); }
   // Reverse direction
   void reverseDirection() {
      radians = normalize(radians + M_PI);
   }
   // Setters
   void setRadians(double rad) { radians = normalize(rad); }
   void setDegrees(double deg) { radians = normalize(deg * (M_PI / 180.0)); }    
   void add(double increment)  { radians = normalize(radians + increment);    }
   void setDxDy(double dx, double dy) {
      radians = atan2(dy, dx);
      this->dirDx = dx;
      this->dirDy = dy;
   }
};

