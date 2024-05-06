#include <iostream>
#include "D_LinkedList.h"
#include "string"
using namespace std;
//class Node
//{
//
//public:
//	int data;
//	Node* next;
//	Node(int data)
//	{
//		this->data = data;
//		this->next = NULL;
//	}
//
//};
//struct ListNode
//{
//	double value;
//	ListNode* next;
//};
//class NumberList
//{
//
//	ListNode* head;
//public:
//	// Constructor
//	NumberList()
//	{
//		head = nullptr;
//	}
//	~NumberList()
//	{
//		if (!head)
//			return;
//		while (head->next)
//		{
//			ListNode* previousNode = head;
//			head = head->next;
//			delete previousNode;
//		}
//	}
//	void appendNode(double val)
//	{
//		ListNode* newNode;
//		ListNode* nodePtr;
//		newNode = new ListNode;
//		newNode->value = val;
//		newNode->next = NULL;
//
//		if (!head)
//			head = newNode;
//		else
//		{
//			nodePtr = head;
//			while (nodePtr->next)
//				nodePtr = nodePtr->next;
//			nodePtr->next = newNode;
//		}
//	}
//	void insertNode(double val)
//	{
//		ListNode* newNode;
//		ListNode* nodePtr;
//		newNode = new ListNode;
//		newNode->value = val;
//		//newNode->next = nullptr;
//		if (!head)
//		{
//			head = newNode;
//			newNode->next = nullptr;
//		}
//		else
//		{
//			nodePtr = head;
//			ListNode* previousNode = nullptr;
//
//			while (nodePtr != nullptr && nodePtr->value < val)
//			{
//				previousNode = nodePtr;
//				nodePtr = nodePtr->next;
//
//			}
//
//			if (previousNode == nullptr)
//			{
//				head = newNode;
//				head->next = nodePtr;
//			}
//			else
//			{
//				previousNode->next = newNode;
//				newNode->next = nodePtr;
//			}
//
//		}
//	}
//	void deleteNode(double val)
//	{
//		ListNode* nodePtr = head;
//		if (!head)
//			return;
//		if (head->value == val)
//		{
//			nodePtr = head->next;
//			delete head;
//			head = nodePtr;
//		}
//
//		else
//		{
//			ListNode* previousNode = nullptr;
//			while (nodePtr != nullptr && nodePtr->value != val)
//			{
//				previousNode = nodePtr;
//				nodePtr = nodePtr->next;
//			}
//			if (nodePtr)
//			{
//				previousNode->next = nodePtr->next;
//				delete nodePtr;
//			}
//
//		}
//	}
//	void displayList() const
//	{
//		ListNode* nodePtr; // To move through the list
//
//		// Position nodePtr at the head of the list.
//		nodePtr = head;
//
//		// While nodePtr points to a node, traverse
//		// the list.
//		while (nodePtr)
//		{
//			// Display the value in this node.
//			cout << nodePtr->value << endl;
//
//			// Move to the next node.
//			nodePtr = nodePtr->next;
//		}
//	}
//	void insertByPosition(int position, double  data)
//	{
//		if (position <= 0)
//			return;
//		ListNode* newNode = new ListNode;
//		ListNode* previousNode =nullptr;
//		newNode->value = data;
//		newNode->next = nullptr;
//		if (position == 1)
//		{
//			previousNode = head;
//			head = newNode;
//			newNode->next = previousNode;
//		}
//		else
//		{
//			int cnt = 1;
//			ListNode* curr = head;
//			while (cnt  < position)
//			{
//				previousNode = curr;
//				curr = curr->next;
//				cnt++;
//			}
//			previousNode->next = newNode;
//			newNode->next = curr;
//		}
//	}
//	void reverse()
//	{
//		if (!head || head->next==nullptr)
//			return;
//		else
//		{
//			ListNode* curr = head;
//			ListNode* temp =head;
//			ListNode* previous =nullptr;
//			while (temp != nullptr)
//			{
//				temp = curr->next;
//				curr->next = previous;
//				previous = curr;
//				curr = temp;
//			}
//			head = previous ;
//		}
//	}
//};
//struct D_Node
//{
//	double value;
//	D_Node* next;
//	D_Node* previous;
//};
//class D_linkedList
//{
//	D_Node* head;
//public:
//	D_linkedList()
//	{
//		head = nullptr;
//	}
//	void appendNode(double val)
//	{
//		D_Node * newNode = new D_Node();
//		D_Node * temp = nullptr ;
//		newNode->value = val;
//		newNode->previous = nullptr;
//		newNode->next = nullptr;
//		if (!head)
//			head = newNode;
//		else
//		{
//			temp = head;
//			while (temp->next != nullptr)
//			{
//				temp = temp->next;
//			}
//			temp->next = newNode;
//			newNode->previous = temp;
//		}
//	}
//	void displayList() const
//	{
//		D_Node* nodePtr; // To move through the list
//
//		// Position nodePtr at the head of the list.
//		nodePtr = head;
//
//		// While nodePtr points to a node, traverse
//		// the list.
//		while (nodePtr)
//		{
//			// Display the value in this node.
//			cout << nodePtr->value << endl;
//
//			// Move to the next node.
//			nodePtr = nodePtr->next;
//		}
//	}
//};
////class A
////{
////public:
////	~A()
////	{
////		cout << "A ka Dest\n";
//// }
////};
//void insertAtHead(int data, Node*& tail)
//{
//	Node* head = new Node(data);
//	head->next = tail;
//	tail = head;
//}
//void insertAtTail(int data, Node*& head)
//{
//	Node* tail = new Node(data);
//	head->next = tail;
//	head = tail;
//
//}
//void print(Node*& head)
//{
//	Node* temp = head;
//	while (temp != NULL)
//	{
//		cout << temp->data << " ";
//		temp = temp->next;
//	}
//	cout << endl;
//
//}
//void insertAtPosition(int position, int data, Node*& head)
//{
//
//}
//class DLLNode
//{
//public :
//	int val;
//	DLLNode* next;
//	DLLNode* previous;
//	DLLNode() :val(0)
//	{
//		next = nullptr;
//		previous = nullptr;
//	}
//	DLLNode(int d, DLLNode* n, DLLNode* p)
//	{
//		val = d;
//		next = n;
//		previous = p;
//	}
//};
//class DLlIST
//{
//	DLLNode* head;
//	DLLNode* tail;
//public:
//	DLlIST()
//	{
//		head = nullptr;
//		tail = nullptr;
//	}
//	void insertAtHead(int e)
//	{
//		if (head == nullptr)
//		{
//			head = new  DLLNode(e, 0, 0);
//			head = tail;
//		}
//		else
//		{
//			head = new DLLNode(e, head, 0);
//			head->next->previous = head;
//		}
//	}
//	void insertAtTail(int e)
//	{
//		if (tail == nullptr)
//		{
//			tail = new DLLNode(e, 0, 0);
//			head = tail;
//		}
//		else
//		{
//			tail = new DLLNode(e, 0, tail);
//			tail->previous->next = tail;
//		}
//
//	}
//	void displayList() 
//	{
//		DLLNode* nodePtr; // To move through the list
//		
//		// Position nodePtr at the head of the list.
//		nodePtr = head;
//
//		// While nodePtr points to a node, traverse
//		// the list.
//		while (nodePtr)
//		{
//			// Display the value in this node.
//			cout << nodePtr->val << endl;
//
//			// Move to the next node.
//			nodePtr = nodePtr->next;
//		}
//	}
//	int deleteFromHead()
//	{
//		if (head == nullptr)
//			return -1;
//		int value;
//		if (head == tail)
//		{ 
//			value = head->val;
//			delete head;
//			head = nullptr;
//			tail = nullptr;
//		}
//		else
//		{
//			value = head->val;
//			head = head->next;
//			delete head->previous;
//			head->previous = nullptr;
//		}
//		return value;
//	}
//	int deleteFromTail()
//	{
//		if (tail == nullptr)
//			return -1;
//		int value;
//		 if (head == tail)
//		{
//			 value = head->val;
//			delete head;
//			head = nullptr;
//			tail = nullptr;
//		}
//		else
//		{
//			 value = tail->val;
//			tail = tail->previous ;
//			delete tail->next;
//			tail->next = nullptr;
//		}
//		 return value;
//	}
//	void reverse()
//	{
//		if (head == nullptr)
//			return;
//		else if (head == tail)
//			return;
//		else
//		{
//			DLLNode* temp = tail;
//			tail->next = tail->previous;
//			tail->previous = nullptr;
//			tail = tail->next;
//			while (tail->previous != nullptr)
//			{
//				DLLNode* temp = tail->next;
//				tail->next = tail->previous;
//				tail->previous = temp;
//				tail = tail->next;
//			}
//			tail->previous = tail->next;;
//			tail->next = nullptr;
//			head = temp;
//		}
//	}
//};
//class Stack
//{
//	DLlIST stack;
//public:
//	void push(int d)
//	{
//		stack.insertAtTail(d);
//	}
//	int pop()
//	{
//		return stack.deleteFromTail();
//	}
//
//};
class Song
{
public:
	int songID;
	string title;
	string artist;
	string album;
	int durationInSecond;
	Song(int id, string t, string a, string al, int dur)
	{
		songID = id;
		title = t;
		artist = a;
		album = al;
		durationInSecond = dur;
	}
};
class MusicPlayer
{
	D_LinkedList <Song> playlist;
	D_Node <Song>* currentSongNode;
public:
	MusicPlayer() :playlist()
	{
		currentSongNode = nullptr;
	}
	void addSongToPlaylist(const Song& rfs)
	{
		playlist.insertAtTail(rfs);
		if (currentSongNode == nullptr)
			currentSongNode = playlist.head;
	}
	void removeSongFromPlaylist(int singID)
	{
		Song temp(singID, "", "", ",", 0);
		playlist.remove(temp);
	}
	void playPlayList()
	{
		while (currentSongNode != nullptr)
		{
			cout << "song id = " << currentSongNode->info.songID << endl;
			cout << "song title  = " << currentSongNode->info.title << endl;
			cout << "song artist name  = " << currentSongNode->info.artist << endl;
			cout << "song album = " << currentSongNode->info.album << endl;
			cout << "song duration = " << currentSongNode->info.durationInSecond << endl;
			currentSongNode = currentSongNode->next;
		}
	}
	void moveForword()
	{
		if (currentSongNode->next != nullptr)
			currentSongNode = currentSongNode->next;
	}
	void moveBackWard()
	{
		if (currentSongNode->previous != nullptr)
			currentSongNode = currentSongNode->previous;
	}
	void displayPlayList()
	{
		D_Node <Song>* temp = playlist.head;
		while (temp!= nullptr)
		{
			cout << "song id = " << temp->info.songID << endl;
			cout << "song title  = " << temp->info.title << endl;
			cout << "song artist name  = " << temp->info.artist << endl;
			cout << "song album = " << temp->info.album << endl;
			cout << "song duration = " << temp->info.durationInSecond << endl;
			temp = temp->next;
		}
	}
	void displayCurrentSong()
	{
		if (currentSongNode != nullptr)
		{
			cout << "song id = " << currentSongNode->info.songID << endl;
			cout << "song title  = " << currentSongNode->info.title << endl;
			cout << "song artist name  = " << currentSongNode->info.artist << endl;
			cout << "song album = " << currentSongNode->info.album << endl;
			cout << "song duration = " << currentSongNode->info.durationInSecond << endl;
		}
	}
	
