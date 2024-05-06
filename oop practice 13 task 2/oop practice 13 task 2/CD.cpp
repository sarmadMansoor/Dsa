#include <iostream>
#include "CD.h"
#include "String.h"
using namespace std;
void CD::display()
{
	cout << "The title of CD is: " << getTitle() << endl;
	cout << "The capacity of CD is : " << capacity <<" MBs" << endl;
}
CD::CD():Media()
{

}
CD::CD(String T, int cap) :Media(T), capacity(cap)
{

}
Media* CD::clone() const
{
	return new CD{ *this };
}
Media* CD::fresh() const
{
	return new CD{};
}
