#include "StdAfx.h"
#include "RegBankTest.h"
#include <iostream>

using namespace std;
RegBankTest::RegBankTest(void):regBank()
{
}


RegBankTest::~RegBankTest(void)
{
}
TEST_F(RegBankTest, regBankTest1)
{
	std::cout.rdbuf(oss.rdbuf());
	cout << regBank;
	EXPECT_EQ("0",oss.str());
}