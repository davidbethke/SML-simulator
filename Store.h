#pragma once
#include "smlinstruction.h"
//#include "PageInstruction.h"
class RegBank;
class SMLPage;
class Store :
	public SMLInstruction
{
public:
	Store(void);
	~Store(void);
	virtual void opFunc(int,SMLPage&,int,RegBank&);
private:
	
};

