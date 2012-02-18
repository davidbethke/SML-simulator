#include "StdAfx.h"
#include "Add.h"
#include "RegBank.h"

Add::Add(void):SMLInstruction(30)
{
}


Add::~Add(void)
{
}
void Add::opFunc(int val, RegBank& regBank)
{
	int accumVal=regBank.read(2);
	regBank.write(2,(accumVal+val)); //DONE to check functionality
	//HACK write to GP reg too
	int accumVal2=regBank.read(3);
	regBank.write(3,(accumVal2+val));

}
