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

 inline float getEarthRotationSpeed() 
{
   return -(2.0 * M_PI / FRAME_RATE) * (TD / 86400.0);
}

 inline float getGravity(float height)
{
   return GRAVITY * pow(EARTH_RADIUS / (EARTH_RADIUS + height),2);
}

 inline float getHeightAboveEarth(float x, float y)
{
   return sqrt(pow(x,2) + pow(y,2)) - EARTH_RADIUS;
}

 inline float getDirectionOfGravityPull(float x, float y)
{
   return atan2(-x,-y);
}

 inline float getHorizontalAccel(float angle, float accel)
{
   return accel * sin(angle); // In radians
}

 inline float getVerticalAccel(float angle, float accel)
{
   return accel * cos(angle); // In radians
}

 inline float getChangedMagnitude(float so, float v, float t) // also used for velocity components
{
   return so + v * t;
}

 inline float getDistance(float pos, float velocity, float time, float accel)
{
   return getChangedMagnitude(pos, velocity, time) + accel * .5 * time * time;
}


