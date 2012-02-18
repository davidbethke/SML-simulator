#include "StdAfx.h"
#include "End.h"
#include "RegBank.h"
#include <iostream>

using namespace std;
End::End(void):SMLInstruction(49)
{
}


End::~End(void)
{
}
void End::opFunc(int val,RegBank& regBank)
{
	//do nothing
	//cout <<"END opFunc call"<<endl; //HACK
}
