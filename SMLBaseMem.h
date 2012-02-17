#pragma once
class SMLBaseMem
{
public:
	SMLBaseMem(int =100);
	~SMLBaseMem(void);
	virtual int getSize() const;
protected:
	virtual bool isValidAddress(int) const;
	virtual bool isValidData(int) const;
	virtual void accessError(int) const;
private:
	const int size;

};

