#pragma once
#include "smlinstruction.h"
class RegBank;
class SMLPage;
class Branch :
	public SMLInstruction
{
public:
	Branch(void);
	~Branch(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
};

