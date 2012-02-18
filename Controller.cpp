#include "StdAfx.h"
#include "Controller.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
Controller::Controller(void):enumResolver(),page(),rom(),regBank(),storeLoc(0)
{
	
}


Controller::~Controller(void)
{
}
void Controller::readProg()
{
	int  loc;
	std::string opCode;
	encodeMap();
	ifstream inFile;
	inFile.open("D:\\Users\\dave\\Documents\\myProg.txt");
	if (inFile.is_open())
	{
		while(inFile.good())
		{
			inFile>> opCode >> loc;
			cout <<"OpCode:"<<opCode<<"Loc:"<<loc<<endl;
			if(enumResolver.count(opCode)) // key has been found
			{
				if(!storeInstruction(opCode,loc))
					cout<< "Error storing Opcode:"<<opCode<<" at location:"<<loc<<endl;
			}
		}
	}
	inFile.close();
	dumpMemory(page,regBank);//TODO test by duming mem
}
void Controller::encodeMap()
{
	enumResolver["READ"]=Instruction::OpCodes::READ;
	enumResolver["WRITE"]=Instruction::OpCodes::WRITE;
	enumResolver["LOAD"]=Instruction::OpCodes::LOAD;
	enumResolver["STORE"]=Instruction::OpCodes::STORE;
	enumResolver["ADD"]=Instruction::OpCodes::ADD;
	enumResolver["SUB"]=Instruction::OpCodes::SUB;
	enumResolver["DIV"]=Instruction::OpCodes::DIV;
	enumResolver["MULT"]=Instruction::OpCodes::MULT;
	enumResolver["BRANCH"]=Instruction::OpCodes::BRANCH;
	enumResolver["BRANCHNEG"]=Instruction::OpCodes::BRANCHNEG;
	enumResolver["BRANCHZERO"]=Instruction::OpCodes::BRANCHZERO;
	enumResolver["HALT"]=Instruction::OpCodes::HALT;
	enumResolver["END"]=Instruction::OpCodes::END;
}
bool Controller::storeInstruction(string instr,int loc)
{
	bool result=false;
	if(storeLoc<page.getSize())
	{
		int storageVal;
		int opCode=100*(static_cast<int>(enumResolver[instr]));
		storageVal=opCode+loc;
		//cout << "Writing to Storage:"<<storageVal<<endl;//DONE testing storage val
		result=page.write(storeLoc,storageVal);
		storeLoc++; // increment storage location
		//return true; // TODO check storeInstruction error condition
	}
	return result;
}
SMLInstruction Controller::decode()
{
	int val;
	int opCode, loc;
	val=fetch(readIC());
	opCode=val/100;
	loc=val%100;
	if(isValidOpCode(opCode))
	{
		int operand=fetch(loc);
		SMLInstruction instruct(opCode,loc,operand);// create instruction
		return instruct;
	}
	else
	{
		cerr<<"Invalid Opcode:"<<opCode<<endl;
		exit(1);
	}

}
bool Controller::isValidOpCode(int op)
{
	//TODO validate opCode do the lazy cast thing see if it works
	return true;
}
int Controller::fetch(int loc)
{
	return page.read(loc);
}
int Controller::readIC()
{
	return regBank.read(1);//reg1 is Instruction Counter IC
}
void Controller::incIC()
{
	int v=regBank.read(1);
	regBank.write(1,v+1); // increment
}
void Controller::updateIR(SMLInstruction instruct)
{
	regBank.