	void deleteNthSongFromEnd(int n)
	{
		if (playlist.tail == 0|| n==0)
			return;
		if (n == 1)
		{
			playlist.removeAtTail();
			return;
		}
		D_Node<Song>* temp = playlist.tail;
		while (n > 1 && temp->previous != nullptr)
		{
			temp = temp->previous;
			n--;
		}
		if (n == 1)
		{
			playlist.remove(temp->info);
		}
	}
	void mergePlayLists(D_LinkedList<Song>& playlist2)
	{
		if (playlist2.head == nullptr)
			return;
		if (playlist.head == nullptr)
		{
			playlist.head = playlist2.head;
		}
		D_LinkedList<Song>  res;
		D_Node<Song> * playlist2Temp = playlist2.head;
		while (playlist.head != nullptr && playlist2Temp!= nullptr)
		{
			if (playlist.head->info.songID < playlist2Temp->info.songID)
			{
				res.insertAtTail(playlist.head->info);
				playlist.head=playlist.head->next;
			}
			else
			{
				res.insertAtTail(playlist2Temp->info);
				playlist2Temp=playlist2Temp->next;
			}
		}

		while (playlist.head!= nullptr)
		{
			res.insertAtTail(playlist.head->info);
			playlist.head = playlist.head->next;
		}
		while (playlist2Temp != nullptr)
		{
			res.insertAtTail(playlist2Temp->info);
			playlist2Temp = playlist2Temp->next;
		}
		
		playlist.head = res.head;
	}
	void  shufflePlaylist()
	{
		if (playlist.head == nullptr || playlist.head->next == nullptr)
			return;
		D_LinkedList <Song> playlistTemp;
		D_Node <Song>* temp = playlist.head;
		while (temp)
		{
			if (temp->next)
				playlistTemp.insertAtTail(temp->next->info);
			playlistTemp.insertAtTail(temp->info);
			temp = temp->next;
			if (temp )
				temp = temp->next;
		}
		playlist.head = playlistTemp.head;

	}
};
int main()
{
	MusicPlayer p1;
	p1.addSongToPlaylist(Song{ 3,"hallo","ali","good",5 });
	p1.addSongToPlaylist(Song{ 8,"hallo","ali","good",5 });
	p1.addSongToPlaylist(Song{ 9,"hallo","ali","good",5 });
	p1.addSongToPlaylist(Song{ 14,"hallo","ali","good",5 });
	p1.addSongToPlaylist(Song{ 89,"hallo","ali","good",5 });


	D_LinkedList<Song> p2;
	p2.insertAtTail(Song{ 1,"hallo","ali","good",5 });
	p2.insertAtTail(Song{ 5,"hallo","ali","good",5 });
	p2.insertAtTail(Song{ 17,"hallo","ali","good",5 });
	p2.insertAtTail(Song{ 20,"hallo","ali","good",5 });

	p1.shufflePlaylist();
	//p1.mergePlayLists(p2);
	//p1.removeSongFromPlaylist(2);
	//p1.deleteNthSongFromEnd(5);
	p1.displayPlayList();
	//D_LinkedList <int> a;
	/*a.insertAtTail("anas");
	a.insertAtTail("ahmad");*/
	//a.printList();
	/*D_LinkedList<int> a;
	a.insertAtTail(1);
	a.insertAtTail(2);
	a.insertAtTail(3);
	a.reverse();
	a.printList();*/
	//a.insertAfter(4, 3);
	///*a.insertAtHead(1);
	//a.insertAtHead(2);
	//a.insertAtHead(3);*/
	//a.printList();
	////a.removeAfter(4);
	//cout << "-------------\n";
	//D_LinkedList<int> b;
	//b = a;
	//b.printList();
	//cout << "--- " << b.removeAtHead() << endl;
	//DLlIST l;
	//l.insertAtTail(2);
	//l.insertAtTail(3);
	//l.insertAtTail(4);
	//l.insertAtTail(5);
	//l.reverse();
	////l.insertAtTail(5);
	//l.insertAtTail(1);

	////l.deleteFromTail();
	//l.displayList();
	//NumberList  list;

	//// Append some values to the list.
	//list.appendNode(2.5);
	//list.appendNode(7.9);
	//list.appendNode(12.6);
	////list.insertNode(99.5);
	////list.insertByPosition(0,99.5);
	//list.reverse();
	//list.displayList();
	// Display the list.
	//cout << "Here are the initial values:\n";
	//list.displayList();
	//cout << endl;

	//// Delete the middle node.
	//cout << "Now deleting the node in the middle.\n";
	//list.deleteNode(7.9);

	//// Display the list.
	//cout << "Here are the nodes left.\n";
	//list.displayList();
	//cout << endl;

	//// Delete the last node.
	//cout << "Now deleting the last node.\n";
	//list.deleteNode(12.6);

	//// Display the list.
	//cout << "Here are the nodes left.\n";
	//list.displayList();
	//cout << endl;

	//// Delete the only node left in the list.
	//cout << "Now deleting the only remaining node.\n";
	//list.deleteNode(2.5);

	//// Display the list.
	//cout << "Here are the nodes left.\n";
	//list.displayList();
	return 0;

	/*int a = 9;
	int * p = &a;
	int* q = p;
	*q = 1;
	cout << a;*/
	/*Node* n1 = new Node(10);
	Node* head = n1;
	Node* tail = n1;
	for (int i = 0; i < 5; i++)
	{
		insertAtTail(i, tail);
	}
	print(head);*/
	//Node* n2 = new Node(9);
	//Node  n1(10);
	/*cout<< n1->data << endl;
	cout<< n1->next << endl;*/
	//cout << "hallo" << endl;
}

//void shuffle()
//{
//	Node<Song>* head = playlist.getHead();
//	Node<Song>* d = new Node<Song>();
//	d->next = head;
//
//	Node<Song>* prev = d;
//	Node<Song>* first = head;
//	Node<Song>* second = head->next;
//
//	while (second)
//	{
//		prev->next = second;
//		first->next = second->next;
//		second->next = first;
//
//		prev = first;
//		first = first->next;
//
//		if (first)
//			second = first->next;
//		else
//			second = nullptr;
//	}
//
//	head = d->next;
//	delete d;
//}
