#pragma once
#include "SMLInstruction.h"
class RegBank;
class Load :
	public SMLInstruction
{
public:
	Load(void);
	~Load(void);
	virtual void opFunc(int val, RegBank&);
};

