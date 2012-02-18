#pragma once
#include <string>
#include "SMLInstruction.h"

class SMLRegister
{
public:
	SMLRegister(std::string="GeneralPurpose",int=0);
	virtual ~SMLRegister(void);
	std::string getName() const;
	int read() const;
	void write(int);
	virtual void setInstruction(const SMLInstruction&);//TODO place holder for IR
	virtual SMLInstruction& getInstruction();//TODO place holder for IR
private:
	std::string name;
	int value;
};

