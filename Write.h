#pragma once
#include "SMLInstruction.h"
class RegBank;
class SMLPage;
class Write :
	public SMLInstruction
{
public:
	Write(void);
	~Write(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
};

