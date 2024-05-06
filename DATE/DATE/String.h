#ifndef MY_STRING
#define MY_STRING
#include"Date.h"
#include<iostream>
using namespace std;
class String
{
	friend String operator +(const char* c, String& x);
	friend ostream& operator <<(ostream&, const String&);
	friend istream& operator >>(istream&, String&);


	friend class Date;
	char* data;
	int size;
	void copyString(char*, const char*, int index) const;
	int getLen(const char* c) const;
	bool checkIfOnlySpaces(const char*) const;
	int getNumLenght(const long long int num);
	int getDivisor(const long long int num);
	char getMapCharacter(const char);
	bool isAlphabet(char c);

public:
	String();
	String(const char);
	String(const char*);
	String(const String&);
	String(String&&);
	const char& at(const int index) const;
	char& at(const int index);
	~String();
	bool isEmpty() const;
	void input();
	int getLength() const;
	int getSize();
	void display() const;
	int find(const String&, int) const;
	void insert(const int, const String&);
	void reSize(int);
	void remove(const int, const int count);
	int replace(const String&, const String&);
	int findIndex(const String&, int index) const;
	void trimRight();
	void trimLeft();
	void trim();
	void makeUpperCase();
	void makeLowerCase();
	void reverse();
	void shrink();
	int compare(const String&) const;
	String concatenate(const String&) const;
	String left(const int count);
	String right(const int count);
	int covertValueToInteger(char c) const;
	long long int convertToInteger() const;
	void concatEqual(const String& s2);
	void setNumber(const long long int num);
	float convertToFloat() const;
	void changeToNewCharset(String cs);
	void reverseWords();
	String tokenzie(String);
	void operator +=(String);
	String operator +(String);
	String& operator =(const String& ref);
	void operator =(String&&); // for move
	bool operator !() const;
	void swap(String& a, String& b);
	operator int();
	operator bool();
	String(Date);
	String& operator =(Date);

};
#endif // !MY_STRING
