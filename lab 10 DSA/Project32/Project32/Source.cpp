#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int val):data (val),left(nullptr),right(nullptr)
	{}
};
class Tree
{
	Node* root;
	
	Node* deleteNode(Node* node, int item)
	{
		if (node == nullptr)
			return node;

		if (item < node->data)
		{
			node->left = deleteNode(node->left, item);
		}
		else if (item > node->data)
		{
			node->right = deleteNode(node->right, item);
		}
		else
		{
			if (node->left == nullptr)
			{
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr)
			{
				Node* temp = node->left;
				delete node;
				return temp;
			}

			Node* temp = findMin(node->right);
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
		return node;
	}

	Node* findMin(Node* node)
	{
		Node* current = node;
		while (current && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}
	int findHeightRecurisve(Node* r)
	{
		if (r == nullptr)
			return 0;
		int left = findHeightRecurisve(r->left);
		int right = findHeightRecurisve(r->right);
		if (left > right)
			return 1 + left;
		else
			return 1 + right;
	}
	
	Node* lowestCommonAncestorRecursive(Node* root, Node* l, Node* right)
	{
		if (root == nullptr or root->data == l->data or root->data == right->data)
			return root;
		Node* leftNode = lowestCommonAncestorRecursive(root->left, l, right);
		Node* rightNode = lowestCommonAncestorRecursive(root->right, l, right);
		if (leftNode == nullptr)
			return rightNode;
		else if (rightNode == nullptr)
			return leftNode;
		else
			return root;
	}
public:
	
	
	Tree():root(nullptr)
	{}
	bool search(int value)
	{
		Node* temp = root; bool status = false;
		while (temp != nullptr && status == false)
		{
			if (value < temp->data)
				temp = temp->left;
			else if (value > temp->data)
				temp = temp->right;
			else if (value == temp->data)
				status = true;
		}
		if (status)
			return true;
		return false;
	}
	void insert(int value)
	{
		if (!root)
			root = new Node(value);
		Node* temp = root;  Node* parent = root;
		while (temp != nullptr)
		{
			if (value < temp->data)
			{
				parent = temp;
				temp = temp->left;
			}
			else if (value > temp->data)
			{
				parent = temp;
				temp = temp->right;
			}
			else if (value == temp->data)
				return ;
		}
		temp = new Node(value);
		if (value < parent->data)
			parent->left = temp;
		else
			parent->right = temp;
	}
	
	int findHeight()
	{
		return findHeightRecurisve(root);
	}
	Node* findMin()
	{
		Node* current = root;
		while (current && current->left!= nullptr)
		{
			current = current->left;
		}
		return current;
	}
	Node* findMax()
	{
		Node* current = root;
		while (current && current->right != nullptr)
		{
			current = current->right;
		}
		return current;
	}
	void deleteItem(int item)
	{
		root = deleteNode(root, item);
	}
	

	Node* lowestCommonAncestor(Node* l, Node* right)
	{
		return lowestCommonAncestorRecursive(root, l, right);
	}
	void inorder(Node * node, int * arr, int& i)
	{
		if (!node) return;
		inorder(node->left, arr, i);
		arr[i] = node->data;
		inorder(node->right, arr, i+=1 );
	}

	bool findTarget(int tsum)
	{
		int* arr = new int [100];
		int size = 0;
		inorder(root, arr, size);
		int i = 0, j = size - 1;
		while (i != j)
		{
			if (arr[i] + arr[j] == tsum)
			{
				return true;
			}
			if (arr[i] + arr[j] > tsum)
			{
				j--;
			}
			if (arr[i] + arr[j] < tsum)
			{
				i++;
			}
		}
		return false;
	}
};
int main()
{
	Tree tree;
	tree.insert(6);
	tree.insert(2);
	tree.insert(8);
	tree.insert(0);
	tree.insert(4);
	tree.insert(7);
	tree.insert(9);
	tree.insert(3);
	tree.insert(5);
	Node a(2), b(4);
	cout << tree.lowestCommonAncestor(&a,&b)->data << endl;
	cout << tree.findTarget(16) << endl;
	cout << endl;
	/*tree.deleteItem(7);
	tree.postOrder();
	cout << endl << tree.findHeight() << endl;*/
}



















//bool checkTreeIsBST()
//{
//	Node* temp = root;
//	// Stores root node and left 
//   // subtree of each node 
//	stack<Node* > Stack;
//
//	// Stores previous visited node 
//	Node* prev = NULL;
//
//	// Traverse the binary tree 
//	while (!Stack.empty() ||
//		temp != NULL) {
//
//		// Traverse left subtree 
//		while (temp != NULL) {
//
//			// Insert root into Stack 
//			Stack.push(temp);
//
//			// Update root 
//			temp = temp->left;
//		}
//
//		// Stores top element of Stack 
//		temp = Stack.top();
//
//		// Remove the top element of Stack 
//		Stack.pop();
//
//		// If data value of root node less 
//		// than data value of left subtree 
//		if (prev != NULL &&
//			temp->data <= prev->data) {
//			return false;
//		}
//
//		// Update prev 
//		prev = temp;
//
//		// Traverse right subtree 
//		// of the tree 
//		temp = temp->right;
//	}
//	return true;
//}
//int minDepth(Node* root)
//{
//	if (root == NULL)
//		return 0;
//	if (root->left == NULL && root->right == NULL)
//		return 1;
//	int l = INT_MAX, r = INT_MAX;
//	if (root->left)
//		l = minDepth(root->left);
//	if (root->right)
//		r = minDepth(root->right);
//	return 1 + (min(l, r));
//}




//void preOrder()
//{
//	preOrderRecursive(root);
//	/*stack <Node*> s;
//	Node* temp = root;
//	s.push(temp);
//	while (!s.empty())
//	{
//		temp = s.top();
//		cout<< temp->data<<"\t";
//		s.pop();
//		if (temp->right != nullptr)
//			s.push(temp->right);
//		if (temp->left != nullptr)
//			s.push(temp->left);
//
//	}*/
//}
//void inOrder()
//{
//	inOrderRecursive(root);
//	/*stack<Node* > s ;
//	Node* temp = root;
//	while (true)
//	{
//		if (temp != nullptr)
//		{
//			s.push(temp);
//			temp = temp->left;
//		}
//		else
//		{
//			if (s.empty())
//				break;
//			temp = s.top();
//			s.pop();
//			cout << temp->data << "\t";
//			temp=temp->right;
//		}
//	}*/
//}
//
//void postOrder()
//{
//	postOrderRecursive(root);
//	/*stack <Node*> s1;
//	stack <Node*> s2;
//	Node* temp = root;
//	s1.push(temp);
//	while (!s1.empty())
//	{
//		temp = s1.top();
//		s1.pop();
//		s2.push(temp);
//		if (temp->left != nullptr)
//			s1.push(temp->left);
//		if (temp->right != nullptr)
//			s1.push(temp->right);
//	}
//	while (!s2.empty())
//	{
//		cout << s2.top()->data << "\t";
//		s2.pop();
//	}*/
//}


























//void preOrderRecursive(Node* r)
//{
//	if (r == nullptr)
//		return;
//	cout << r->data << '\t';
//	preOrderRecursive(r->left);
//	preOrderRecursive(r->right);
//}
//void inOrderRecursive(Node* r)
//{
//	if (r == nullptr)
//		return;
//	inOrderRecursive(r->left);
//	cout << r->data << '\t';
//	inOrderRecursive(r->right);
//}
//void postOrderRecursive(Node* r)
//{
//	if (r == nullptr)
//		return;
//	postOrderRecursive(r->left);
//	postOrderRecursive(r->right);
//	cout << r->data << '\t';
//}
/*bool isPossible(Node* root, long long l, long long r)
	{
		if (root == nullptr)  return true;
		if (root->data < r and root->data > l)
			return isPossible(root->left, l, root->data) &&
			isPossible(root->right, root->data, r);
		else
			return false;
	}*/
	/*bool symmetric(Node* rleft, Node* rright)
	{
		if (rleft == NULL || rright == NULL)
			return rleft == rright;
		if (rleft->data != rright->data)
			return false;
		return symmetric(rleft->left, rright->right) && symmetric(rleft->right, rright->left);
	}*/