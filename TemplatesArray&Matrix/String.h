#ifndef  MY_STRING
#define MY_STRING
#include <iostream>
#include <fstream>
using namespace std;
//class Date;
class String
{
	friend istream& operator >>(istream& r, String& s2);
	friend ifstream& operator >>(ifstream& ifs, String& s2);
	friend ostream& operator << (ostream&, const String&);
	friend ofstream& operator << (ofstream&, const String&);
	//friend String  operator +(const char* r, const String& a);



	char* data;
	int size;


	//char giveNewChar(int i,String cs);
	int getLength(const char*) const;
	void copyCharArray(const char*, char*) const;
	bool isSame(const String& s2) const;
	bool isFound(int, String&);
	int changeStringToNum(char) const;
	int findOccurance(const String& subStr, int = 0) const;
	int getLengthOfNum(long long int num);
	bool isCharFound(int, const String& str);
	//bool checkPunctuation(int);
	bool isEmpty() const;
public:
	String();
	String(const char c);
	String(const char*);
	String(const String&);
	String(String&& r);
	String& operator = (const String& ref);
	String& operator =(String&& rfs);
	~String();
	void input();
	void shrink();


	const char& operator [](const int index) const;
	char& operator [](int index);

	bool operator !() const;
	int getLength() const;
	int getSize() const;
	void display() const;
	int find(const String& subStr, const  int  start = 0) const;
	void insert(const int index, const  String& subStr);
	void remove(int index, int  count = 1);
	int replace(const String& old, const  String& newSubStr);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reSize(int);
	void reverse();
	int operator == (const String& s2) const;
	bool operator >(const String& s2) const;
	bool operator <(const String& s2) const;
	bool operator >=(const String& s2) const;
	bool operator <=(const String& s2) const;
	bool operator !=(const String& s2) const;

	String left(const int count);
	String right(const int count);
	String operator +(const String& s2) const;
	void operator +=(const String&);
	String& operator = (const long long int num);
	String& operator = (const double num);


	//	String(Date);
		/*char& at(int index);
		const char& at(const int index) const;*/


	explicit operator bool();
	explicit operator double() const;
	explicit operator long long int() const;
	String	operator ()(const String& delim);
	/*

	//	String(Date);
	/*char& at(int index);
	const char& at(const int index) const;

	int toInteger() const;

	float toFloat() const;
	void changeToNewChar(String cs);
	void reverseWords();
	explicit operator int();
	String& operator = ( Date ref);
*/
};
#endif