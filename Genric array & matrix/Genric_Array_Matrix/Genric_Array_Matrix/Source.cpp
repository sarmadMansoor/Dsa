#include <iostream>
#include "Array.h"
#include "Matrix.h"
using namespace std;
int main()
{
	int rows = 2, col = 2;
	Matrix<int > t1(rows,col);
	int num= 1;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			t1[i][j] = num;
		}
	}
	t1.display();
	Matrix<int> t2 = t1;
	t2.display();
	cout << t2.isSymmetric();
	/*Matrix<int> t2;
	t2= t1;
	t2.display();*/
	//cout << t2.operator==(t1) << endl;
}
