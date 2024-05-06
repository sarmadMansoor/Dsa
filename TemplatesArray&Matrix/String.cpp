#include "String.h"
#include <iostream>
//#include "Date.h"
#include <fstream>
using namespace std;
//ofstream& operator << (ofstream& ofs, const String& s2)
//{
//	
//	ofs << s2.getSize();
//	ofs << "\n";
//	ofs<< s2.data;
//	ofs << '\n';
//	return ofs;
//}
ifstream& operator>>(ifstream& ifs, String& s2)
{
	ifs >> s2.size;
	s2.data = new char[s2.size];
	ifs.ignore(); // Ignore the newline character left in the stream

	ifs.getline(s2.data, s2.size); // Read a line of text into s2.data

	return ifs;
}

ostream& operator <<(ostream& r, const String& s2)
{
	if (s2.data == nullptr)
		return r;
	r << s2.data;
	return r;
}
istream& operator >>(istream& r, String& s)
{
	s.~String();
	char ch;
	int i = 0;
	while ((ch = r.get()) != '\n')
	{
		s.reSize(i + 1);
		s.data[i] = ch;
		s.data[i + 1] = '\0';
		i++;
	}
	return r;
}
String::operator bool()
{
	if (isEmpty())
		return false;
	return true;
}
String  operator +(const char* r, const String& a)
{
	String temp{ r };
	return temp + a;
}
String::String()
{
	//	cout << "DC" << endl;
	data = nullptr;
	size = 0;
}
String::String(const char* str) :String()
{
	//cout << " const pC\t\t"<<str<< endl;
	//cout << endl;

	if (str == nullptr)
		return;
	int sizeOfStr = getLength(str);
	if (sizeOfStr != 0)
	{
		data = new char[sizeOfStr + 1];
		copyCharArray(str, data);
		size = sizeOfStr + 1;
	}
}
String::~String()
{
	//	cout << "destructor";
		//display();
		//cout << endl;
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
		size = 0;
	}
}
//String::String(Date rfs):String()
//{
//	//cout << "Date Constructor \n\n";
//	*this = rfs.getDateInFormat1();
//}
String& String::operator = (const String& ref)
{
	//cout << "assigmnet op \n";
	if (this == &ref)
		return *this;
	this->~String();
	if (!ref.data)
		return *this;
	size = ref.size;
	data = new char[size];
	copyCharArray(ref.data, data);
	return *this;
}
String::String(String&& r)
{
	//cout << "move constructor \n";
	data = r.data;
	size = r.size;
	r.data = 0;
	r.size = 0;
}
String& String::operator =(String&& rfs)
{
	//cout << "move Assigment\n";
	data = rfs.data;
	size = rfs.size;
	rfs.data = 0;
	rfs.size = 0;
	return *this;
}
String::String(const String& ref) :String()
{
	//cout << " const pC" << endl;
//	cout << "Copy  constructor \n";

	if (ref.data != nullptr)
	{
		size = ref.size;
		data = new char[size];
		copyCharArray(ref.data, data);
	}
}
//String& String::operator = (Date ref)
//{
//	cout << "string Date = opeartor \n\n";
//		this->~String();
//	*this = ref.getDateInFormat1();
//	return *this;
//}
void String::copyCharArray(const char* source, char* destination) const
{
	int i = 0;
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
}
String::String(const char c)
{
	//cout << "Char Ctor \n";
	if (c == '\0')
	{
		size = 1;
		data = new char;
		*data = '\0';
		return;
	}
	size = 2;
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
}
int String::getLength(const char* arr) const
{
	int length = 0;

	while (arr != nullptr && arr[length] != '\0')
	{
		length++;
	}
	return length;
}

char& String::operator [](int index)
{
	return data[index];
}
const char& String::operator [](const int index) const
{
	return data[index];
}
bool String::isEmpty() const
{
	if (data == nullptr || data[0] == '\0')
		return true;
	return false;
}
int String::getSize() const
{
	return size;
}
void String::display() const
{
	if (data != nullptr)
	{
		cout << data;
	}
}
int String::find(const String& subStr, const  int  start) const
{
	bool found = false;
	int length = getLength();
	int lengthOfSubStr = subStr.getLength();
	if (lengthOfSubStr == 0)
		return 0;

	for (int i = start; i <= length - lengthOfSubStr; i++)
	{
		int j = 0;
		while (j < lengthOfSubStr)
		{
			if (data[i + j] != subStr[j])
				break;
			j++;
		}
		if (j == lengthOfSubStr)
			return i;
	}
	return -1;
}

