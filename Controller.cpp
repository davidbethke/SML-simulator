#include "StdAfx.h"
#include "Controller.h"
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
Controller::Controller(void):enumResolver(),page(),rom(),regBank(),storeLoc(0)
{
	encodeMap();
}


Controller::~Controller(void)
{
	delete theInstr;//TODO If Multiple Controllers are allowed, need Copy Constructor, assignment op
}
void Controller::initProg()
{
	//only supports Read instruction
	int  loc, val;
	std::string opCode;
	//encodeMap();
	ifstream inFile;
	inFile.open("D:\\Users\\dave\\Documents\\initProg.txt");
	if (inFile.is_open())
	{
		while(inFile.good())
		{
			inFile>> opCode >> loc>> val;
			//cout <<"OpCode:"<<opCode<<"Loc:"<<loc<<"Val:"<<val<<endl;
			if(enumResolver.count(opCode)) // key has been found
			{
				if(!storeData(loc,val))
					cout<< "Error storing Data:"<<opCode<<" at location:"<<loc<<endl;
			}
		}
	}
	inFile.close();
	cout << "InitProg Result"<<endl;
	dumpMemory(page,regBank);//TODO test by duming mem
}
void Controller::readProg()
{
	int  loc;
	std::string opCode;
	//encodeMap();
	ifstream inFile;
	inFile.open("D:\\Users\\dave\\Documents\\myProg.txt");
	if (inFile.is_open())
	{
		while(inFile.good())
		{
			inFile>> opCode >> loc;
			//cout <<"OpCode:"<<opCode<<"Loc:"<<loc<<endl;
			if(enumResolver.count(opCode)) // key has been found
			{
				if(!storeInstruction(opCode,loc))
					cout<< "Error storing Opcode:"<<opCode<<" at location:"<<loc<<endl;
			}
		}
	}
	inFile.close();
	cout <<"ReadProg Result"<<endl;
	dumpMemory(page,regBank);//TODO test by duming mem
}
void Controller::encodeMap()
{
	enumResolver["READ"]=Instruction::OpCodes::READ;
	enumResolver["WRITE"]=Instruction::OpCodes::WRITE;
	enumResolver["LOAD"]=Instruction::OpCodes::LOAD;
	enumResolver["STORE"]=Instruction::OpCodes::STORE;
	enumResolver["LOAD0"]=Instruction::OpCodes::LOAD0;
	enumResolver["STORE0"]=Instruction::OpCodes::STORE0;
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
bool Controller::storeData(int loc, int val)
{
	bool result=false;
		if(loc<page.getSize())
		{
			result=page.write(loc,val);
		}
		return result;

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
		//cout <<"Val written to instruct"<<operand<<endl;//HACK
		return instruct;
	}
	else
	{
		cerr<<"Invalid Opcode:"<<opCode<<endl;
		//return false;
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
void Controller::updateIR(const SMLInstruction& instruct)
{
	
	regBank.writeIR(instruct);
	cout <<"Val written to IR"<<regBank.readIR().getData();
}
void Controller::execute() // execute instruction in the IR
{
	//SMLInstruction *theInstr;
	//theInstru used to get correct oPFunc from ROM,loc,val are zero
	//need actual vals from IR
	short int myOp, myLoc;
	int myDat;
	myOp=regBank.readIR().getOp();
	myLoc=regBank.readIR().getLoc();
	myDat=regBank.readIR().getData();
	theInstr=rom.getInstruction(regBank.readIR().getOp());
	//for PageInstructions
	if(isStore(myOp) || isBranch(myOp)) //Store, Branch Instr
	{
		cout <<endl;
		cout <<"Store Instru detected"<<endl; //HACK

		theInstr->opFunc(myLoc,page,myDat,regBank);
	}
	else if(myOp==Instruction::END)
		cout << "End of Program"<<endl;
		//do nothing
	else
		theInstr->opFunc(myDat,regBank);
}
void Controller::run()
{
	SMLInstruction theInstr; //TODO Check 2 theInstr one a pointer one a local var
	//readProg();
	/*
	while(regBank.readIR().getOp() !=99) //(( is the end))
	{
		theInstr=decode();
		updateIR(theInstr);
		execute();
		incIC();
	}
	*/
	do{
		theInstr=decode();
		updateIR(theInstr);
		execute();
		// only inc if not a branch instruction
		if(!isBranch(theInstr.getOp()))
			incIC();

	}while(regBank.readIR().getOp() !=Instruction::END);

	dumpMemory(page,regBank);//TODO test by duming mem
}
bool Controller::isBranch(short int op)
{
	if(op == Instruction::BRANCH || op==Instruction::BRANCHNEG
		|| op == Instruction::BRANCHZERO)
		return true;
	else
		return false;
}
bool Controller::isStore(short int op)
{
	if(op== Instruction::STORE || op == Instruction::STORE0)
		return true;
	else
		return false;
}
