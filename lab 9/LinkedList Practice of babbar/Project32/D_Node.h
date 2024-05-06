#ifndef  D_NODE_H
#define  D_NODE_H
//class D_Node
//{
//	
//public:
//	int info;
//	D_Node* next;
//	D_Node* previous;
//	D_Node();
//	D_Node(int val);
//};
template<typename T>
class D_Node 
{
public:
    T info;
    D_Node<T>* next;
    D_Node<T>* previous;

    // Default constructor
    D_Node() : info(T()), next(nullptr), previous(nullptr) {}

    // Constructor with value initialization
    D_Node(const T& val) : info(val), next(nullptr), previous(nullptr) {}
};

#endif // ! D_NODE_H
