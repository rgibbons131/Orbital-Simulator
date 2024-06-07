#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
using namespace std;

const float FRAME_RATE = 30;
const float TD = 60 * 24;
const float TPF = TD / FRAME_RATE;
const float EARTH_RADIUS = 6378000;
const float GRAVITY = 9.80665;

 float getEarthRotationSpeed() 
{
   return -(2.0 * M_PI / FRAME_RATE) * (TD / 86400.0);
}

float getGravity(float height) 
{
   return GRAVITY * (EARTH_RADIUS / (EARTH_RADIUS / height)) * (EARTH_RADIUS / (EARTH_RADIUS / height));
}

float getHeightAboveEarth(float x, float y)
{
   return sqrt(x * x + y * y) - EARTH_RADIUS;
}

float getDirectionOfGravityPull(float x, float y)
{
   return atan2(-x,-y);
}

float getHorizontalAccel(float angle, float accel)
{
   return accel * sin(angle); // In radians
}

float getVerticalAccel(float angle, float accel)
{
   return accel * cos(angle); // In radians
}

float getChangedMagnitude(float so, float v, float t) // also used for velocity components
{
   return so + v * t;
}

float getDistance(float pos, float velocity, float time, float accel)
{
   return getChangedMagnitude(pos, velocity, time) + accel * .5 * time * time;
}


