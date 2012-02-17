#include "StdAfx.h"
#include "SMLRegister.h"


SMLRegister::SMLRegister(int v):value(v)
{
}


SMLRegister::~SMLRegister(void)
{
}
int SMLRegister::read()
{
	return value;
}
void SMLRegister::write(int v)
{
	value=v;
}