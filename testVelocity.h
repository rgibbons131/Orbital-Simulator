//
//  test_velocity.hpp
//  Tests
//
//  Created by Marisabel Trejo  on 3/15/24.
//
#include <stdio.h>

#ifndef test_velocity_hpp
#define test_velocity_hpp
#include "direction.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include "velocity.h"
#include "unitTest.h"
using namespace std;

#endif /* test_velocity_hpp */

/******************

 Test the Velocity class
 *********************/
class TestVelocity : public UnitTest 
{
public:
    void run() 
    {
        // run tests
        testSetupDxAndDy();
        TestSetDx();
        TestSetDy();
        testSetSpeed();
        testAddDx();
        testAddDy();
        testAddZeroDx();
        testAddZeroDy();
        testNegativeDx();
        testNegativeDy();
        testNormalize();

        report("Velocity");

    };

private:
    // Test the default constructor
    void testDefaultConstructor() {
        // Set
        Velocity v;

        // Exercise & Verify
        assertUnit(v.getDx() == 0.0);
        assertUnit(v.getDy() == 0.0);

        // Teardown
    }


    void testSetupDxAndDy() {
        //Setup
        Velocity v;

        //Exercise
        v.setDxDy(8, 7);

        //Verify
        assertUnit(v.getDx() == 8);
        assertUnit(v.getDy() == 7);
    };

    void TestSetDx() {
        //Set up
        Velocity v;

        // Exercise
        v.setDx(5.0);

        // Verifiy
        assertUnit(v.getDx() == 5.0);

        // Teardown
    };
    void TestSetDy() {
        //Set up
        Velocity v;

        // Exercise
        v.setDy(6.0);

        // Verifiy
        assertUnit(v.getDy() == 6.0);

        // Teardown
    };


    void testSetSpeed() {
        //Set up
        Velocity v(3.0, 4.0);

        // Exercise
        double speed = v.getSpeed();

        // Verifiy
        assertUnit(5.001 >= speed && speed >= 4.9999);

        // Teardown
    };

    void testAddDx() {
        //Set up
        Velocity v;

        // Exercise
        v.setDx(3.0);
        v.addDx(2.0);

        // Verifiy
        assertUnit(v.getDx() == 5.0);
        // Teardown

    };

    void testAddDy() {
        //Set up
        Velocity v;

        // Exercise
        v.setDy(4.0);
        v.addDy(2.0);

        // Verifiy
        assertUnit(v.getDy() == 6.0);

        // Teardown

    };


    void testAddZeroDx() {
        //Set
        Velocity v;

        //Exercise
        v.setDx(3.0);
        v.addDx(0.0);

        //Verify
        assertUnit(v.getDx() == 3.0);

    };

    void testAddZeroDy() {
        //Set
        Velocity v;

        //Exercise
        v.setDy(3.0);
        v.addDy(0.0);

        //Verify
        assertUnit(v.getDy() == 3.0);

    };

    void testAddNegativeDx() {
        //Set
        Velocity v;

        //Exercise
        v.setDx(15.0);
        v.addDx(-5.0);

        //Verify
        assertUnit(v.getDx() == 10.0);

    };
    void testAddNegativeDy() {

        //Set
        Velocity v;

        //Exercise
        v.setDy(30.0);
        v.addDy(-10.0);

        //Verify
        assertUnit(v.getDy() == 20.0);

    };
    void testNegativeDx() {
        //Set
        Velocity v;

        //Exercise
        v.setDx(-50.0);

        //Verify
        assertUnit(v.getDx() == -50.0);

        //Teardown
    };

    void testNegativeDy() {
        //Set
        Velocity v;

        //Exercise
        v.setDy(-10.0);

        // Verify
        assertUnit(v.getDy() == -10.00);
    };

    void testNormalize() {
        // Setup
        Direction d;
        // Test case 1: Positive angle within 0 to 2*PI
        // Excercise
        double result1 = d.normalize(1.5);
        // Verify
        assertUnit(result1 == 1.5);

        // Teardown

    }
};