#pragma once
#include "smlinstruction.h"
class RegBank;
class SMLPage;
class BranchZero :
	public SMLInstruction
{
public:
	BranchZero(void);
	~BranchZero(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
};