int String::getLength() const
{
	return getLength(data);
}

void String::remove(int index, int  count)
{
	if (data == nullptr)
		return;
	int lengthOfCurr = getLength();
	if (index + count > lengthOfCurr)
	{
		data[0] = '\0';
		shrink();
		return;
	}
	if (index < 0 || index >= lengthOfCurr)
		return;
	else if (lengthOfCurr == 0 || isEmpty())
		return;
	else
		copyCharArray(&data[index + count], &data[index]);
}
void String::makeUpper()
{
	if (data == nullptr)
		return;
	int lengthOfCurr = getLength();
	int i = 0;
	while (i < lengthOfCurr)
	{
		if (data[i] >= 'a' && data[i] <= 'z')
		{
			data[i] = data[i] - 'a' + 'A';
		}
		i++;
	}
}
void String::makeLower()
{
	if (data == nullptr)
		return;
	int lengthOfCurr = getLength();
	int i = 0;
	while (i < lengthOfCurr)
	{
		if (data[i] >= 'A' && data[i] <= 'Z')
		{
			data[i] = data[i] - 'A' + 'a';
		}
		i++;
	}
}
void String::trimLeft()
{
	if (isEmpty())
		return;
	int count = 0;
	int length = getLength();
	int i = 0;
	while (i < length && (data[i] == ' ' || data[i] == '\t' || data[i] == '\n'))
	{
		count++;
		i++;
	}
	copyCharArray(&data[i], data);
}

void String::trimRight()
{
	if (isEmpty())
		return;
	int length = getLength() - 1;
	int count = 0;
	while (length >= 0 && (data[length] == ' ' || data[length] == '\t' || data[length] == '\n'))
	{
		count++;
		length--;
	}
	data[length + 1] = '\0';
}
void String::trim()
{
	trimLeft();
	trimRight();
}
void String::reSize(int cap)
{
	if (cap <= 0)
	{
		this->~String();
		return;
	}
	char* temp = new char[cap + 1];
	if (!isEmpty())
		copyCharArray(data, temp);
	this->~String();
	size = cap + 1;
	data = temp;
}
void String::reverse()
{
	int length = getLength();
	if (length == 0)
		return;
	int i = 0;
	int j = length - 1;
	while (i < length / 2)
	{
		char temp = data[i];
		data[i] = data[j];
		data[j] = temp;
		i++;
		j--;
	}
}
bool String::isSame(const String& str) const
{
	if (isEmpty() && str.isEmpty())
		return 1;
	else if (isEmpty() || str.isEmpty())
		return 0;
	int currLength = getLength();
	int strLen = str.getLength();
	if (currLength != strLen)
	{
		return false;
	}
	else
	{
		int i = 0;
		while (i < currLength)
		{
			if (data[i] != str[i])
				return false;
			i++;
		}
		return true;
	}
}
bool String::operator > (const String& s2) const
{
	int currLength = getLength();
	int strLen = s2.getLength();
	if (strLen == 0 && currLength != 0)
		return true;
	if (currLength == 0 && strLen == 0)
		return false;
	int i = 0;
	while (i < currLength && i < strLen)
	{
		if (data[i] > s2[i])
			return true;
		i++;
	}
	return false;
}
bool String::operator <(const String& s2) const
{
	int currLength = getLength();
	int strLen = s2.getLength();
	if (strlen == 0 && currLength == 0)
		return false;
	if (strlen != 0 && currLength == 0)
		return true;
	if (strLen == 0 && currLength != 0)
		return false;
	int i = 0;
	while (i < currLength && i < strLen)
	{
		if (data[i] < s2[i])
			return true;
		i++;
	}
	return false;
}
bool String::operator >=(const String& s2) const
{
	if (isSame(s2))
		return true;
	if ((*this) > s2)
		return true;
	return false;
}
bool String::operator <=(const String& s2) const
{
	if (isSame(s2))
		return true;
	if ((*this) < s2)
		return true;
	return false;
}
//void String::shrink()
//{
//	if (!isEmpty())
//	{
//		int length = getLength();
//		if (length != size)
//		{
//			size = length + 1;
//		}
//	}
//}
int String::operator == (const String& s2) const
{
	if (isSame(s2))
		return 0;
	else if ((*this) > s2)
		return 1;
	else
		return -1;
}

