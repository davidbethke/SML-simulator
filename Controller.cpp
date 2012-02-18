#include "StdAfx.h"
#include "Controller.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
Controller::Controller(void):enumResolver(),page(),storeLoc(0)
{
}


Controller::~Controller(void)
{
}
void Controller::readProg()
{
	int  loc;
	std::string opCode;
	ifstream inFile;
	inFile.open("D:\\Users\\dave\\Documents\\myProg.txt");
	if (inFile.is_open())
	{
		while(inFile.good())
		{
			inFile>> opCode >> loc;
			cout <<"OpCode:"<<opCode<<"Loc:"<<loc<<endl;
			if(enumResolver.count(opCode)) // key has been found
				if(!storeInstruction(opCode,loc))
					cout<< "Error storing Opcode:"<<opCode<<" at location:"<<loc<<endl;
		}
	}
	inFile.close();
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
}
bool Controller::storeInstruction(string instr,int loc)
{
	int storageVal;
	int opCode=100*(static_cast<int>(enumResolver[instr]));
	storageVal=opCode+loc;
	page.write(storeLoc,storageVal);
	storeLoc++; // increment storage location
	return true; // TODO check storeInstruction error condition

}
