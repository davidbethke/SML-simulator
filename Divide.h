#pragma once
#include "smlinstruction.h"
class RegBank;
class Divide :
	public SMLInstruction
{
public:
	Divide(void);
	~Divide(void);
	virtual void opFunc(int, RegBank&);
};