bool  String::isFound(int start, String& s)
{
	bool found = false;
	int length = getLength();
	int lengthOfSubStr = s.getLength();
	if (lengthOfSubStr == 0)
		return 0;

	for (int i = start; i <= length - lengthOfSubStr; i++)
	{
		int j = 0;
		while (j < lengthOfSubStr)
		{
			if (data[i + j] != s[j])
				return false;
			j++;
		}
		if (j == lengthOfSubStr)
			return true;
	}
	return false;
}
int String::replace(const String& old, const  String& newSubStr)
{
	if (old.data == nullptr || newSubStr.data == nullptr)
		return 0;
	int occurances = findOccurance(old); //= //find(old);
	int i = 1;
	int newSubLen = newSubStr.getLength();
	int index = 0;
	if (occurances > 0)
	{
		while (i <= occurances)
		{
			index = find(old, index);
			remove(index, old.getLength());
			insert(index, newSubStr);
			index += newSubLen;
			i = i + 1;
		}
	}
	return occurances;
}
void String::input()
{
	this->~String();
	char ch;
	int i = 0;
	while ((ch = cin.get()) != '\n')
	{
		reSize(i + 1);
		data[i] = ch;
		data[i + 1] = '\0';
		i++;
	}
}
String String::operator +(const String& s2) const
{
	if (s2.data == nullptr)
		return String{ *this };
	else if (isEmpty())
		return String{ s2 };
	String temp{ *this };
	int len = getLength();
	int s2len = s2.getLength();
	temp.reSize(len + s2len);
	copyCharArray(s2.data, &temp.data[len]);
	return temp;
}

