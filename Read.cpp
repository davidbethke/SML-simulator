#include "StdAfx.h"
#include "Read.h"
#include <iostream>

using namespace std;
Read::Read(void):SMLInstruction(10,10,99,0)
{
}


Read::~Read(void)
{
}
void Read::opFunc()
{
	cout << "Im a Read";
}