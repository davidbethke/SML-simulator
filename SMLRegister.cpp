#include "StdAfx.h"
#include "SMLRegister.h"
#include <iostream>


using namespace std;
SMLRegister::SMLRegister(std::string n,int v):value(v),name(n)
{
}


SMLRegister::~SMLRegister(void)
{
}
int SMLRegister::read() const
{
	return value;
}
void SMLRegister::write(int v)
{
	value=v;
}
string SMLRegister::getName() const
{
	return name;
}