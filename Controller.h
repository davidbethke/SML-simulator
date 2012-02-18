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
	//void buildSim();
	void readProg();
	void initProg();
	void run();
private:
	
	std::map<std::string,Instruction::OpCodes> enumResolver;
	SMLPage page;
	SMLROM rom;
	RegBank regBank;
	int storeLoc;
	void encodeMap();
	SMLInstruction decode();
	void updateIR(const SMLInstruction&);
	void execute();
	void incIC();
	
	bool storeInstruction(std::string,int);
	int readIC();
	bool isValidOpCode(int);
	int fetch(int);
	bool storeData(int, int);
	

};

