#ifndef BST_H
#define BST_H

#include <string>		
#include <iostream>
using namespace std;

class Node
{
	friend class BST;
public:
	Node(): data(0), rlink(nullptr), llink(nullptr) {}
	~Node(){}
private:
    int data;
    Node *rlink, *llink;
};

class BST
{
public:

	BST();
        
        ~BST();   
	
	void insert(int item); 
	
        void destroyTree();
        
	void inorderTraversal() const;
        

	// Declaration function insert (non-recursive) 
	// Inserts element in the BST
	
	// Declaration function totalNodes
	// Returns the number of nodes in the BST

         int totalNodes() ;
         
	// Declaration overloaded function preorderTraversal
	// Print all nodes in the BST in a preorder sequence

          void preorderTraversal() const;
          
	// Declaration overloaded function postorderTraversal
	// Print all nodes in the BST in a postorder sequence
                       
         void postorderTraversal() const;
        
       

			
private:	
    
	Node *root; //Pointer to the root

	void insert(Node* &p, Node *newNode);

	void destroyTree(Node* &p);
	
	void inorderTraversal(const Node* p) const;
        
       

	// Declaration overloaded function totalNodes (recursive)
         int totalNodes(Node* &p) ;
	// Declaration overloaded function preorderTraversal (recursive)
         void preorderTraversal(const Node* p) const;
	// Declaration overloaded function postorderTraversal (recursive)
         void postorderTraversal(const Node* p) const;
      
         
       
        
       
        
       
	
};

#endif