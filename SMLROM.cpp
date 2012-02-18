#include "StdAfx.h"
#include "SMLROM.h"



SMLROM::SMLROM(int s):SMLBaseMem(s),v(s)
{
	fillRom();
}


SMLROM::~SMLROM(void)
{
}
SMLInstruction*  SMLROM::getInstruction(int add) 
{
	if(isValidAddress(add))
		return (v[add]);
	else
	{
		accessError(add);
		exit(1);
	}
}
void SMLROM::fillRom()
{
	//SMLInstruction arr[]={Add(),Branch(),BranchNeg(),BranchZero(),Divide(),Halt(),Load(),
	//					Multiply(),Read(),Store(),Subtract(),Write()};
	SMLInstruction * arr[]={(new Add),new Branch,new BranchNeg,new BranchZero,new Divide,new Halt,new Load,
						new Multiply,new Read,new Store,new Subtract,new Write,new End,new Load0, new Store0};
	/*
	Read read;
	Write write;
	v[read.getOp()]=read;
	v[write.getOp()]=write;
	*/
	for(int i=0; i< NUM_INSTRUCT;++i)
		v[arr[i]->getOp()]=arr[i];
}
