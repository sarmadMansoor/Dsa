#include<iostream>
#include "String.h"
using namespace std;

int String::getLen(const char* c) const
{
	int i = 0;
	while (c[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
void String::copyString(char* dest, const char* src, int index = 0) const
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[index] = src[i];
		i = i + 1;
		index = index + 1;
	}
	dest[index] = '\0';
}
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(const char c) :String()
{
	if (c == ' ')
		return;
	size = 2;
	data = new char[size];
	data[0] = c;
	data[1] = '\0';
}
String::String(const char* c) :String()
{
	size = getLen(c) + 1;
	if (size == 1)
		return;

	data = new char[size];
	copyString(data, c);
}
String::String(const String& ref) :String()
{
	if (!ref.data)
		return;
	size = ref.size;
	data = new char[size];
	copyString(data, ref.data);
}
String::~String()
{
	if (!data)
		return;
	//delete[] data;
	data = nullptr;
	size = 0;
}
char& String::at(const int index)
{
	if (index >= 0 && index < size - 1)
		return data[index];
	exit(0);
}
const char& String::at(const int index) const
{
	if (index >= 0 && index < size - 1)
		return data[index];
	exit(0);
}
bool String::isEmpty() const
{
	if (!data)
		return true;
	if (data[0] == '\0')
		return true;
	if (checkIfOnlySpaces(data))
		return true;
	return false;
}
bool String::checkIfOnlySpaces(const char* c) const
{
	int i = 0;
	while (c[i] != '\0')
	{
		if (c[i] != ' ')
			return false;
		i = i + 1;
	}
	return true;
}
int String::getLength() const
{
	return getLen(data);
}
int String::getSize()
{
	return size;
}
void String::display() const
{
	if (!data)
		return;
	cout << data;
}
int String::find(const String& subStr, int start = 0) const
{
	int occur = 0;
	int i = 0;
	while (data[i] != '\0')
	{
		int len = 0;
		if (data[i] == subStr.at(0))
		{
			int j = 0;
			int k = i;
			while (subStr.at(j) != '\0')
			{
				if (data[k] == subStr.at(j))
				{
					len = len + 1;
				}
				if (len == subStr.getLen(subStr.data))
					occur = occur + 1;
				k = k + 1;
				j = j + 1;
			}
		}
		i = i + 1;
	}
	if (occur > 0)
		return occur;
	return -1;
}
void String::reSize(int s)
{
	if (s <= 0)
	{
		this -> ~String();
		return;
	}
	char* temp = new char[s];
	if (data != nullptr)
	{
		copyString(temp, data);
	}
	this -> ~String();
	data = temp;
	size = s;
}

void String::insert(const int index, const String& subStr)
{
	if (index < 0 || index >= size || subStr.isEmpty())
	{
		return;
	}
	if (index + subStr.getLength() > size)
	{
		reSize(size + subStr.getLength());
	}

	for (int i = getLength(); i >= index; i--)
	{
		data[i + subStr.getLength()] = data[i];
	}
	int i = 0;
	int k = index;
	while (subStr.data[i] != '\0')
	{
		data[k] = subStr.data[i];
		i = i + 1;
		k = k + 1;
	}
}

void String::remove(const int index, const int count)
{
	int c = count;
	int i = index;
	if (index < 0 || index > size || count < 0)
	{
		return;
	}
	int len = getLength();
	if (count > (len - index))
	{
		c = len - index;
	}
	int sourceIndex = index + c;
	while (data[sourceIndex] != '\0')
	{
		data[i] = data[sourceIndex];
		i = i + 1;
		sourceIndex = sourceIndex + 1;
	}
	size = size - c;
	data[i] = '\0';
}

int String::findIndex(const String& subStr, int start = 0) const
{

	int occur = 0;
	int i = 0;
	while (data[i] != '\0')
	{
		int len = 0;
		if (data[i] == subStr.at(0))
		{
			int j = 0;
			int k = i;
			while (subStr.at(j) != '\0')
			{
				if (data[k] == subStr.at(j))
				{
					len = len + 1;
				}
				if (len == subStr.getLen(subStr.data))
					return i;
				k = k + 1;
				j = j + 1;
			}
		}
		i = i + 1;
	}
	return 0;
}
int String::replace(const String& old, const String& newSubStr)
{
	if (old.data == nullptr || newSubStr.data == nullptr)
		return 0;
	int occurances = 0;
	occurances = find(old);
	int i = 1;
	int index = 0;
	if (occurances > 0)
	{
		while (i <= occurances)
		{

			index = findIndex(old, index);
			remove(index, old.getLen(old.data));
			insert(index, newSubStr);

			i = i + 1;
		}
	}
	return occurances;
}
void String::trimRight()
{
	if (data != nullptr)
	{
		int i = getLength();
		while (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
		{
			i = i - 1;
		}
		data[i + 1] = '\0';
	}
}
void String::trimLeft()
{
	if (data != nullptr)
	{
		int i = 0;
		int len = getLength() + 1;
		while (data[0] == ' ' || data[0] == '\t' || data[i] == '\n')
		{
			int j = 0;
			while (data[j] != '\0')
			{
				data[j] = data[j + 1];
				size = size - 1;
				j = j + 1;
			}
			i = i + 1;
		}
	}
}
void String::trim()
{
	if (!data)
		return;
	trimRight();
	trimLeft();

}
void String::makeUpperCase()
{
	if (data != nullptr)
	{
		int i = 0;
		while (data[i] != '\0')
		{
			if (data[i] >= 'a' && data[i] <= 'z')
				data[i] = data[i] - 32;
			i = i + 1;
		}
	}
}
void String::makeLowerCase()
{
	if (data != nullptr)
	{
		int i = 0;
		while (data[i] != '\0')
		{
			if (data[i] >= 'A' && data[i] <= 'Z')
				data[i] = data[i] + 32;
			i = i + 1;
		}
	}
}
void String::reverse()
{
	if (data != nullptr)
	{
		int len = getLen(data);
		int till = len / 2;
		int i = 0;
		while (i <= till)
		{
			char temp = data[i];
			data[i] = data[len - i - 1];
			data[len - i - 1] = temp;
			i = i + 1;
		}
	}
}
int String::compare(const String& s2) const
{
	if (data != nullptr && s2.data != nullptr)
	{
		int len1 = getLen(data);
		int len2 = getLen(s2.data);
		if (len1 > len2)
			return 1;
		else if (len2 > len1)
			return -1;
		int i = 0;
		while (data[i] != '\0' && s2.data[i] != '\0')
		{
			if (data[i] < s2.data[i])
				return -1;
			if (data[i] > s2.data[i])
				return 1;
			i = i + 1;
		}
		if (data[i] == '\0' && s2.data[i] == '\0')
			return 0;
		return 1;
	}
}
void String::shrink()
{
	size = getLen(data);
	reSize(size);
}
void String::input()
{
	char ch;
	int index = 0;
	if (this->data != nullptr)
	{
		index = getLength();
	}
	else
	{
		size = 2;
		data = new char[size];
	}
	while (cin.get(ch))
	{
		if (ch == '\n')
		{
			data[index] = '\0';
			return;
		}
		if (index >= size - 1)
		{
			reSize(200);
		}
		data[index] = ch;
		index++;
	}
	data[index] = '\0';
}
String String::concatenate(const String& s2) const
{
	String str{};
	if (!s2.data)
		return str;
	int index = getLength();
	str.reSize(getLength() + s2.getLength() + 1);
	copyString(str.data, data);
	copyString(str.data, s2.data, index);
	return str;
}
void String::concatEqual(const String& s2)
{
	if (!s2.data)
		return;
	if (data == nullptr)
	{
		int s = s2.getLength();
		data = new char[s];
		copyString(data, s2.data);
	}
	else
	{
		int index = getLength();
		if (index + getLen(s2.data) > size)
		{
			int s = index + getLen(s2.data);
			reSize(size + s2.getLength());
		}
		copyString(&data[index], s2.data);
	}
}
String String::left(const int count)
{
	String str{};
	if (count <= 0)
		return str;
	if (!data)
		return str;
	int i = 0;
	if (str.data != nullptr)
		return str;
	str.data = new char[count + 1];
	while (i <= count)
	{
		str.data[i] = data[i];
		i = i + 1;
	}
	str.data[i] = '\0';
	return str;
}
String String::right(const int count)
{
	String str{};
	if (count <= 0)
		return str;
	if (!data)
		return str;
	if (str.data != nullptr)
		return str;
	str.data = new char[count + 1];
	int index = getLength() - count;
	copyString(str.data, &data[index]);
	return str;
}
int String::covertValueToInteger(const char c) const
{
	int val = c - '0';
	return val;
}
long long int String::convertToInteger() const
{
	long long int integer = 0;
	if (!data)
		return integer;
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			integer = (integer * 10) + covertValueToInteger(data[i]);
		}
		i = i + 1;
	}
	return integer;
}
int String::getNumLenght(const long long int num)
{
	long long int n = num;
	if (n < 0)
		n = n * -1;
	int len = 0;
	while (n > 0)
	{
		n = n / 10;
		len = len + 1;
	}
	return len;
}
int String::getDivisor(const long long int num)
{
	long long int n = num;
	int div = 1;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		div = div * 10;
	}
	return div / 10;
}
void String::setNumber(const long long int num)
{
	if (!data)
	{
		long long int n = num;
		int div = getDivisor(num);
		int length = getNumLenght(num);

		if (n < 0)
		{
			n = n * -1;
			length++;
		}

		data = new char[length + 1];

		int i = 0;
		if (num < 0)
		{
			data[i] = '-';
			i++;
		}

		while (div > 0)
		{
			int digit = n / div;
			data[i] = '0' + digit;
			n = n % div;
			div = div / 10;
			i++;
		}
		data[i] = '\0';
	}
	else
	{
		long long int n = num;
		int div = getDivisor(num);
		int length = getNumLenght(num);

		if (n < 0)
		{
			n = n * -1;
			length++;
		}
		reSize(size + getNumLenght(num));
		int i = getLength();
		if (num < 0)
		{
			data[i] = '-';
			i++;
		}

		while (div > 0)
		{
			int digit = n / div;
			data[i] = '0' + digit;
			n = n % div;
			div = div / 10;
			i++;
		}
		data[i] = '\0';
	}
}
float String::convertToFloat() const
{
	float temp1 = 0;
	if (isEmpty())
		return 0;
	int i = 0;
	int multiple = 1;
	if (at(i) == '-')
	{
		i++;
		multiple = -1;
	}
	while (at(i) != '.')
	{
		temp1 = temp1 * 10 + (at(i) - '0');
		i++;
	}
	i++;
	int j = 1;
	while (at(i) != '\0')
	{
		float div = (at(i) - '0') / (10.0 * j);
		temp1 = temp1 + div;
		j = j * 10;
		i++;
	}
	return temp1 * multiple;
}
char String::getMapCharacter(char c)
{
	if (c == 'a')
		return 'q';
	if (c == 'b')
		return 'w';
	if (c == 'c')
		return 'e';
	if (c == 'd')
		return 'r';
	if (c == 'e')
		return 't';
	if (c == 'f')
		return 'y';
	if (c == 'g')
		return 'u';
	if (c == 'h')
		return 'i';
	if (c == 'i')
		return 'o';
	if (c == 'j')
		return 'p';
	if (c == 'k')
		return 'a';
	if (c == 'l')
		return 's';
	if (c == 'm')
		return 'd';
	if (c == 'n')
		return 'f';
	if (c == 'o')
		return 'g';
	if (c == 'p')
		return 'h';
	if (c == 'q')
		return 'j';
	if (c == 'r')
		return 'k';
	if (c == 's')
		return 'l';
	if (c == 't')
		return 'z';
	if (c == 'u')
		return 'x';
	if (c == 'v')
		return 'c';
	if (c == 'w')
		return 'v';
	if (c == 'x')
		return 'b';
	if (c == 'y')
		return 'n';
	if (c == 'z')
		return 'm';
	return c;
}
void String::changeToNewCharset(String cs)
{
	int i = 0;
	while (data[i] != '\0')
	{
		char c = getMapCharacter(data[i]);
		data[i] = c;
		i = i + 1;
	}
}
bool String::isAlphabet(char c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
	{
		return true;
	}
	return false;
}
void String::reverseWords()
{
	if (!data)
		return;
	int length = getLength();
	int start = 0;
	int end = 0;
	while (start < length)
	{
		while (start < length && !isAlphabet(data[start]))
		{
			start = start + 1;
		}
		end = start;
		while (end < length && isAlphabet(data[end]))
		{
			end = end + 1;
		}
		if (start < end)
		{
			int i = start;
			int j = end - 1;
			while (i < j)
			{
				char temp = data[i];
				data[i] = data[j];
				data[j] = temp;
				i++;
				j--;
			}
		}
		start = end;
	}
}
String String::tokenzie(String receivedStr)
{
	if (!receivedStr.data)
	{
		return *this;
	}
	String str{};
	int i = 0;
	while (data[i] != '\0')
	{
		int j = 0;
		while (receivedStr.data[j] != '\0')
		{
			if (data[i] == receivedStr.data[j])
			{
				str.data[i] = '\n';
			}
			j++;
		}
		i++;
	}
	return str;
}
String& String::operator = (const String& ref)
{
	if (this == &ref)
		return *this;
	this->~String();
	size = ref.size;
	if (!ref.data)
		return *this;
	data = new char[size];
	copyString(data, ref.data);
	return *this;
}
void String::operator += (String x)
{
	concatEqual(x);
}
String String::operator + (String x)
{
	return concatenate(x);
}
bool String::operator ! () const
{
	if (!data || data[0] == '\0')
		return true;
	return false;
}
String::String(String&& r) // move constructor
{
	cout << "move constructor in string";
	*this = r;
}
void String::operator = (String&& r) // move assignment
{
	this->~String();
	data = r.data;
	size = r.size;
	r.data = 0;
	r.size = 0;
}
void String::swap(String& a, String& b)
{
	String temp = move(a);
	a = move(b);
	b = move(temp);
}
String::operator int()
{
	return convertToInteger();
}
String::operator bool()
{
	if (data != nullptr || data[0] != '\0')
		return true;
	return false;
}
String::String(Date d) :String()
{
	cout << "String constructor that recieves date" << endl;
	String s{ d.getDateInFormat1() };
	if (!s)
		return;
	data = s.data;
	size = s.size;
	s.data = 0;
	s.size = 0;
}
String& String::operator =(Date r)
{
	cout << "= in String class" << endl;
	this->~String();
	*this = r.getDateInFormat1();
	return *this;
}