#pragma once
class SMLInstruction
{
public:
	SMLInstruction(short int=00, short int=0,int=0, int=0);
	virtual ~SMLInstruction(void);
	virtual void opFunc();
private:
	short int op;
	short int loc;
	int data;
	int dir;

};

