#pragma once

class RegBank;
class SMLPage;
class SMLInstruction
{
public:
	SMLInstruction(short int=00, short int=0,int=0, int=0);
	virtual ~SMLInstruction(void);
	virtual void opFunc(int,RegBank&); //TODO Consider making this const
	virtual void opFunc(int,SMLPage&,int,RegBank&); 
	short int getOp() const;
	short int getLoc() const;
	int getData() const;
	int getDir() const;
private:
	short int op;
	short int loc;
	int data;
	int dir;

};

