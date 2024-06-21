
#define TWO_PI 6.28318530718

#include <math.h>    
#include <iostream>  
#include "direction.h"
using namespace std;

class Direction;

/*************************************************************************
 * QUAD
 * 
 *************************************************************************/
double Direction::normalize(double radian) const {
	// If it is a negative makes it a positive
	while (radian < 0)
	{
		radian += TWO_PI;
	}
	// If Greater than 2 PI (360 degrees) sets it 
	// within 0, 2 PI
	while (radian >= TWO_PI) 
	{
		radian -= TWO_PI;
	}

	return radian;
};

double Direction::normalizeDegrees(double degrees) const {
	// If it is a negative makes it a positive
	while (degrees < 0)
	{
		degrees += 360;
	}
	// If Greater than 2 PI (360 degrees) sets it 
	// within 0, 2 PI
	while (degrees >= 360)
	{
		degrees -= 360;
	}

	return degrees;
};

double Direction::convertToDegrees(double radians) const {
	double degrees = normalize(radians) * 360 / TWO_PI;
	return degrees;
};

double Direction::convertToRadians(double degrees) const {
	double radians = degrees * TWO_PI / 360;
	return normalize(radians);
};


