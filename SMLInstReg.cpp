#include "StdAfx.h"
#include "SMLInstReg.h"


SMLInstReg::SMLInstReg(void):instruction()
{
}


SMLInstReg::~SMLInstReg(void)
{
}
const SMLInstruction&  SMLInstReg::getInstruction() const
{
	return instruction;
}
