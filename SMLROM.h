#pragma once
#include <vector>
#include "SMLInstruction.h"
#include "SMLBaseMem.h"
class SMLROM:public SMLBaseMem
{
	
public:
	SMLROM(int=50);
	~SMLROM(void);
	const SMLInstruction& getInstruction(int) const;
private:
	//const int size;
	void fillRom();
	std::vector<SMLInstruction> v;
	
};

