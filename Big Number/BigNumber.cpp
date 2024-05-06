#include <iostream>
#include "BigNumber.h"
using namespace std;
int BigNumber::getLength(const char* num)
{
	int i = 0;
	while (num[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}

bool BigNumber::isEmpty() const
{
	if (numberLength == 0)


		return true;
	return false;
}

BigNumber BigNumber:: operator = (const BigNumber& rfs)
{
	if (this == &rfs)
		return *this;
	this->~BigNumber();
	if (rfs.isEmpty() || rfs.number == "")
		return *this;
	number = new char[rfs.numberLength + 1];
	numberLength = rfs.numberLength;
	copyCharArray(rfs.number);
	return *this;

}
bool BigNumber::operator == (const BigNumber& str) const
{
	if (isEmpty() && str.isEmpty())
		return 1;
	if (numberLength != str.numberLength)
	{
		return false;
	}
	else
	{
		int i = 0;
		while (i < numberLength)
		{
			if (number[i] != str.number[i])
				return false;
			i++;
		}
		return true;
	}
}

void BigNumber::copyCharArray(const char* source)
{
	int i = 0;
	while (source[i] != '\0')
	{
		number[i] = source[i];
		i++;
	}
	number[i] = '\0';
}

bool BigNumber::operator > (const BigNumber& s2) const
{
	if (numberLength > s2.numberLength)
		return true;
	else if (numberLength < s2.numberLength)
		return false;
	int i = 0;
	while (i < numberLength)
	{
		if (number[i] > s2.number[i])
			return true;
		i++;
	}
	return false;
}
bool  BigNumber::operator < (const BigNumber& other) const
{
	if (*this > other)
		return false;
	return true;
}
bool BigNumber::operator >= (const BigNumber& other) const
{
	if (*this == other || *this > other)
		return true;
	return false;
}
bool BigNumber::operator <= (const BigNumber& other) const
{
	if (*this == other || *this < other)
		return true;
	return false;
}
bool BigNumber::operator != (const BigNumber& other) const
{
	if (*this == other)
		return false;
	return true;
}
BigNumber::BigNumber(const char* num)
{
	if (num == nullptr || num == "")
	{
		number = new char;
		*number = '\0';
		numberLength = 0;
	}
	else
	{
		int lengthOfNumber = getLength(num);
		number = new char[lengthOfNumber + 1];
		numberLength = lengthOfNumber;
		copyCharArray(num);
	}
}

BigNumber::BigNumber(const BigNumber& rfs)
{
	if (rfs.number == nullptr || rfs.number == "")
	{
		number = new char;
		*number = '\0';
		numberLength = 0;
		return;
	}
	number = new char[rfs.numberLength + 1];
	numberLength = rfs.numberLength;
	copyCharArray(rfs.number);
}

BigNumber::~BigNumber()
{
	if (number != nullptr)
	{
		delete[] number;
		number = nullptr;
		numberLength = 0;
	}

}

void BigNumber::print() const
{
	if (number != nullptr)
	{
		if (numberLength != 0)
		{
			cout << number;
		}
		else
		{
			cout << "0";
		}
	}

}

BigNumber BigNumber::operator + (const BigNumber& rfs) const
{
	int maxLength = (numberLength > rfs.numberLength) ? numberLength : rfs.numberLength;
	char* result = new char[maxLength + 1];
	result[maxLength] = '\0';
	int carry = 0;
	int callingObjectIndex = numberLength - 1;
	int parameterIndex = rfs.numberLength - 1;
	int resultIndex = maxLength - 1;
	while (callingObjectIndex >= 0 || parameterIndex >= 0)
	{
		int digit1 = (callingObjectIndex >= 0) ? (number[callingObjectIndex] - '0') : 0;
		int digit2 = (parameterIndex >= 0) ? (rfs.number[parameterIndex] - '0') : 0;
		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result[resultIndex] = (sum % 10) + '0';
		resultIndex--;
		callingObjectIndex--;
		parameterIndex--;
	}
	if (carry > 0)
		result[resultIndex] = carry + '0';
	BigNumber sumNumber(result);
	delete[] result;
	return sumNumber;
}

BigNumber BigNumber::operator * (const BigNumber& other) const
{
	int resultLength = numberLength + other.numberLength;
	char* result = new char[resultLength + 1];
	result[resultLength] = '\0';
	for (int i = 0; i < resultLength; i++)
	{
		result[i] = '0';
	}
	for (int i = numberLength - 1; i >= 0; i--)
	{
		int carry = 0;
		for (int j = other.numberLength - 1; j >= 0; j--)
		{
			int digit1 = number[i] - '0';
			int digit2 = other.number[j] - '0';
			int product = digit1 * digit2 + carry + (result[i + j + 1] - '0');
			result[i + j + 1] = (product % 10) + '0';
			carry = product / 10;
		}
		result[i] += carry;
	}
	int startPos = 0;
	while (result[startPos] == '0' && startPos < resultLength - 1)
	{
		startPos++;
	}
	BigNumber resultBigNum(result + startPos);
	delete[] result;
	return resultBigNum;
}
BigNumber BigNumber::operator -(const BigNumber& other) const
{
	if (*this < other)
	{
		return BigNumber("0");
	}

	int len1 = numberLength;
	int len2 = other.numberLength;
	int carry = 0;
	char* result = new char[len1 + 1];

	for (int i = len1 - 1, j = len2 - 1, k = len1 - 1; i >= 0; --i, --j, --k)
	{
		int num1 = number[i] - '0';
		int num2 = j >= 0 ? other.number[j] - '0' : 0;

		if (num1 < num2 + carry)
		{
			num1 += 10;
			result[k] = (num1 - num2 - carry) + '0';
			carry = 1;
		}
		else
		{
			result[k] = (num1 - num2 - carry) + '0';
			carry = 0;
		}
	}

	result[len1] = '\0';
	int start = 0;
	while (result[start] == '0')
	{
		++start;
	}

	BigNumber res(result + start);
	delete[] result;
	return res;
}


void BigNumber::setNumber(const char* num)
{
	this->~BigNumber();
	if (num == nullptr || num == "")
	{
		number = new char;
		*number = '\0';
		numberLength = 0;
	}
	else
	{
		int lengthOfNumber = getLength(num);
		number = new char[lengthOfNumber + 1];
		numberLength = lengthOfNumber;
		copyCharArray(num);
	}
}
