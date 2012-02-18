#pragma once
#include "DumpMemory.h"
#include "InstructionList.h"
#include "SMLPage.h"
#include "SMLROM.h"
#include "RegBank.h"
#include "SMLInstruction.h"
#include <map>
class Controller
{
	friend void dumpMemory(const SMLPage& page, const RegBank& regBank);
public:
	Controller(void);
	~Controller(void);
	void buildSim();
	void readProg();
	void run();
private:
	
	std::map<std::string,Instruction::OpCodes> enumResolver;
	SMLPage page;
	SMLROM rom;
	RegBank regBank;
	int storeLoc;
	void encodeMap();
	void updateIR(const SMLInstruction&);
	SMLInstruction decode();
	bool storeInstruction(std::string,int);
	int readIC();
	void incIC();
	bool isValidOpCode(int);
	int fetch(int);
	void execute();

};

