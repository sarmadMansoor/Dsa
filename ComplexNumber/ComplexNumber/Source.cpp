#include <iostream>
#include "complexNumber.h"
using namespace std;


int main()
{
	Complex<double> a{ 3,4 };
	Complex<double>  b{0, 0};
	cout << b;
}






//static ComplexNumber <T> conjugate(ComplexNumber <T>& ref)
//{
//	return ComplexNumber<T> {ref.x, ref.y * -1};
//}

















//ComplexNumber<T> operator / (ComplexNumber<T>& ref)
//{
//	T realPart = (x * ref.x + y * ref.y) / (pow(ref.x, 2) + pow(ref.y, 2));
//	T imaginaryPart = (y * ref.x - x * ref.y) / (pow(ref.x, 2) + pow(ref.y, 2));
//	return ComplexNumber<T> { realPart, imaginaryPart };
//}
//template <typename T>
//class ComplexNumber
//{
//	template <typename T >
//	friend ostream& operator<< (ostream& out, ComplexNumber <T>& ref);
//	T x, y;
//public:
//	ComplexNumber():x(0),y(0)
//	{}
//	ComplexNumber(T a, T b) :x(a), y(b)
//	{}
//	ComplexNumber<T> operator + (ComplexNumber<T>& ref)
//	{
//		return ComplexNumber<T>{ x + ref.x ,y + ref.y };
//	}
//	ComplexNumber<T> operator - (ComplexNumber<T>& ref)
//	{
//		return ComplexNumber<T>{ x - ref.x ,y - ref.y };
//	}
//	ComplexNumber<T> operator * (ComplexNumber<T>& ref)
//	{
//		return ComplexNumber<T> { ((x * ref.x) - (y * ref.y)) ,((x * ref.y) + (y * ref.x)) };
//	}
//	
//	ComplexNumber<T> operator / (ComplexNumber<T>& ref)
//	{
//		T denom = ref.x * ref.x + ref.y * ref.y;
//		return ComplexNumber<T>{ (x* ref.x + y * ref.y) / denom, (y* ref.x - x * ref.y) / denom };
//	}
//	ComplexNumber <T> conjugate()
//	{
//		return ComplexNumber<T> {x,y * -1};
//	}
//	double magnitude()
//	{
//		return sqrt(pow(x,2)+pow(y,2));
//	}
//	void print()
//	{
//		cout << x;
//		y > -1 ? cout<<" + " : cout<<' ';
//		cout << y << "i" << endl;
//	}
//	
//};