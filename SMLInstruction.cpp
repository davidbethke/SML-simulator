#include "StdAfx.h"
#include "SMLInstruction.h"
#include "RegBank.h"
#include "SMLPage.h"
#include <iostream>

using namespace std;
SMLInstruction::SMLInstruction(short int o, short int l,int d,int di):op(o),loc(l),data(d),dir(di)
{
}


SMLInstruction::~SMLInstruction(void)
{
}
void SMLInstruction::opFunc(int val, RegBank& rb)
{
	cout <<"Undefined no op"<<endl;
}
void SMLInstruction::opFunc(int l,SMLPage&,int val, RegBank& rb)
{
	cout <<"Undefined no op 4 params"<<endl;
}
short int SMLInstruction::getOp() const
{
	return op;
}
short int SMLInstruction::getLoc() const
{
	return loc;
}
int SMLInstruction::getData() const
{
	return data;
}
int SMLInstruction::getDir() const
{
	return dir;
}