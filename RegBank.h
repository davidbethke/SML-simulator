#pragma once
#include "SMLBaseMem.h"
#include "SMLRegister.h"
#include "SMLInstReg.h"
#include "SMLInstruction.h"
#include <vector>

class RegBank:public SMLBaseMem
{
	friend std::ostream& operator<<(std::ostream&,const RegBank&);
public:
	RegBank(void);
	~RegBank(void);
	int read(int) const;
	void write(int,int);
	void writeIR(const SMLInstruction&);//void RegBank::write(int add, int val)
	SMLInstruction& readIR();
	/*
	v[0]=SMLInstReg();
	v[1]=InstructionCounter();
	v[2]=SMLAccum();
	v[3]=SMLRegister(); // General Purpose
	*/
	
private:
	std::vector<SMLRegister *> v;
	void fillBank();
	static const int NUMREGS=4;
};

