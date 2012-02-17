#pragma once
#include "smlinstruction.h"
class Divide :
	public SMLInstruction
{
public:
	Divide(void);
	~Divide(void);
	virtual void opFunc();
};

