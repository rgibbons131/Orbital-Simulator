/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/
#pragma once
#include "test.h"
#include "testPosition.h"
#include "testVelocity.h"
#include "testDirection.h"
#include "testEntity.h"
#include "testDragon.h"
#include "testStarlink.h"
#include "testSputnik.h"
#include "testHubble.h"
#include "testGPS.h"
#include "testFragment.h"
#include "testPart.h"
#include "testStar.h"

 // This code, and the similar IF_DEF in testRunner(), is to ensure that
 // you can see the text output (called the console window) and OpenGL's
 // graphics at the same time. It is not required on Apple's XCode, only
 // on Window's Visual Studio. If you have problems seeing the output window
 // and your team is exclusively on Visual Studio, you can safely remove
 // these two "#ifdef _WIN32" and the "#endif" below it.
#ifdef _WIN32
#include <windows.h>
#include <iostream>
using namespace std;
#endif

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{

#ifdef _WIN32
   AllocConsole();
   FILE* stream;
   errno_t err;
   err = freopen_s(&stream, "CONOUT$", "a", stdout);
#endif // _WIN32
   TestPosition().run();
   TestVelocity().run();
   TestDirection().run();
   TestEntity().run();
   TestDragon().run();
   TestStarlink().run();
   TestSputnik().run();
   TestHubble().run();
   TestGPS().run();
   TestFragment().run();
   TestPart().run();
   TestStar().run();
}
