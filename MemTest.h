#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "SMLPage.h"
class MemTest :
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
	SMLPage mem;
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf;
public:
	MemTest(void);
	~MemTest(void);
};

