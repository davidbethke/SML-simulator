#pragma once
#include <vector>
#include "SMLInstruction.h"
#include "SMLBaseMem.h"
#include "AllInstructions.h"
class SMLROM:public SMLBaseMem
{
	
public:
	SMLROM(int=50);
	~SMLROM(void);
	//const SMLInstruction& getInstruction(int) const;
	SMLInstruction getInstruction(int) ;
private:
	//const int size;
	void fillRom();
	//std::vector<SMLInstruction> v;
	std::vector<SMLInstruction*> v;
	static const int NUM_INSTRUCT=12;
	
};

