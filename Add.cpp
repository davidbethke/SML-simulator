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
	regBank.write(2,accumVal+val+3); //TODO Hack to check functionality

}
