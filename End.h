#pragma once
#include "smlinstruction.h"
class RegBank;
class End :
	public SMLInstruction
{
public:
	End(void);
	~End(void);
	virtual void opFunc(int,RegBank&);
};

