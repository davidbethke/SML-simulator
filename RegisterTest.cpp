#include "StdAfx.h"
#include "RegisterTest.h"


RegisterTest::RegisterTest(void):reg()
{
}


RegisterTest::~RegisterTest(void)
{
}
TEST_F(RegisterTest,regTest1)
{
	EXPECT_EQ(0,reg.read())<<"Register failed to init to 0";
	reg.write(1);
	EXPECT_EQ(1,reg.read())<<"Register failed to write 1";
	reg.write(0);
	EXPECT_EQ(0,reg.read())<<"Register failed to write 0";
}

