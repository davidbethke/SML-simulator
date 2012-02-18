#pragma once
#include "smlinstruction.h"
class SMLPage;
class RegBank;
class PageInstruction :
	public SMLInstruction
{
public:
	PageInstruction(int =21); //HACK default to Store instru
	~PageInstruction(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
};

