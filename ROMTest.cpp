#include "StdAfx.h"
#include "ROMTest.h"
#include "SMLInstruction.h"


ROMTest::ROMTest(void):rom()
{
}


ROMTest::~ROMTest(void)
{
}
TEST_F(ROMTest,DISABLED_romTest1)
{
	/*
	std::cout.rdbuf(oss.rdbuf());
	SMLInstruction  myInstruct;
	SMLInstruction myInstruct11;
	SMLInstruction myInstruct32;
	EXPECT_EQ(50,rom.getSize());
	myInstruct=rom.getInstruction(10);
	myInstruct11=rom.getInstruction(11);
	myInstruct32=rom.getInstruction(32);
	EXPECT_EQ(10,myInstruct.getOp())<<"Fail getOp";
	EXPECT_EQ(10,myInstruct.getLoc())<<"Fail getLoc";
	EXPECT_EQ(99,myInstruct.getData())<<"Fail getData";
	EXPECT_EQ(0,myInstruct.getDir())<<"Fail getDir";
	//op11
	EXPECT_EQ(11,myInstruct11.getOp())<<"Fail getOp :op11";
	EXPECT_EQ(11,myInstruct11.getLoc())<<"Fail getLoc  :op11";
	EXPECT_EQ(88,myInstruct11.getData())<<"Fail getData :op11";
	EXPECT_EQ(0,myInstruct11.getDir())<<"Fail getDir :op11";
	//op32
	EXPECT_EQ(32,myInstruct32.getOp())<<"Fail getOp :op32";
	EXPECT_EQ(10,myInstruct32.getLoc())<<"Fail getLoc  :op32";
	EXPECT_EQ(0,myInstruct32.getData())<<"Fail getData :op32";
	EXPECT_EQ(0,myInstruct32.getDir())<<"Fail getDir :op32";
	/*
	myInstruct.opFunc();
	EXPECT_EQ("Im a Read",oss.str())<<"Fail opFunc";
	oss.str("");
	myInstruct11.opFunc();
	EXPECT_EQ("Im a Write",oss.str())<<"Fail opFunc :op11";
	oss.str("");
	myInstruct32.opFunc();
	EXPECT_EQ("Im a Write",oss.str())<<"Fail opFunc :op32";
	*/
}
TEST_F(ROMTest,romTest2)
{
	/*
	std::cout.rdbuf(oss.rdbuf());
	SMLInstruction * myInstruct;
	SMLInstruction * myInstruct11;
	SMLInstruction * myInstruct32;
	EXPECT_EQ(50,rom.getSize());
	myInstruct=rom.getInstruction(10);
	myInstruct11=rom.getInstruction(11);
	myInstruct32=rom.getInstruction(32);
	EXPECT_EQ(10,myInstruct->getOp())<<"Fail getOp";
	EXPECT_EQ(10,myInstruct->getLoc())<<"Fail getLoc";
	EXPECT_EQ(99,myInstruct->getData())<<"Fail getData";
	EXPECT_EQ(0,myInstruct->getDir())<<"Fail getDir";
	//op11
	EXPECT_EQ(11,myInstruct11->getOp())<<"Fail getOp :op11";
	EXPECT_EQ(11,myInstruct11->getLoc())<<"Fail getLoc  :op11";
	EXPECT_EQ(88,myInstruct11->getData())<<"Fail getData :op11";
	EXPECT_EQ(0,myInstruct11->getDir())<<"Fail getDir :op11";
	//op32
	EXPECT_EQ(32,myInstruct32->getOp())<<"Fail getOp :op32";
	EXPECT_EQ(0,myInstruct32->getLoc())<<"Fail getLoc  :op32";
	EXPECT_EQ(0,myInstruct32->getData())<<"Fail getData :op32";
	EXPECT_EQ(0,myInstruct32->getDir())<<"Fail getDir :op32";
	//TODO Need real opFunc Tests
	/*
	myInstruct->opFunc(0);
	EXPECT_EQ("Im a Read",oss.str())<<"Fail opFunc";
	oss.str("");
	myInstruct11->opFunc(0);
	EXPECT_EQ("Im a Write",oss.str())<<"Fail opFunc :op11";
	oss.str("");
	myInstruct32->opFunc(0);
	EXPECT_EQ("Im a Divide",oss.str())<<"Fail opFunc :op32";
	*/
}