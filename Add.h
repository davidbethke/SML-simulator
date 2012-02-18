#pragma once
#include "smlinstruction.h"
class RegBank;
class Add :
	public SMLInstruction
{
public:
	Add(void);
	~Add(void);
	virtual void opFunc(int,const RegBank&);
};

