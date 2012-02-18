#include "StdAfx.h"
#include "BranchNeg.h"
#include "RegBank.h"
#include "SMLPage.h"

BranchNeg::BranchNeg(void):SMLInstruction(41)
{
}


BranchNeg::~BranchNeg(void)
{
}
void BranchNeg::opFunc(int loc,SMLPage& page,int val,RegBank& regBank)
{
	int accumVal=regBank.read(2);
	if(accumVal>0)
		regBank.write(1,regBank.read(1)+1);//inc normally by 1 if 
	else
		regBank.write(1,loc); //Branch

}

