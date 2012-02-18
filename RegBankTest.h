#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "RegBank.h"
class RegBankTest :
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
	RegBank regBank;
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf;
public:
	RegBankTest(void);
	~RegBankTest(void);
};

