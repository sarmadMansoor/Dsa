//#include "D_LinkedList.h"
//#include "D_Node.h"
//#include <iostream>
//using namespace std;
//D_LinkedList::D_LinkedList()
//{
//	head = nullptr;
//}
//void D_LinkedList::insertAtHead(int val)
//{
//	D_Node* temp = new D_Node(val);
//	if (head == nullptr)
//	{
//		head = temp;
//		tail = head;
//	}
//	else
//	{
//		head->previous = temp;
//		temp->next = head;
//		head = temp;
//	}
//}
//void D_LinkedList::insertAtTail(int val)
//{
//	D_Node* temp = new D_Node(val);
//	if (!head)
//	{
//		head = temp;
//		tail = head;
//	}
//	else 
//	{
//		temp->previous = tail;
//		tail->next = temp;
//		tail = temp;
//	}
//}
//void D_LinkedList::insertBefore(int val, int key)
//{
//	if (!head)
//		return;
//	if (head->info == key)
//	{
//		insertAtHead(val);
//		return;
//	}
//	D_Node* p = head;
//	while (p->next != nullptr && p->next->info != key)
//	{
//		p = p->next;
//	}
//	if (p->next != nullptr)
//	{
//		D_Node* x = new D_Node(val);
//		x->next = p;
//		x->previous = p->previous;
//		p->previous = x;
//		x->previous->next = x;
//	}
//
//}
//void  D_LinkedList::insertAfter(int val, int key)
//{
//	if (!head)
//		return;
//	D_Node* p = tail;
//	if (p->info == key)
//	{
//		insertAtTail(val);
//		return;
//	}
//	p = head;
//	while (p->next != nullptr && p->info != key)
//	{
//		p = p->next;
//	}
//	if ((p->next != nullptr))
//	{
//		D_Node* x = new D_Node(val);
//			x->next = p->next;
//			x->previous = p;
//			p->next = x;
//			x->next->previous = x;
//	}
//}
//
//
//void D_LinkedList::printList()
//{
//	D_Node* nodePtr; // To move through the list
//	//		
//	//		// Position nodePtr at the head of the list.
//			nodePtr = head;
//	
//			// While nodePtr points to a node, traverse
//			// the list.
//			while (nodePtr)
//			{
//				// Display the value in this node.
//				cout << nodePtr->info << endl;
//	
//				// Move to the next node.
//				nodePtr = nodePtr->next;
//			}
//}
//void D_LinkedList::removeAtTail()
//{
//	if (head == nullptr)
//		return;
//	tail = tail->previous;
//	delete tail->next;
//	tail->next = nullptr;
//}
//void D_LinkedList::removeAtHead()
//{
//	if (head == nullptr)
//		return;
//	head = head->next;
//	delete head->previous;
//	head->previous = nullptr;
//}
//void D_LinkedList::remove(int key)
//{
//	if (head == nullptr)
//		return;
//	if (tail->info == key)
//	{
//		return removeAtTail();
//	}
//	if (head->info == key)
//	{
//		return removeAtHead();
//	}
//
//	D_Node* p = head;
//	while (p->next != nullptr && p->info != key)
//	{
//		p = p->next;
//	}
//	if (p->next != nullptr)
//	{
//		p->previous->next = p->next;
//		p->next->previous = p->previous;
//		delete p;
//	}
//}
//void D_LinkedList::removeAfter(int key)
//{
//	if (head == nullptr)
//		return;
//	if (tail->previous->info == key)
//		return removeAtTail();
//	remove(searchAddress(key)->next->info);
//
//}
//void D_LinkedList::removeBefore(int key)
//{
//	if (head == nullptr)
//		return;
//	if (head->next->info == key)
//		return removeAtHead();
//	remove(searchAddress(key)->previous->info);
//
//}
//D_Node *  D_LinkedList::searchAddress(int key)
//{
//	D_Node*  p = head;
//	while (p->next!=nullptr)
//	{
//		if (p->info == key)
//			return p;
//		p = p->next;
//	}
//	return p;
//}




#include "D_LinkedList.h"
#include "D_Node.h"
#include <iostream>

using namespace std;

template<typename T>
D_LinkedList<T>::D_LinkedList() : head(nullptr), tail(nullptr) {}

//template<typename T>
//void D_LinkedList<T>::insertAtHead(const T& val) {
//    D_Node<T>* temp = new D_Node<T>(val);
//    if (!head) {
//        head = temp;
//        tail = head;
//    }
//    else {
//        head->previous = temp;
//        temp->next = head;
//        head = temp;
//    }
//}

template<typename T>
void D_LinkedList<T>::insertAtTail(const T& val) {
    D_Node<T>* temp = new D_Node<T>(val);
    if (!head) {
        head = temp;
        tail = head;
    }
    else {
        temp->previous = tail;
        tail->next = temp;
        tail = temp;
    }
}