String String::left(const int count)
{
	int len = getLength();
	if (count > len)
		return String{ *this };
	String str{};
	if (count <= 0 || isEmpty())
		return str;
	str.reSize(count);
	int i = 0;
	while (i < count)
	{
		str.data[i] = data[i];
		i++;
	}
	str.data[i] = '\0';
	return str;
}
String String::right(const int count)
{
	int len = getLength();
	if (count > len)
		return String{ *this };
	String str{};
	if (count <= 0 || isEmpty())
		return str;
	str.reSize(count);
	int index = len - count;
	copyCharArray(&data[index], str.data);
	return str;
}
String::operator long long int() const
{
	long long int num = 0;
	if (isEmpty())
		return num;
	int i = 0;
	int len = getLength();
	int multipler = 1;
	if (data[i] == '-')
	{
		multipler = multipler * -1;
		i++;
	}
	while (i < len)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			int value = changeStringToNum(data[i]);
			num = (num * 10) + value;
			i++;
		}
		else
		{
			i++;
		}
	}
	num = num * multipler;
	return num;
}
int String::findOccurance(const String& subStr, int start)  const
{
	int count = 0;
	int length = getLength();
	int lengthOfSubStr = subStr.getLength();

	for (int i = 0; i <= length - lengthOfSubStr; i++)
	{
		int j = 0;
		bool mismatchFound = false;

		while (j < lengthOfSubStr && !mismatchFound)
		{
			if (data[i + j] != subStr[j])
			{
				mismatchFound = true;
			}
			j++;
		}

		if (!mismatchFound && j == lengthOfSubStr)
		{
			count++;
		}
	}
	return count;
}
void String::insert(const int index, const  String& subStr)
{
	if (index < 0)
		return;
	if ((isEmpty() || getLength() == 0) && index == 0)
	{
		if (!subStr.isEmpty() && subStr.data != nullptr)
		{
			reSize(subStr.getLength());
			copyCharArray(subStr.data, data);
			return;
		}
		else
			return;
	}
	int subStrLen = subStr.getLength();
	int currStrLen = getLength();
	if (index<0 || index > currStrLen)
		return;
	reSize(subStrLen + currStrLen);
	for (int i = currStrLen; i != index - 1; i--)
	{
		data[i + subStrLen] = data[i];
	}
	for (int i = 0; i < subStrLen; i++)
	{
		data[i + index] = subStr[i];
	}
}
int String::changeStringToNum(char  c) const
{
	return c - '0';
}
String& String::operator = (const long long int num)
{
	int len = getLengthOfNum(num);
	this->~String();
	long long int temp = num;
	int i = 0;
	if (temp < 0)
	{
		reSize(len + 1);
		(*this)[len] = '-';
		temp = temp * -1;
	}
	else
	{
		reSize(len);
	}
	while (len > 0)
	{
		int rem = temp % 10;
		(*this)[i] = rem + '0';
		i++;
		len--;
		temp = temp / 10;
	}
	num < 0 ? data[i + 1] = '\0' : data[i] = '\0';
	reverse();
	return *this;
}
//String& String::operator = (const double num)
//{
//	
//}
int String::getLengthOfNum(long long int num)
{
	int len = 1;
	num < 0 ? num = num * -1 : num;
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return len;
}
void  String::operator +=(const String& s2)
{
	if (s2.isEmpty())
		return;
	int len = getLength();
	int s2Len = s2.getLength();
	reSize(len + s2Len);
	copyCharArray(s2.data, &data[len]);

}
String:: operator double() const
{
	double  temp1 = 0;
	if (isEmpty())
		return 0;
	int i = 0;
	int multiple = 1;
	if (data[i] == '-')
	{
		i++;
		multiple = -1;
	}
	while (data[i] != '.')
	{
		temp1 = temp1 * 10 + (data[i] - '0');
		i++;
	}
	i++;
	int j = 1;
	while (data[i] != '\0')
	{
		float div = (data[i] - '0') / (10.0 * j);
		temp1 = temp1 + div;
		j = j * 10;
		i++;
	}
	return temp1 * multiple;
}

void String::shrink()
{
	if (!isEmpty())
	{
		int length = getLength();
		if (length + 1 != size)
		{
			char* temp = new char[length + 1];
			copyCharArray(data, temp);
			this->~String();
			data = temp;
			size = length + 1;
		}
	}
}
bool String::isCharFound(int index, const String& str)
{
	int i = 0;
	if (str.isEmpty())
		return false;
	int len = str.getLength();
	while (i < len)
	{
		if (data[index] == str[i])
		{
			return true;
		}
		i++;
	}
	return false;

}
String	String::operator ()(const String& delim)
{
	String temp{};
	if (delim.isEmpty() || isEmpty())
	{
		return temp;
	}
	int i = 0;
	int len = getLength();
	bool flag = false;
	while (i < len)
	{
		if (isCharFound(i, delim))
		{
			flag = true;
		}
		i++;
	}
	if (!flag)
	{
		temp += *this;
		this->~String();
		return temp;
	}
	flag = true;
	i = 0;
	while (flag && i < len)
	{
		if (isCharFound(i, delim))
		{
			temp.reSize(getLength());
			copyCharArray(data, temp.data);
			temp[i] = '\0';
			temp.shrink();
			remove(0, i + 1);
			flag = false;

		}
		i++;
	}
	return temp;
}
/*char String::giveNewChar(int i, String cs)
{
	cs
}*/
//void String::changeToNewChar(String cs)
//{
   // if (cs.getLength() != 26)
   //	 return;
   // int len = getLength();
   // int i = 0;
   // while (i < len)
   // {
   //	 if ((data[i] >= 'a' && data[i] <= 'z'))
   //	 {
   //		 int index = data[i] - 'a';
   //		 data[i] = cs[index];
   //	 }
   //	 i++;
   // }
//}
//bool String::checkPunctuation(int i)
//{
   // if ((data[i] >= '1' && data[i] <= '9') || (data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z'))
   // {
   //	 return false;
   // }
   // return true;
