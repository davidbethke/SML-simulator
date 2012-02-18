#include <string>
#pragma once
class SMLRegister

{
public:
	SMLRegister(std::string="GeneralPurpose",int=0);
	virtual ~SMLRegister(void);
	std::string getName() const;
	int read() const;
	void write(int);
private:
	int value;
	std::string name;
};

