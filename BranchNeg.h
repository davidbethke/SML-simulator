#pragma once
#include "smlinstruction.h"
class RegBank;
class SMLPage;
class BranchNeg :
	public SMLInstruction
{
public:
	BranchNeg(void);
	~BranchNeg(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
};

