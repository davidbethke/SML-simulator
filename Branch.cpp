#include "StdAfx.h"
#include "Branch.h"
#include "RegBank.h"
#include "SMLPage.h"

Branch::Branch(void):SMLInstruction(40)
{
}


Branch::~Branch(void)
{
}
void Branch::opFunc(int loc, SMLPage& page,int val,RegBank& regBank)
{
	regBank.write(1,loc);
}

