#pragma once
#include "smlinstruction.h"
class RegBank;
class SMLPage;
class Store0 :
	public SMLInstruction
{
public:
	Store0(void);
	~Store0(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
};

