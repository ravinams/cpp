#include "BST.h"

BST::BST() : root(nullptr) {}

//void BST::insert(int insertItem)
//{
//	Node  *newNode = new Node;
//	newNode->data = insertItem;
//	insert(root, newNode);
//}
//
//void BST::insert( Node* &p, Node *newNode)
//{
//	if (p == nullptr)
//		p = newNode;
//	else if (p->data > newNode->data)
//		insert(p->llink, newNode);
//	else
//		insert(p->rlink, newNode);
//}

void BST::inorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		inorderTraversal(root);
	}
}

void BST::inorderTraversal(const Node *p) const
{
	if (p != nullptr)
	{		
		inorderTraversal(p->llink);
		cout << p->data << " ";
		inorderTraversal(p->rlink);		
	}
}

void  BST::destroyTree(Node* &p)
{
	if (p != nullptr)
	{
		destroyTree(p->llink);
		destroyTree(p->rlink);
		delete p;
		p = nullptr;
	}
}
	
void  BST::destroyTree()
{
	destroyTree(root);
}

BST::~BST()
{
	destroyTree(root);
}

