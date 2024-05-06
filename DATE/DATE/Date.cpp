#include <iostream>
#include <iomanip>
#include "Date.h"
//#include "String.h"

using namespace std;
const int Date::daysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
Date::Date() :day(14), month(10), year(2019)
{}
Date::Date(int d, int m, int y) :day(d), month(m), year(y)
{}
bool Date::isLeapYear() const
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
void Date::setDate(int d, int m, int y)
{
	if (y > 1500 && y < 3000)
		year = y;
	if (m < 13 && m > 0)
		month = m;
	if (isLeapYear() && month == 2 && d <= 29 && d > 0)
		day = d;
	else if (d <= daysInMonth[m] && d > 0)
		day = d;
}
void Date::setDay(int d)
{
	if (isLeapYear() && month == 2 && d <= 29 && d > 0)
		day = d;
	else if (d <= daysInMonth[month] && d > 0)
		day = d;
}
void Date::setMonth(int m)
{
	if (m < 13 && m > 0)
		month = m;
}
void Date::setYear(int y)
{
	if (y > 1500 && y < 3000)
		year = y;
}
bool Date::compareDate(const Date& d) const
{
	if (d.getDay() == getDay() && d.getMonth() == getMonth() && d.getYear() == getYear())
		return true;
	return false;
}
int Date::getDay() const
{
	return day;
}
int Date::getMonth() const
{
	return month;
}
int Date::getYear() const
{
	return year;
}
void Date::input()
{
	int d, m, y;
	cout << "\nEnter date: e.g(12 03 2019) -> day month year: ";
	cin >> d >> m >> y;
	if ((m < 1 || m > 12) || (d < 1 || (d > 31 && !(m == 4 || m == 6 || m == 9 || m == 11)) ||
		(d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) ||
		(d > 29 && m == 2 && (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0))) ||
		(d > 28 && m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))) ||
		y <= 0))
	{
		while ((m < 1 || m > 12) || (d < 1 || (d > 31 && !(m == 4 || m == 6 || m == 9 || m == 11)) ||
			(d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) ||
			(d > 29 && m == 2 && (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0))) ||
			(d > 28 && m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))) ||
			y <= 0))
		{
			cout << "Please enter valid date";
			cout << "\nEnter date: (12 03 2019): ";
			cin >> d >> m >> y;
		}
	}
	setDate(d, m, y);
}

void Date::printFormat1() const
{
	cout << setw(2) << right << setfill('0') << month << '/';
	cout << setw(2) << right << setfill('0') << day << '/';
	cout << setw(4) << right << setfill('0') << year;
}
String Date::getMonthInString() const
{
	String m[12]{ "January", "February", "March", "April", "May", "June", "July",
							"August", "September", "October", "November", "December" };
	return m[getMonth() - 1];
}
void Date::printFormat2() const
{
	String d{ getMonthInString() };
	d.display();
	cout << " " << getDay() << "," << getYear();
}
String Date::getShortMonthInString() const
{
	String m[12]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
							"Aug", "Sep", "Oct", "Nov", "Dec" };
	return m[getMonth() - 1];
}
void Date::printFormat3() const
{
	String m{ getShortMonthInString() };
	cout << getDay() << '-';
	m.display();
	cout << "-" << getYear();
}
void Date::incYear(int y)
{
	setYear(getYear() + y);
}
void Date::incMonth(int m)
{
	int totalMonths = month + m;
	if (totalMonths > 12)
	{
		incYear((getMonth() + m) / 12);
		setMonth((getMonth() + m) % 12);
	}
	else
	{
		setMonth(getMonth() + m);
	}
}
void Date::incDay(int n)
{
	int total = (getDay() + n);
	int maxDaysInMonth = daysInMonth[month];
	if (isLeapYear() && getMonth() == 2)
	{
		maxDaysInMonth = 29;
	}
	if (total > maxDaysInMonth)
	{
		setDay(total % maxDaysInMonth);
		incMonth(total / maxDaysInMonth);
	}
	else
		setDay(getDay() + n);
}
String Date::toString(const long long int n) const
{
	String s;
	s.setNumber(n);
	return s;
}
String Date::getDateInFormat1() const
{
	String date;
	if (getDay() < 10)
		date += "0";
	date += toString(getDay());
	date += "/";
	if (getMonth() < 10)
		date += "0";
	date += toString(getMonth());
	date += "/";
	date += toString(getYear());
	return date;
}
String Date::getDateInFormat2() const
{
	String date;
	date += getMonthInString();
	date += " ";
	date += toString(getDay());
	date += ",";
	date += toString(getYear());
	return date;
}
String Date::getDateInFormat3() const
{
	String date;
	date += toString(getDay());
	date += "-";
	date += getShortMonthInString();
	date += "-";
	date += toString(getYear());
	return date;
}
Date& Date::operator ++ () // pre increment
{
	incDay();
	return *this;
}
Date Date::operator ++ (int) // post increment
{
	Date x = *this;
	incDay();
	return x;
}
bool Date::operator == (Date r)
{
	if (day == r.day && month == r.month && year == r.year)
		return true;
	return false;
}
Date::operator String()
{
	cout << "operator String()" << endl;
	return this->getDateInFormat1();
}
