#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "SMLROM.h"
#include <iostream>
#include <sstream>
class ROMTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		p_cout_streambuf = std::cout.rdbuf();
	}
	virtual void TearDown()
	{
		std::cout.rdbuf(p_cout_streambuf); // restore
	}

public:
	ROMTest(void);
	~ROMTest(void);
	SMLROM rom;
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf;
};

