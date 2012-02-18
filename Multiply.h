#pragma once
#include "smlinstruction.h"
class RegBank;
class Multiply :
	public SMLInstruction
{
public:
	Multiply(void);
	~Multiply(void);
	virtual void opFunc(int,RegBank&); 
};

