#include "StdAfx.h"
#include "SMLROM.h"


SMLROM::SMLROM(int s):SMLBaseMem(s),v(s)
{
}


SMLROM::~SMLROM(void)
{
}
const SMLInstruction & SMLROM::getInstruction(int add) const
{
	if(isValidAddress(add))
		return v[add];
	else
	{
		accessError(add);
		exit(1);
	}
}
void SMLROM::fillRom()
{

}
