#include "StdAfx.h"
#include "SMLROM.h"
#include "Read.h"
#include "Write.h"

SMLROM::SMLROM(int s):SMLBaseMem(s),v(s)
{
	fillRom();
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
	Read read;
	Write write;
	v[read.getOp()]=read;
	v[write.getOp()]=write;
}
