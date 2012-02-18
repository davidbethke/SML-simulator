#include "StdAfx.h"
#include "Store0.h"
#include "RegBank.h"
#include "SMLPage.h"

Store0::Store0(void):SMLInstruction(23)
{
}


Store0::~Store0(void)
{
}
void Store0::opFunc(int loc,SMLPage& page,int val,RegBank& regBank)
{
	int gp0Val=regBank.read(3);
	page.write(loc,gp0Val);
}