//template<typename T>
//void D_LinkedList<T>::insertBefore(const T& val, const T& key) {
//    if (!head)
//        return;
//    if (head->info == key) {
//        insertAtHead(val);
//        return;
//    }
//    D_Node<T>* p = head;
//    while (p->next != nullptr && p->next->info != key) {
//        p = p->next;
//    }
//    if (p->next != nullptr) {
//        D_Node<T>* x = new D_Node<T>(val);
//        x->next = p;
//        x->previous = p->previous;
//        p->previous = x;
//        x->previous->next = x;
//    }
//}

//template<typename T>
//void D_LinkedList<T>::insertAfter(const T& val, const T& key) {
//    if (!head)
//        return;
//    D_Node<T>* p = tail;
//    if (p->info == key) {
//        insertAtTail(val);
//        return;
//    }
//    p = head;
//    while (p->next != nullptr && p->info != key) {
//        p = p->next;
//    }
//    if ((p->next != nullptr)) {
//        D_Node<T>* x = new D_Node<T>(val);
//        x->next = p->next;
//        x->previous = p;
//        p->next = x;
//        x->next->previous = x;
//    }
//}

//template<typename T>
//void D_LinkedList<T>::printList() {
//    D_Node<T>* nodePtr = head;
//    while (nodePtr) {
//        cout << nodePtr->info << endl;
//        nodePtr = nodePtr->next;
//    }
//}

template<typename T>
void D_LinkedList<T>::removeAtTail() {
    if (head == nullptr)
        return ;

    tail = tail->previous;
    delete tail->next;
    tail->next = nullptr;

}

template<typename T>
void D_LinkedList<T>::removeAtHead() {
    if (head == nullptr)
        return  ;
    head = head->next;
    delete head->previous;
    head->previous = nullptr;
}

template<typename T>
void D_LinkedList<T>::remove(const T& key)
{
    if (head == nullptr)
        return ;
    if (tail->info.songID == key.songID)
    {
        removeAtTail();
        return;
    }
    if (head->info.songID == key.songID)
    {
        removeAtHead();
        return;
    }
    D_Node<T>* p = head;
    while (p->next != nullptr && p->info.songID != key.songID) 
    {
        p = p->next;
    }
    if (p->next != nullptr)
    {
        p->previous->next = p->next;
        p->next->previous = p->previous;
        delete p;
    }
}

//template<typename T>
//void D_LinkedList<T>::removeAfter(const T& key) {
//    if (head == nullptr)
//        return;
//    if (tail->info == key)
//        return ;
//    if (tail->previous->info == key)
//    {
//        removeAtTail();
//        return;
//    }
//    remove(searchAddress(key)->next->info);
//    
//}

//template<typename T>
//void D_LinkedList<T>::removeBefore(const T& key) {
//    if (head == nullptr)
//        return;
//    if (head->info == key)
//        return;
//    if (head->next->info == key)
//    {
//         removeAtHead();
//         return;
//    }
//    remove(searchAddress(key)->previous->info);
//}

template<typename T>
D_Node<T>* D_LinkedList<T>::searchAddress(const T& key) 
{
    D_Node<T>* p = head;
    while (p->next != nullptr) {
        if (p->info.songID == key.songID)
            return p;
        p = p->next;
    }
    return p;
}
//template<typename T>
//bool D_LinkedList<T>::search(const T& key)
//{
//    D_Node<T>* p = head;
//    while (!p)
//    {
//        if (p->info == key)
//            return true;
//        p = p->next;
//    }
//    return false;
//}
//template<typename T>
//D_LinkedList<T>::~D_LinkedList() {
//    // Delete all nodes in the linked list
//    D_Node<T>* current = head;
//    while (current != nullptr) {
//        D_Node<T>* next = current->next;
//        delete current;
//        current = next;
//    }
//    // Reset head and tail pointers
//    head = nullptr;
//    tail = nullptr;
//}
//template<typename T>
//D_LinkedList<T>& D_LinkedList<T>::operator=(const D_LinkedList<T>& rhs)
//{
//    if (this == &rhs) // Self-assignment check
//        return *this;
//
//    this->~D_LinkedList();
//
//    if (rhs.head == nullptr)
//        return *this;;
//    D_Node<T>* rhsPtr = rhs.head;
//    while (rhsPtr != nullptr) {
//        insertAtTail(rhsPtr->info);
//        rhsPtr = rhsPtr->next;
//    }
//
//    return *this;
//}

//template<typename T>
//D_LinkedList<T>::D_LinkedList(const D_LinkedList<T>& rfs)
//{
//    *this = rfs;
//}
//template<typename T>
//void D_LinkedList<T>::reverse()
//{
//    D_Node<T>* current = head;
//    D_Node<T>* temp = nullptr;
//
//    while (current != nullptr)
//    {
//        temp = current->previous;
//        current->previous = current->next;
//        current->next = temp;
//        current = current->previous;
//    }
//    temp = head;
//    head = tail;
//    tail = temp;
//}


