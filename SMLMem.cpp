#include "StdAfx.h"
#include "SMLMem.h"
#include <iostream>
using namespace std;

SMLMem::SMLMem(int s):SMLBaseMem(s),v(s)
{
}

SMLMem::~SMLMem(void)
{
}
int SMLMem::read(int add)
{
	if(isValidAddress(add))
		return v[add].read();
	else
	{
		cerr<< "Invalid Read Attempted to Mem Loc:"<<add<<endl;
		cerr<< "Program Halted"<<endl;
		exit(1);
	}
}
void SMLMem::write(int add,int val)
{
	if(isValidAddress(add) && isValidData(val))
		return v[add].write(val);
	else
	{
		cerr<< "Invalid Write Attempted to Mem Loc:"<<add<<endl;
		cerr<< "Program Halted"<<endl;
		exit(1);
	}
}
/*
int SMLMem::getSize() const
{
	return size;
}
bool SMLMem::isValidAddress(int add)
{
	if(add >=0 && add <size)
		return true;
	else
		return false;
}
bool SMLMem::isValidData(int dat)
{
	if(dat>-1000 & dat <1000)
		return true;
	else
		return false;
}
*/