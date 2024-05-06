#include<iostream>
#include"Array.h"
#include"Matrix.h"
#include"String.h"
#include"Set.h"
#include <initializer_list>

using namespace std;

template<typename T>
void mySwap(T* a, T* b)
{
	T* temp = a;
	a = b;
	b = temp;
}
template<typename T>
void myGenericSort(T* arr,int size)
{
	for (int i = 0; i < size ; i++)
	{
		for (int j = 0; j < (size - 1); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	
	Array<int> a{ 12,3,4 };
	a.display();

	cout << endl;
	Matrix<int> m{ 2,2 };
	m[0][0] = 1;
	m[0][1] = 1;
	m[1][0] = 1;
	m[1][1] = 1;
	m.display();
	cout << endl;
	Set<int> s{ 1,2,3,4 };
	s.print();

	return 0;

}
//Set <int >  a = { 1,2,3,4 };

	////cout << a.getCardinality();
	//
	//Array<int> s{ 1,2,3,4 };

	//cout << s.getSize() << endl;
	//const int* p = s.end();
	//p--;
	////cout << *p;
	//while (p != s.begin())
	//{
	//	cout << *p << " ";
	//	p--;
	//}
	//cout << *p;

	//cout << endl << endl;

	//Array<int>x{ 12,2,3,4 };
	//

	////Array<int> h = { 1,2,3 };
	//return 0;
	////Set st{ 1,2,3,4 };

	////	INTERNAL BUFFER CHANGE

	//ifstream ifs("Test.txt", ios::binary);
	//cout << ifs.rdbuf(); // reads the data from the file and display on console

	//ofstream  ofs("Test2.txt", ios::binary);
	//ofs << ifs.rdbuf(); // reads the data from the test file and writes in test2 file

	////	pipeline / buffer change

	//cout.rdbuf(ofs.rdbuf()); // buffer of cout change to ofs'
	//cout << "hello"; // hello will be written in test2 file



	//

	////pipeline change
	////cout.rdbuf(ofs)



	//Array<Array<float>> a;
	//a.reSize(3);
	//a[0].reSize(3);
	//a[1].reSize(3);
	//a[2].reSize(3);
	//for (int i = 0; i < a.getSize(); i++)
	//{
	//	for (int j = 0; j < a[i].getSize(); j++)
	//	{
	//		cin >> a[i][j];
	//	}
	//}

	//for (int i = 0; i < a.getSize(); i++)
	//{
	//	for (int j = 0; j < a[i].getSize(); j++)
	//	{
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//3d array

	/*Array<Array<Array<int>>> a;
	int val = 100;
	a.reSize(3);*/

	/*a[0].reSize(3);
	a[1].reSize(3);
	a[2].reSize(3);*/
	/*for (int i = 0; i < a.getSize(); i++)
	{
		a[i].reSize(3);
	}*/

	/*a[0][0].reSize(3);
	a[0][1].reSize(3);
	a[0][2].reSize(3);*/
	/*a[1][0].reSize(3);
	a[1][1].reSize(3);
	a[1][2].reSize(3);

	a[2][0].reSize(3);
	a[2][1].reSize(3);
	a[2][2].reSize(3);*/
	/*for (int i = 0; i < a.getSize(); i++)
	{
		for (int j = 0; j < a[i].getSize(); j++)
		{
			a[i][j].reSize(3);
		}
	}

	for (int i = 0; i < a.getSize(); i++)
	{
		for (int j = 0; j < a[i].getSize(); j++)
		{
			for (int k = 0; k < a[i][j].getSize(); k++) 
			{
				a[i][j][k] = val;
				val++;
			}
		}
	*/

	//for (int i = 0; i < a.getSize(); i++)
	//{
	//	for (int j = 0; j < a[i].getSize(); j++)
	//	{
	//		for (int k = 0;k < a[i][j].getSize(); k++)
	//		{
	//			cout << a[i][j][k] << "\t";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//}
	

	// end 3d array
	//int arr[5] = { 9,2,6,4,0 };
	//myGenericSort(arr, 5);

	/*Matrix<int> m(2,2);
	m[0][0] = 1;
	m[0][1] = 2;
	m[1][0] = 3;
	m[1][1] = 4;*/

	//m.display();
	/*Array<int> ar;
	ar.reSize(3);
	for (int i = 0; i < ar.getSize(); i++)
		ar[i] = i;
	Matrix<Array<int>> m2(2,2);
	m2[0][0] = ar;
	m2[0][1] = ar;
	m2[1][0] = ar;
	m2[1][1] = ar;
	m2.display();*/



	//Matrix<String> m(2,2);
	//m[0][0] = "anas";
	//m[0][1] = "cheema";
	//m[1][0] = "usman";
	//m[1][1] = "cake";
	//m.reSize(3, 2);
	//m[2][0] = "usman";
	//m[2][1] = "cake";
	//m.display();

	/*Matrix<Matrix<String>> m1(2, 2);
	m1[0][0] = m;
	m1[0][1] = m;
	m1[1][0] = m;
	m1[1][1] = m;

	m1.display();*/


	/*auto x = { 1,2,3,4 };
	for (auto val : x)
	{
		cout << val << " ";
	}*/
