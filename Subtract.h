#pragma once
#include "smlinstruction.h"
class RegBank;
class Subtract :
	public SMLInstruction
{
public:
	Subtract(void);
	~Subtract(void);
	virtual void opFunc(int,RegBank&);
};

