#pragma once
class SMLRegister
{
public:
	SMLRegister(int=0);
	virtual ~SMLRegister(void);
	int read();
	void write(int);
private:
	int value;
};

