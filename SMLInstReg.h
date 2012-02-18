#pragma once
#include "smlregister.h"
#include "SMLInstruction.h"
class SMLInstReg :
	public SMLRegister
{
public:
	SMLInstReg(void);
	~SMLInstReg(void);
	//const SMLInstruction&  getInstruction() const;
	virtual void setInstruction(const SMLInstruction&);
	virtual SMLInstruction& getInstruction();
private:
	SMLInstruction instruction;
};

