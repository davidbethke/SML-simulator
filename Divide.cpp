#include "StdAfx.h"
#include "Divide.h"
#include <iostream>
#include "RegBank.h"
using namespace std;
Divide::Divide(void):SMLInstruction(32)
{
}


Divide::~Divide(void)
{
}
void Divide::opFunc(int val, RegBank& regBank)
{
	int accumVal=regBank.read(2);
	if(val) // not zero
			regBank.write(2,(accumVal/val)); //DONE to check functionality
	else
		cout <<"DIVIDE BY ZERO Not Allowed!!, Nothing Done"<<endl;

}
