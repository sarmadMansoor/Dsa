#ifndef DATE_CLASS
#define DATE_CLASS
#include"String.h"
class String;
class Date
{
	//friend class String;
	int day;
	int month;
	int year;
	static const int daysInMonth[13];
	bool isLeapYear() const;
	String getMonthInString()const;
	String getShortMonthInString() const;
public:
	Date();
	Date(int, int, int);
	void setDate(int, int, int);
	void input();
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printFormat1() const;
	void printFormat2() const;
	void printFormat3() const;
	void incDay(int = 1);
	void incMonth(int = 1);
	void incYear(int = 1);
	String getDateInFormat1() const;
	String getDateInFormat2() const;
	String getDateInFormat3() const;
	String toString(const long long int) const;
	bool compareDate(const Date&) const;
	Date operator + (Date);
	void operator += (Date);
	Date& operator ++();
	Date operator++(int);
	bool operator ==(Date);
	operator String();

};

#endif
