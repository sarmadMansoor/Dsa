#include <iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node() : next(nullptr), prev(nullptr) {}
	Node(T val) : data(val), next(nullptr), prev(nullptr) {}
};
template<typename T>
class CDLL
{
	Node<T>* head;
	Node <T>* searchAddress(const T& key)
	{
		Node<T>* temp = head;
		while (temp!=head->prev && temp->data != key)
		{
			temp=temp->next;
		}
		if (temp == head->prev && temp->data == key)
			return temp;
		if (temp != head->prev )
			return temp;
		return nullptr;
	}
	void copyFrom(const CDLL<T>& other)
	{
		if (other.head)
		{
			Node<T>* otherTemp = other.head;
			do
			{
				insertAtTail(otherTemp->data);
				otherTemp = otherTemp->next;
			} while (otherTemp != other.head);
		}
	}
	
public:
	CDLL():head(nullptr)
	{

	}// Constructor (2)
	~CDLL() //Destructor (2)
	{
		if (head)
		{
			Node<T>* temp = head;
			do
			{
				Node<T>* nextNode = temp->next;
				delete temp;
				temp = nextNode;
			} while (temp != head);
		}
	}
	CDLL<T>&  operator = (const CDLL<T>& ref)
	{
		if (&ref == this)
			return *this;
		this->~CDLL();
		if (ref.head == nullptr)
			return *this;
		copyFrom(ref);
		return *this;
	}
	CDLL<T>(const CDLL<T>& ref)//Copy Constructor (3)
	{
		*this = ref;
	}
	void insertAtHead(T val) // Insert val at head (2)
	{
		Node<T>* temp = new Node<T>(val);
		if (!head)
		{
			head = temp;
			head->next = head;
			head->prev = head;
		}
		else
		{
			temp->next = head;
			temp->prev = head->prev;
			head->prev->next = temp;
			head->prev = temp;
			head = temp;
		}
	}



	void insertAtTail(T val)//Insert val at tail (2)
	{
		Node<T>* temp = new Node<T>(val);
		if (!head)
		{
			head = temp;
			head->next = head;
			head->prev = head;
		}
		else
		{
			temp->prev = head->prev;
			temp->next = head;
			head->prev->next = temp;
			head->prev = temp;
		}
	}
	void insertAfter(T key, T val) // insert val after first occurrence of key (3)
	{
		if (!head)
			return;
		else
		{
			Node<T>* newNode = new Node<T>(val);
			Node<T>* location = searchAddress(key);
			if (location == nullptr)
				return;
			if (location == head->prev)
				return insertAtTail(val);
			location->next->prev = newNode;
			newNode->next = location->next;
			location->next = newNode;
			newNode->prev = location;
		}
	}
	void insertBefore(T key, T val) // insert val before first occurrence of key (3)
	{
		if (!head)
			return;
		else
		{
			Node<T>* newNode = new Node<T>(val);
			Node<T>* location = searchAddress(key);
			if (location == nullptr)
				return;
			if (location == head)
				return insertAtHead(val);
			location->prev->next = newNode;
			newNode->prev = location->prev;
			newNode->next = location;
			location->prev = newNode;
		}
	}
	void removeAtHead() // Remove Node at Head (3)
	{
		if (!head)
			return;
		else if (head==head->prev)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			head->next->prev = head->prev;
			Node<T>* temp = head;
			head = head->next;
			head->prev->next = head;
			delete temp;
		}
	}
	void removeAtTail() // Remove Node at Tail (3)
	{
		if (!head)
			return;
		else if (head == head->prev)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node<T>* temp = head->prev;
			head->prev = head->prev->prev;
			head->prev->next = head;
			delete temp;

		}
	}
	void removeAfter(T key) // Remove the node after first occurrence of key (3)
	{
		if (!head)
			return;
		else
		{
			Node<T>* location = searchAddress(key);
			if (location == nullptr)
				return;
			if (location == head->prev)
				return removeAtTail();
			Node<T>* temp = location->next;
			location->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	void removeBefore(T key) //Remove node before first occurrence of key (3)
	{
		if (!head)
			return;
		else
		{
			Node<T>* location = searchAddress(key);
			if (location == nullptr)
				return;
			if (location == head->next)
				return removeAtHead();
			Node<T>* temp = location->prev;
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
	}
	 
	void remove(T key) // Remove first occurrence of key (3)
	{
		if (!head)
			return;
		else if (head->data == key)
			return removeAtHead();
		else if (head->prev->data == key)
			return removeAtTail();
		else
		{
			Node<T>* location = searchAddress(key);
			location->prev->next = location->next;
			location->next->prev = location->prev;
			delete location;
		}

	}
	void display()
	{
		if (!head)
			return;
		Node<T>* temp = head;
		do
		{
			cout << "Prev: " << temp->prev->data << ";";
			cout << "Data:  " << temp->data << ";";
			cout << "Next:  " << temp->next->data << ";";
			temp = temp->next;
			cout << endl;
		} while (temp != head);
	}
	int getLength()
	{
		int len = 0;
		if (!head)
			return len;
		Node <T>* temp = head;
		do
		{
			temp = temp->next;
			len++;
		} while (temp != head);
		return len;
	}
	void rotateCircularDLL(int times)
	{
		int len = getLength();
		int rotateNumber = times % len;
		Node <T>* tail = head;
		while (rotateNumber >= 1)
		{
			tail = tail->prev;
			rotateNumber--;
		}
		head = tail;
	}
	bool targetSum(int target)         
	{
		Node<T>* left = head;
		Node<T>* right = head->prev;
		while (left != right)
		{
			if (left->data + right->data < target)
			{
				left = left->next;
			}
			else if (left->data + right->data > target)
			{
				right = right->prev;
			}
			else
			{
				return true;
			}
		}
		return false;
	}




};
int main()
{
	CDLL<int> a;
	a.insertAtTail(1);
	a.insertAtTail(2);
	a.insertAtTail(3);
	a.insertAtTail(4);
	a.insertAtTail(5);
	cout << a.targetSum(8);
	//a.rotateCircularDLL(7);
	//a.display();
	/*a.insertAtTail(1);
	a.insertAtTail(2);
	a.insertAtTail(3);
	a.insertAtTail(4);
	a.insertAtTail(5);
	a.insertAtTail(3);
	a.insertAtTail(9);
	a.insertAfter(3, 0);*/
	/*a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();
	a.removeAtTail();*/
	//a.removeBefore(99);
	/*a.removeAtHead();
	a.removeAtHead();*/
	//a.removeAtHead();
	//a.remove(3);
	// 
	//a.display();
	//CDLL<int> b;
	////b = a;
	////b.display();
	//cout << endl;
	//cout<<b.getLength();

}
