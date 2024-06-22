/***********************************************************************
 * Source File:
 *    User Interface Direction
 * Author:
 *    Parker, Marisabel, Taemour
 * Summary:
 *    13 hours, most difficult in formatting and which methods to test 
 *	  together, or alone 
 ************************************************************************/
#pragma once
#include "direction.h"
#include <cassert>
#include "unitTest.h"
class TestDirection : public UnitTest
{
public:
	void run()
	{
		testConstructors();
		testConstructorInput();
		testSetupDxAndDy();
		
		testSetAndGetRadians();
		testSetAndGetDegrees();
		
		clickUp();
		clickDown();
		clickLeft();
		clickRight();

		reverseDirection();

		//Tests checking for other circumstances
		testSetAndGetLoopingRadians();
		testSetAndGetLoopingDegrees();
		testSetAndGetNegativeRadians();
		testSetAndGetNegativeDegrees();
		loopByClickLeft();
		loopByClickRight();
		loopByClickUp();
		loopByClickDown();

		report("Direction");
	}

private:
	//Constructors
	void testConstructors() {
		//Setup		
		//Exercise
		Direction dir;
		//Verify
		double radiansUsed = dir.getRadians();
		assertUnit(radiansUsed == 0.0);
		//Teardown
	}

	void testConstructorInput() {
		//Setup		
		//Exercise
		Direction dir(1.5);
		//Verify
		double radiansUsed = dir.getRadians();
		assertUnit(radiansUsed == 1.5);
		//Teardown
	}

	void testSetupDxAndDy() {
		//Setup
		Direction dir;
		//Exercise
		dir.setDxDy(8, 56);
		//Verify
		double myX = dir.getDx();
		double myY = dir.getDy();

		assertUnit(dir.closeEnough(myX, 8, 0.001) == 1);
		assertUnit(dir.closeEnough(myY, 56, 0.001) == 1);
		//Teardown
	}

	void testSetAndGetRadians() {
		//Setup
		Direction dir;
		//Exercise
		dir.setRadians(1);		
		//Verify
		assertUnit(dir.getRadians() == 1);
		//Teardown
	}

	void testSetAndGetDegrees() {
		//Setup
		Direction dir;
		//Exercise
		dir.setDegrees(43);
		//Verify
		assertUnit(dir.getDegrees() == 43);
		//Teardown
	}
	
	//left right +- 0.05
	//up down +- 0.003

	//1 rad  = 57.2958 degrees
	//57.2952

	//Test User clicks
	void clickUp() {
		//Setup
		Direction dir;
		dir.setRadians(1.2);
		//Exercise
		dir.clickUp();
		dir.clickUp();
		//Verify
		double myRadians = dir.getRadians();
		cout << myRadians << "\n";
		assertUnit(dir.closeEnough(myRadians, 1.206, 0.001) == 1);
		//Teardown
	}
	void clickDown() {
		//Setup
		Direction dir;
		dir.setRadians(1.2);
		//Exercise
		dir.clickDown();
		dir.clickDown();
		//Verify
		//assertUnit(dir.getRadians() == 1.194);  
		double myRadians = dir.getRadians();
		assertUnit(dir.closeEnough(myRadians, 1.194, 0.001) == 1);
		//Teardown
	}
	void clickLeft() {
		//Setup
		Direction dir;
		dir.setRadians(1.2);
		//Exercise
		dir.clickLeft();
		dir.clickLeft();
		//Verify
		//assertUnit(dir.getRadians() == 1.21);  //not sure
		// 
		double myRadians = dir.getRadians();
		assertUnit(dir.closeEnough(myRadians, 1.3, 0.001) == 1);
		//Teardown
	}
	void clickRight() {
		//Setup
		Direction dir;
		dir.setRadians(2.0);
		//Exercise
		dir.clickRight();
		dir.clickRight();
		//Verify
		double myRadians = dir.getRadians();
		assertUnit(dir.closeEnough(myRadians, 1.90, 0.001) == 1);
		//Teardown
	}
	void reverseDirection() { //drag for both x,y
		//Setup
		Direction dir;
		dir.setRadians(1);
		//Exercise
		dir.reverseDirection();
		//Verify
		assertUnit(dir.closeEnough(dir.getRadians(), 4.14159, 0.01) == 1);
		//Teardown
	}

	/*****************************************
	* Try error or other conditions
	******************************************/

	void testSetAndGetLoopingRadians() {
		//Setup
		Direction dir;
		//Exercise
		dir.setRadians(7);
		//Verify
		double myRadians = dir.getRadians();
		assertUnit(dir.closeEnough(myRadians, 0.716815, 0.001) == 1);
		//Teardown
	}

	void testSetAndGetLoopingDegrees() {
		//Setup
		Direction dir;
		//Exercise
		dir.setDegrees(400);
		//Verify
		double myDegrees = dir.getDegrees();
		assertUnit(dir.closeEnough(myDegrees, 40, 0.001) == 1);
		//Teardown
	}

	void testSetAndGetNegativeRadians() {
		//Setup
		Direction dir;
		//Exercise
		dir.setRadians(7);
		//Verify
		double myRadians = dir.getRadians();
		assertUnit(dir.closeEnough(myRadians, 0.716815, 0.001) == 1);
		//Teardown
	}

	void testSetAndGetNegativeDegrees() {
		//Setup
		Direction dir;
		//Exercise
		dir.setDegrees(-400);
		//Verify
		double myDegrees = dir.getDegrees();
		assertUnit(dir.closeEnough(myDegrees, 320, 0.001) == 1);
		//Teardown
	}

	void loopByClickLeft() {
		//Setup
		Direction dir;
		dir.setRadians(0);
		//Exercise
		for (int i = 0; i < 126; i++) {
			dir.clickLeft();
		}

		//Verify
		double myRadians = dir.normalize(dir.getRadians());
		assertUnit(dir.closeEnough(myRadians, 0, 0.02) == 1);
		//Teardown
	}

	void loopByClickRight() {
		//Setup
		Direction dir;
		dir.setRadians(0);
		//Exercise
		for (int i = 0; i < 126; i++) {
			dir.clickRight();
		}

		//Verify
		double myRadians = dir.normalize(dir.getRadians());
		assertUnit(dir.closeEnough(myRadians, 6.28 , 0.02) == 1);
		//Teardown
	}
	
	void loopByClickUp() {
		//Setup
		Direction dir;
		dir.setRadians(0);
		//Exercise
		for (int i = 0; i < 2095; i++) {
			dir.clickUp();
		}

		//Verify
		double myRadians = dir.normalize(dir.getRadians());
		assertUnit(dir.closeEnough(myRadians, 0, 0.02) == 1);
		//Teardown
	}

	void loopByClickDown() {
		//Setup
		Direction dir;
		dir.setRadians(0);
		//Exercise
		for (int i = 0; i < 2095; i++) {
			dir.clickDown();
		}

		//Verify
		double myRadians = dir.normalize(dir.getRadians());
		assertUnit(dir.closeEnough(myRadians, 6.28, 0.02) == 1);
		//Teardown
	}
};



