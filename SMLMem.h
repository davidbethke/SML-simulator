#pragma once
#include <vector>
#include "SMLRegister.h"
#include "SMLBaseMem.h"


class SMLMem:public SMLBaseMem
{
public:
	SMLMem(int=100);
	~SMLMem(void);
	int  read(int);
	void write(int,int);
	//int  getSize() const;
private:
	//const int size;
	std::vector<SMLRegister> v;
	//bool isValidAddress(int);
	//bool isValidData(int);
	
};

