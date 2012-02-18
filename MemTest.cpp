#include "StdAfx.h"
#include "MemTest.h"
#include <iostream>

using namespace std;
MemTest::MemTest(void):mem()
{
}


MemTest::~MemTest(void)
{
}
TEST_F(MemTest, memTest1)
{
	std::cout.rdbuf(oss.rdbuf());
	EXPECT_EQ(100,mem.getSize())<< "Size failed for Mem";
	EXPECT_EQ(0,mem.read(0))<< "Read default val 0 FAIL";
	
	EXPECT_EQ(0,mem.read(99))<<"Read defalult val 99 FAIL";
	mem.write(0,99);
	EXPECT_EQ(99,mem.read(0))<< "Write 99 at 0 Fail";
	mem.write(99,99);
	EXPECT_EQ(99,mem.read(99))<<"Write 99 at 99 FAIL";
	cout << mem;
	EXPECT_EQ("0 ",oss.str());
	
}
