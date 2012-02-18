#include "StdAfx.h"
#include "Write.h"
#include <iostream>
#include "RegBank.h"
#include "SMLPage.h"


using namespace std;
Write::Write(void):SMLInstruction(11,11,88,0)
{
}


Write::~Write(void)
{
}
void Write::opFunc(int loc,SMLPage& page,int val,RegBank& regBank)
{
	int writeVal=page.read(loc);
	cout<<"val:"<<writeVal<<" loc:"<<loc<<endl;
}
