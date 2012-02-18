#pragma once
#include "DumpMemory.h"
#include "InstructionList.h"
#include "SMLPage.h"
#include <map>
class Controller
{
	friend void dumpMemory(const SMLPage& page, const RegBank& regBank);
public:
	Controller(void);
	~Controller(void);
	void buildSim();
	void readProg();
	bool storeInstruction(std::string,int);
	void run();
private:
	
	std::map<std::string,Instruction::OpCodes> enumResolver;
	SMLPage page;
	int storeLoc;
	void encodeMap();
};

