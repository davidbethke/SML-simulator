#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "SMLRegister.h"
class RegisterTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{

	}
	virtual void TearDown()
	{
	}
	SMLRegister reg;

public:
	RegisterTest(void);
	~RegisterTest(void);
};

