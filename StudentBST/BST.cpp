#include <iostream>

#include "BST.h"

using namespace std;

//Constructor for the BST class
template <typename Comparable>
BST<Comparable>::BST()
{
	root = NULL;    //creating a new BST. Initially, root is NULL
}

/*
template <typename Comparable>
void BST<Comparable>::deletePreOrder(node<Comparable>* current)
{
	if(current==NULL)
		return;
	deletePreOrder(current->left);
}
*/
//Destructor for the BST class
template <typename Comparable>
BST<Comparable>::~BST()
{

}

template <typename Comparable>
void BST<Comparable>::insert(const Comparable & x)
{
	node<Comparable>* newNode = createNode(x);

	insertNode(root, newNode);
}


template <typename Comparable>
void BST<Comparable>::insert(Comparable && x)
{
	node<Comparable>* newNode = createNode(x);
		
	insertNode(root, newNode);
}

template <typename Comparable>
bool BST<Comparable>::isEmpty()
{
	if (root == NULL)
		return true;

	return false;
}



template <typename Comparable>
void BST<Comparable>::printInOrder(node<Comparable>* current)
{
	if(current==NULL)
		return;
	printInOrder(current->left);
	//printStudent(current->data);
	printInOrder(current->right);
}

template <typename Comparable>
void BST<Comparable>::printTree()
{
	if (root == NULL)
	{
		cout << "\nTree is empty";
		return;
	}

	printInOrder(root);
}

template <typename Comparable>
node<Comparable>* BST<Comparable>::createNode(const Comparable & x)
{
	node<Comparable>* ptr = new node<Comparable>;
	
	ptr->left = ptr->right = NULL;
	ptr->data = x;

	return ptr;
}

template <typename Comparable>
void BST<Comparable>::insertNode(node<Comparable>* current, node<Comparable>* toInsert)
{
	if (current == nullptr)
	{
		current = toInsert;
	}
	else
	{
		if ((current->data) < (toInsert->data))
			current->right = toInsert;
		else
			current->left = toInsert;
	}
}

template <typename Comparable>
Comparable BST<Comparable>::getItem(int key)
{
	Comparable c;

	return c;
}

template <typename Comparable>
void BST<Comparable>::deletePreOrder(node<Comparable>* root)
{
	// pointer to store parent node of current node
	node<Comparable>* parent = nullptr;

	// start with root node
	node<Comparable>* curr = root;

	// search key in BST and set its parent pointer
	//searchKey(curr, key, parent);

	// return if key is not found in the tree
	if (curr == nullptr)
		return;

	// Case 1: node to be deleted has no children i.e. it is a leaf node
	if (curr->left == nullptr && curr->right == nullptr)
	{
		// if node to be deleted is not a root node, then set its
		// parent left/right child to null
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
			// if tree has only root node, delete it and set root to null
		else
			root = nullptr;

		// deallocate the memory
		delete curr ;
		//free(curr);  // or delete curr;
	}

		// Case 2: node to be deleted has two children
	else if (curr->left && curr->right)
	{
		// find its in-order successor node
		node<Comparable>* successor  = minimumKey(curr->right);

		// store successor value
		int val = successor->data;

		// recursively delete the successor. Note that the successor
		// will have at-most one child (right child)
		deleteNode(root, successor->data);

		// Copy the value of successor to current node
		curr->data = val;
	}

		// Case 3: node to be deleted has only one child
	else
	{
		// find child node
		node<Comparable>* child = (curr->left)? curr->left: curr->right;

		// if node to be deleted is not a root node, then set its parent
		// to its child
		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

			// if node to be deleted is root node, then set the root to child
		else
			root = child;

		// deallocate the memory
		delete curr ;
		//free(curr);
	}
}