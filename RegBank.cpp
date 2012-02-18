#include "StdAfx.h"
#include "RegBank.h"
#include "NamedRegisters.h"
#include <iostream>

using namespace std;
RegBank::RegBank(void):SMLBaseMem(NUMREGS),v(NUMREGS)
{
	fillBank();
}


RegBank::~RegBank(void)
{
}
int RegBank::read(int add) const
{
	if(isValidAddress(add))
		return v[add]->read();
	else
		accessError(add);
}
void RegBank::write(int add, int val)
{
	if(isValidAddress(add) && isValidData(val))
		v[add]->write(val);
	else
		accessError(add);

}
void RegBank::fillBank()
{
	/*
	v[0]=SMLInstReg();
	v[1]=InstructionCounter();
	v[2]=SMLAccum();
	v[3]=SMLRegister(); // General Purpose
	*/
	// need pointers?
	v[0]=new SMLInstReg;
	v[1]=new InstructionCounter;
	v[2]=new SMLAccum;
	v[3]=new SMLRegister; // General Purpose

}
 std::ostream& operator<<(std::ostream& os,const RegBank& regBank)
 {
	 os<<"REGISTERS:"<<endl;
	 for(int i=0;i<regBank.NUMREGS;++i)
		 os<<regBank.v[i]->getName()<<":\t\t\t"<<regBank.v[i]->read();
	 // print opcode and operand
	 //os<<regBank.v[0]->  //TODO figure out how to access instruction private member of SMLRegister derived class SMLInstReg
	 return os;
 }