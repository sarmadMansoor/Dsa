#ifndef MY_ARRAY
#define MY_ARRAY
template<typename T>
class Array
{
private:
	T* data;
	int size;
	int noOfElement;
	bool isValidIndex(int) const;
	void initailize();
public:
	Array(int cnt);
	Array();
	~Array();
	int getNoOfTerm();
	Array(const Array<T>&);
	int getSize() const;
	void reSize(int);
	void display() const ;
	T & operator[](int index);
	const T & operator[](int index) const;
	Array<T>& operator =(const Array<T>& rfs);
	void add(int value);
	void insert( int index,const T & value);
	void remove (int value);
	int findElement(int element);
	void sort();
	Array <T> findNewElements( int k);
};
#endif 
