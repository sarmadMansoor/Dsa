#ifndef BIG_NUMBER_H
#define  BIG_NUMBER_H
class BigNumber
{
	char* number;
	int numberLength;
	int getLength(const char* num);
	void copyCharArray(const char* source);
	bool isEmpty() const;
public:
	BigNumber(const char*);
	BigNumber(const BigNumber&);
	~BigNumber();
	void setNumber(const char* num);
	void print() const;
	BigNumber operator = (const BigNumber&);
	BigNumber operator + (const BigNumber&) const;
	BigNumber operator - (const BigNumber& other) const;
	BigNumber operator * (const BigNumber& other) const;
	bool operator == (const BigNumber& other) const;
	bool operator > (const BigNumber& other) const;
	bool operator < (const BigNumber& other) const;
	bool operator >= (const BigNumber& other) const;
	bool operator <= (const BigNumber& other) const;
	bool operator != (const BigNumber& other) const;

};
#endif // ! BIG_NUMBER_H

