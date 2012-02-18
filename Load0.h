#pragma once
#include "smlinstruction.h"
class RegBank;
class Load0 :
	public SMLInstruction
{
public:
	Load0(void);
	~Load0(void);
	virtual void opFunc(int,RegBank&);
};

