#include "StdAfx.h"
#include "Load0.h"
#include "RegBank.h"

Load0::Load0(void):SMLInstruction(22)
{
}


Load0::~Load0(void)
{
}
void Load0::opFunc(int val,RegBank& regBank)
{
	regBank.write(3,val);
}
