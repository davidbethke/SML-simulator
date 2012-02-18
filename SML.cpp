// SML.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Controller.h"

#include "gtest/gtest.h"
using namespace std;
TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv) 
{ 
	testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	std::getchar(); // keep console window open until Return keystroke
	Controller myControl;
	myControl.readProg();
	std::getchar();
	myControl.initProg();
	std::getchar();
	cout << "Press To Run"<<endl;
	myControl.run();
	std::getchar(); 
}