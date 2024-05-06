#ifndef D_LINKEDLIST_H
#define D_LINKEDLIST_H
#include"D_Node.h"
    template<typename T>
    class D_LinkedList
    {
        D_Node<T>* searchAddress(const T& key);
    public:
        D_Node<T>* head;
        D_Node<T>* tail;
      
    
        D_LinkedList();
        //D_LinkedList(const D_LinkedList<T> & rfs);
      // D_LinkedList<T>& operator =(const  D_LinkedList<T>& rfs);
        void insertAtHead(const T& val);
        void insertAtTail(const T& val);
        //void insertBefore(const T& val, const T& key);
        //void insertAfter(const T& val, const T& key);

        void printList();

        void remove(const T& key);
        void removeAtHead();
        void  removeAtTail();
        //void removeAfter(const T& key);
        //void removeBefore(const T& key);
        //bool search(const T& key);
       // ~D_LinkedList();
        //void reverse();
       // void reorderList();


        //~LinkedList
    };
//	D_Node* head;
//	D_Node* tail;
//	D_Node* searchAddress(int key);
//public:
//	D_LinkedList();
//	void insertAtHead(int val);
//	void insertAtTail(int val);
//	void insertBefore(int val, int key);
//	void insertAfter(int val, int key);
//
//	void printList();
//
//	void remove(int key);
//	void removeAtHead();
//
//	void removeAtTail();
//	void removeAfter(int key);
//	void removeBefore(int key);
//	bool search(int key);
//	//~LinkedL

#endif
