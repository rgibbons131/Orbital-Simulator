#pragma once
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
double Direction::normalize(const double & radian) const {
	double divisor = 2 * M_PI;
	double result = std::fmod(radian, divisor);

	if (result < 0) {
		result += divisor;  // Adjust the result to be positive if it's negative
	}
	return result;
}

double Direction::normalizeDegrees(const double & degrees) const {
	// If it is a negative makes it a positive
	double result = degrees;
	while (result < 0)
	{
		result += 360;
	}
	// If Greater than 2 PI (360 degrees) sets it 
	// within 0, 2 PI
	while (result >= 360)
	{
		result -= 360;
	}

	return result;
}

double Direction::convertToDegrees(const double & radians) const {
	double degrees = normalize(radians) * 360 / TWO_PI;
	return degrees;
}

double Direction::convertToRadians(const double & degrees) const {
	double radians = degrees * TWO_PI / 360;
	return normalize(radians);
}


