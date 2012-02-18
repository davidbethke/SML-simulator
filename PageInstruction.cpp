#include "StdAfx.h"
#include "PageInstruction.h"
#include "SMLPage.h"
#include "RegBank.h"


PageInstruction::PageInstruction(int n):SMLInstruction(n)
{
}


PageInstruction::~PageInstruction(void)
{
}
void PageInstruction::opFunc(int l,SMLPage& p, int v, RegBank& rb)
{
	// do nothing
}
