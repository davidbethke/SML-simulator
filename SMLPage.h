#pragma once
#include <vector>
#include "SMLRegister.h"
#include "SMLBaseMem.h"
#include "DumpMemory.h"


class SMLPage:public SMLBaseMem
{
	friend std::ostream& operator<<(std::ostream&,const SMLPage &);
public:
	SMLPage(int=100);
	~SMLPage(void);
	int  read(int) const;
	void write(int,int);
	//int  getSize() const;
private:
	//const int size;
	std::vector<SMLRegister> v;
	//bool isValidAddress(int);
	//bool isValidData(int);
	
};


