#include <iostream>
using namespace std;
#include "BigNumber.h"
int main()
{
	BigNumber a{ "1234" };
	BigNumber b{ "1234" };
	(a + b).print();

}