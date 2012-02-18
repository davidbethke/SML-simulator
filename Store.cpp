#include "StdAfx.h"
#include "Store.h"
#include "RegBank.h"
#include "SMLPage.h"
#include "RegBank.h"

Store::Store(void):SMLInstruction(21)
{
}


Store::~Store(void)
{
}
void Store::opFunc(int loc,SMLPage& page,int val, RegBank& regBank)
{
	int accumVal=regBank.read(2);
	page.write(loc,accumVal);
}
