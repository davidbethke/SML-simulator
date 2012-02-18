#include "StdAfx.h"
#include "BranchZero.h"
#include "RegBank.h"
#include "SMLPage.h"

BranchZero::BranchZero(void):SMLInstruction(42)
{
}


BranchZero::~BranchZero(void)
{
}
void BranchZero::opFunc(int loc,SMLPage& page,int val,RegBank& regBank)
{
	int accumVal=regBank.read(2);
	if(accumVal)  /// non zero inc normally
		regBank.write(1,regBank.read(1)+1);//inc normally by 1 if 
	else
		regBank.write(1,loc); //Branch

}
