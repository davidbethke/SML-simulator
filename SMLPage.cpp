#include "StdAfx.h"
#include "SMLPage.h"
#include <iostream>
#include <iomanip>
using namespace std;

SMLPage::SMLPage(int s):SMLBaseMem(s),v(s)
{
}

SMLPage::~SMLPage(void)
{
}
int SMLPage::read(int add) const
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
bool SMLPage::write(int add,int val)
{
	if(isValidAddress(add) && isValidData(val))
	{
		v[add].write(val);
		return true;
	}
		
	else
	{
		cerr<< "Invalid Write Attempted to Mem Loc:"<<add<<endl;
		cerr<< "Program Halted"<<endl;
		return false;
		//exit(1);
	}
}
std::ostream& operator<<(std::ostream& os,const SMLPage & page)
{
	int temp=0;//TODO nicer dump output
	//os<<temp; 
	for(int i=0;i<page.getSize();++i)
	{
		
		os.width(5);
		os<<showpos;
		os<<setfill('0')<<internal;
		os<< page.read(i)<< " ";
		temp++;
			if(!(temp%10))
			{
				os << endl;
				//os<noshowpos;
				//os<<temp;
			}
	}
	return os;
}
/*
int SMLPage::getSize() const
{
	return size;
}
bool SMLPage::isValidAddress(int add)
{
	if(add >=0 && add <size)
		return true;
	else
		return false;
}
bool SMLPage::isValidData(int dat)
{
	if(dat>-1000 & dat <1000)
		return true;
	else
		return false;
}
*/