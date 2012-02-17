#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "SMLMem.h"
class MemTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	}
	virtual void TearDown()
	{
	}
	SMLMem mem;
public:
	MemTest(void);
	~MemTest(void);
};

