#include "StdAfx.h"
#include "SMLInstReg.h"


SMLInstReg::SMLInstReg(void):SMLRegister("Instruction Register"),instruction()
{
}


SMLInstReg::~SMLInstReg(void)
{
}
/*
const SMLInstruction&  SMLInstReg::getInstruction() const
{
	return instruction;
}
*/
void SMLInstReg::setInstruction(const SMLInstruction& i)
{
	instruction=i;
}
SMLInstruction SMLInstReg::getInstruction()
{
	return instruction;
}
