#include "StdAfx.h"
#include "SMLBaseMem.h"
#include <iostream>

using namespace std;
SMLBaseMem::SMLBaseMem(int s):size(s)
{
}


SMLBaseMem::~SMLBaseMem(void)
{
}
int SMLBaseMem::getSize() const
{
	return size;
}
bool SMLBaseMem::isValidAddress(int add) const
{
	if(add >=0 && add <size)
		return true;
	else
		return false;
}
bool SMLBaseMem::isValidData(int dat) const
{
	if(dat>-1000 && dat <1000)
		return true;
	else
		return false;
}
void SMLBaseMem::accessError(int code) const
{
	if(code)
		cerr<<"Invalid address"<< endl;
	else
		cerr<<"Invalid access"<<endl;
}

