#include "StdAfx.h"
#include "Load.h"
#include "RegBank.h"

Load::Load(void):SMLInstruction(20)
{
}


Load::~Load(void)
{
}
void Load::opFunc(int val, RegBank& regBank)
{
			regBank.write(2,val); //DONE to check functionality
}

