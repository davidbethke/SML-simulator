#include "StdAfx.h"
#include "Multiply.h"
#include "RegBank.h"

Multiply::Multiply(void):SMLInstruction(33)
{
}


Multiply::~Multiply(void)
{
}
void Multiply::opFunc(int val, RegBank& regBank)
{
	int accumVal=regBank.read(2);
	regBank.write(2,(accumVal*val)); //DONE to check functionality
	
}
