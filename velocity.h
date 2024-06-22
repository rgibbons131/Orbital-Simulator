//
//  onevelocity.hpp
//  Tests
//
//  Created by Marisabel Trejo  on 3/15/24.
//

#ifndef onevelocity_hpp
#define onevelocity_hpp

#include <stdio.h>

#endif /* onevelocity_hpp */

class testEntity;

 /***********************************************************
  * VELOCITY
  * The velocity class
  ***********************************************************/

#include <cmath> // Include <cmath> for mathematical operations

class Velocity 
{

private:

    // velocity component in the x-direction
    double dx;
    // velocity component in the y-direction
    double dy;

    // method to calculate velocity from graph data
    double calcFromGraph() {
        // calculate velocity based on graph coordinates (dx, dy)
            // claceholder return value:
        return dx + dy;
    }

    // method for linear interpolation
    double linearInterpolation(double x1, double y1, double x2, double y2, double x) {
        // perform linear interpolation based on two data points
        // laceholder return value:
        return y1 + ((y2 - y1) / (x2 - x1)) * (x - x1);
    }
public:

   friend testEntity;
    // Constructors
    Velocity() : dx(0.0), dy(0.0) {}
    Velocity(double dx_, double dy_) : dx(dx_), dy(dy_) {}

    // Setter methods
    void setDxDy(double newDx, double newDy) {
        dx = newDx;
        dy = newDy;
    }

    void setDx(double newDx) {
        dx = newDx;
    }

    void setDy(double newDy) {
        dy = newDy;
    }

    void setDirection(double radians) {
        double magnitude = sqrt(dx * dx + dy * dy);
        dx = magnitude * cos(radians);
        dy = magnitude * sin(radians);
    }

    void setSpeed(double speed) {
        double currentSpeed = sqrt(dx * dx + dy * dy);
        if (currentSpeed > 0.0) {
            double scaleFactor = speed / currentSpeed;
            dx *= scaleFactor;
            dy *= scaleFactor;
        }
    }

    // Getter methods
    double getDx() const {
        return dx;
    }

    double getDy() const {
        return dy;
    }

    double getDirection() const {
        return atan2(dy, dx); // Return direction in radians
    }
    double getSpeed() const {
        return hypot(dx, dy);
    }

    // Methods to modify velocity
    void addVelocity(const Velocity& v) {
        dx += v.dx;
        dy += v.dy;
    }

    void addDx(double deltaDx) {
        dx += deltaDx;
    }

    void addDy(double deltaDy) {
        dy += deltaDy;
    }

    void reverseVelocity() {
        dx = -dx;
        dy = -dy;
    }
};