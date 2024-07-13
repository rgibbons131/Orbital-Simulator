/***********************************************************************
 * Header File:
 *    Physics : Physics within the simulation
 * Author:
 *    Taemour, Richard, Aria
 * Summary:
 *    handles and represents physics of entities within the simulation.
 ************************************************************************/
#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
using namespace std;

#ifndef M_PI
   #define M_PI 3.14159265358979323846
#endif

const float FRAME_RATE = 30;
const float TD = 60 * 24;
const float TPF = TD / FRAME_RATE;
const float EARTH_RADIUS = 6378000;
const float GRAVITY = 9.80665;

/***************************************************************
* getEarthRotationSpeed() 
* Returns the speed at which the Earth should rotate
******************************************************************/
 inline float getEarthRotationSpeed() 
{
   return -(2.0 * M_PI / FRAME_RATE) * (TD / 86400.0);
}

 /***************************************************************
* getGravity(float height)
* height - Height above the surface of the earth
* Calculates the acceleration do to gravity at a given height
******************************************************************/
 inline float getGravity(const float& height)
{
   return GRAVITY * (EARTH_RADIUS / (EARTH_RADIUS + height)) * (EARTH_RADIUS / (EARTH_RADIUS + height));
}

 /***************************************************************
* getHeightAboveEarth(float x, float y)
* x - Horizontal position
* y - vertical position
* Calculates the distance above the surface of the earth
******************************************************************/
 inline float getHeightAboveEarth(const float& x,const float& y)
{
   return sqrt((x * x) + (y * y)) - EARTH_RADIUS;
}

 /***************************************************************
* getDirectionOfGravityPull(float x, float y)
* x - Horizontal position
* y - vertical position
* Calculates the direction of the earth from the object
******************************************************************/
 inline float getDirectionOfGravityPull(const float& x,const float& y)
{
   return atan2(-x,-y);
}

 /***************************************************************
* getHorizontalAccel(float angle, float accel)
* angle - the angle of the moving object
* accel - total acceleration
* Calculates the horizontal component of acceleration, or accel
* relative to X. This function can be used to find the horizontal
* component of any angled vector.
******************************************************************/
 inline float getHorizontalAccel(const float& angle,const float& accel)
{
   return accel * sin(angle); // In radians
}

 /***************************************************************
* getVerticalAccel(float angle, float accel)
* angle - the angle of the moving object
* accel - total acceleration
* Calculates the Vertical component of acceleration, or accel
* relative to Y. This function can be used to find the vertical
* component of any angled vector.
******************************************************************/
 inline float getVerticalAccel(const float& angle,const float& accel)
{
   return accel * cos(angle); // In radians
}

 /***************************************************
 * getChangedMagnitude(float so, float v, float t)
 * so - the initial value that will be changed
 * v  - the rate of change
 * t  - time
 * This formula is the same whether changing position 
 * with velocity, or velocity with acceleration
 ****************************************************/

 inline float getChangedMagnitude(const float& so,const float& v,const float& t) // also used for velocity components
{
   return so + v * t;
}

 /***************************************************************
* getDistance(float pos, float velocity, float time, float accel)
* pos      - the initial value that will be changed
* velocity - the speed of the object
* time     - time in seconds
* accel    - total acceleration
* This formula calculates the new position of an object based on
* it's current movement. It is meant to be used from second to
* second
******************************************************************/
 inline float getDistance(const float& pos,const float& velocity,const float& time,const float& accel)
{
   return getChangedMagnitude(pos, velocity, time) + accel * .5 * time * time;
}


