#include "StdAfx.h"
#include "Subtract.h"
#include "RegBank.h"

Subtract::Subtract(void):SMLInstruction(31)
{
}


Subtract::~Subtract(void)
{
}
void Subtract::opFunc(int val,RegBank& regBank)
{
	int accumVal=regBank.read(2);
	regBank.write(2,accumVal); //DONE to check functionality
}