//}
/*void String::reverseWords()
{
	if (isEmpty())
		return;
	String s;
	s.reSize(getSize());
	copyCharArray(data, s.data);
	int index = 0;
	while (!isEmpty())
	{
		String temp = tokenzie(" ,!?.");
		temp.reverse();
		s.remove(index, temp.getLength());
		s.insert(index, temp);
		index = index + temp.getLength() + 1;
	}
	s.data[index] = '\0';
	copyCharArray(s.data, data);
}*/
bool String::operator !=(const String& s2) const
{
	if (isSame(s2))
		return false;
	return true;
}

bool String::operator !() const
{
	return isEmpty();
}
/*String::operator int()
{
	return toInteger();
}*/
//String::operator Date()
//{
   // return 
//}
//void String::reverseWords()
//{
   // int i = 0;
   // int lastPunIndex = -1;
   // int len = getLength();
   // while (i < len)
   // {
   //	 if (checkPunctuation(i))
   //	 {
   //		 int punIndex = i;
   //		 String temp{};
   //		 temp.reSize(punIndex - lastPunIndex+1);
   //		 char c = at(i);
   //		 at(i) = '\0';
   //		 int num;
   //		 //int ref = punIndex + 1;
   //		 if (lastPunIndex == -1)
   //			 num = 0;
   //		 else
   //			 num = -1;
   //		// lastPunIndex == -1 ? lastPunIndex == 0 : lastPunIndex;
   //		 copyCharArray(&data[num], temp.data);
   //		 remove(lastPunIndex, punIndex - lastPunIndex);

   //		// String p{ c };
   //		 //insert(lastPunIndex, p);
   //		 insert(ref, temp);
   //		// String temp;
   //		// char c = at(i);
   //		// at(i) = '\0';
   //		// temp.reSize(len);
   //		// copyCharArray(&data[ref], temp.data);
   //		// temp.reverse();
   //		///* temp.display();
   //		// cout << endl;*/
   //		// remove(ref, i);
   //		// insert(ref, temp);
   //		// at(i) = c;
   //		// ref = i+1 ;
   //	 }
   //	 i++;
   // }
//}
//----------------------------------------------------------------------------------------------------------------------

/*int origLen = getLength();
	int oldSubStrLen = old->getLength();
	int newSubStrLen = newSubStr->getLength();
	int occur = find(old, 0);
	if (occur == 0)
		return 0;
	int newSize = (newSubStrLen * occur) + (origLen - (oldSubStrLen * occur));
	char* temp = new char[newSize + 1];
	int IndexOrig = 0;
	int indexOfTemp = 0;
	while (IndexOrig < origLen)
	{
		if (isFound(IndexOrig, (*old)))
		{
			int k = 0;
			while (k < newSubStrLen)
			{
				temp[indexOfTemp] = newSubStr->at(k);
				k++;
				indexOfTemp++;

			}
			IndexOrig += oldSubStrLen;
		}
		else
		{
			temp[indexOfTemp] = data[IndexOrig];
			indexOfTemp++;
			IndexOrig++;
		}
	}
	temp[indexOfTemp] = '\0';
	this->~String();
	data = temp;;
	size = newSize + 1;
	return occur;*/



	/*int count = 0;
		int length = getLength();
		int lengthOfSubStr = subStr.getLength();

		for (int i = 0; i <= length - lengthOfSubStr; i++)
		{
			int j = 0;
			bool mismatchFound = false;

			while (j < lengthOfSubStr && !mismatchFound)
			{
				if (data[i + j] != subStr.at(j))
				{
					mismatchFound = true;
				}
				j++;
			}

			if (!mismatchFound && j == lengthOfSubStr)
			{
				count++;
			}
		}
		return count;*/


		/*bool found = false;
			int length = getLength();
			int lengthOfSubStr = subStr.getLength();
			if (lengthOfSubStr == 0)
				return 0;

			for (int i = start; i <= length - lengthOfSubStr; i++)
			{
				int j = 0;
				while (j < lengthOfSubStr)
				{
					if (data[i + j] != subStr.at(j))
						break;
					j++;
				}
				if (j == lengthOfSubStr)
					return i;
			}
			return -1;*/