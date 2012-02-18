#pragma once
#include "SMLInstruction.h"
class RegBank;
class Add :
	public SMLInstruction
{
public:
	Add(void);
	~Add(void);
	virtual void opFunc(int,RegBank&);
};

