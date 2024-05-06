//ROLL NUMBER --------------------- >  BSE-F22-M-012 
//NAME        --------------------- >  SARMAD MANSOOR


#include <iostream>
#include "String.h"
#include "Stack_class.h"
#include "MiniStack.h"
using namespace std;

bool isValid(const String &  str)
{
	Stack<char> s{100};
	for (int i = 0; str[i] != '\0';i++)
	{
		char c = str[i];
		if (c == '(' || c == '[' || c == '{') 
		{
			s.push(c);
		}
		else
		{
			if (s.isEmpty() || (c == ')' && s.top() != '(') ||
				(c == ']' && s.top() != '[') || (c == '}' && s.top() != '{'))
			{
				return false;
			}
			else 
			{
				s.pop();
			}
		}
	}
	return s.isEmpty();
}
int* nextGreaterToLeft(int arr[], int n)
{
	Stack<int> stack{100};
	int* result = new int[n];

	for (int i = 0; i < n; ++i)
	{
		while (!stack.isEmpty() && stack.top() <= arr[i])
		{
			stack.pop();
		}

		if (stack.isEmpty())
		{
			result[i] = -1;
		}
		else
		{
			result[i] = stack.top();
		}

		stack.push(arr[i]);
	}

	return result;
}
void printArray(int arr[], int n) 
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	//TASK NUMBER 1 

	cout << isValid("()") << std::endl;
	cout << isValid("([)]") << std::endl;






	//TASK NUMBER 2 

	MinStack minStack;
	minStack.push(-5);
	minStack.push(1);
	minStack.push(2);
	cout << "getMin: " << minStack.getMin() << endl;
	minStack.push(-6);
	cout << "getMin: " << minStack.getMin() << endl;
	cout << "top: " << minStack.top() << endl;
	minStack.pop();
	cout << "top: " << minStack.top() << endl;
	cout << "getMin: " << minStack.getMin() << endl;





	//TASK NUMBER 3

	int nums1[] = { 4, 5, 2, 0 };
	int nums2[] = { 1, 6, 4, 10, 2, 5 };
	int n1 = sizeof(nums1) / sizeof(nums1[0]);
	int n2 = sizeof(nums2) / sizeof(nums2[0]);

	cout << "Output for nums1: ";
	int* result1 = nextGreaterToLeft(nums1, n1);
	printArray(result1, n1);

	cout << "Output for nums2: ";
	int* result2 = nextGreaterToLeft(nums2, n2);
	printArray(result2, n2);

	delete[] result1;
	delete[] result2;


}
