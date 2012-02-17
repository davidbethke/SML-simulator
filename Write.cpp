#include "StdAfx.h"
#include "Write.h"
#include <iostream>


using namespace std;
Write::Write(void):SMLInstruction(11,11,88,0)
{
}


Write::~Write(void)
{
}
void Write::opFunc()
{
	cout << "Im a Write";
}
