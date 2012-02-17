#include "StdAfx.h"
#include "Divide.h"
#include <iostream>

using namespace std;
Divide::Divide(void):SMLInstruction(32)
{
}


Divide::~Divide(void)
{
}
void Divide::opFunc()
{
	cout << "Im a Divide";
}
