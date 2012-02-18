#pragma once
#include "SMLBaseMem.h"
#include "SMLRegister.h"
#include <vector>

class RegBank:public SMLBaseMem
{
	friend std::ostream& operator<<(std::ostream&,const RegBank&);
public:
	RegBank(void);
	~RegBank(void);
	int read(int) const;
	void write(int,int);
	
private:
	std::vector<SMLRegister *> v;
	void fillBank();
	static const int NUMREGS=4;
};

