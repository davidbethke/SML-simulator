#pragma once
#include "SMLInstruction.h"
class Read :
	public SMLInstruction
{
public:
	Read(void);
	~Read(void);
	virtual void opFunc();
};

