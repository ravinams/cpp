/* BST.h contains the declaration of class template BST.
Basic operations:
Constructor: Constructs an empty BST
empty:       Checks if a BST is empty
search:      Search a BST for an item
insert:      Inserts a value into a BST
remove:      Removes a value from a BST
inorder:     Inorder traversal of a BST -- output the data values
graph:       Output a grapical representation of a BST
Private utility helper operations:
search2:     Used by delete
inorderAux:  Used by inorder
graphAux:    Used by graph
Other operations described in the exercises:
destructor
copy constructor
assignment operator
preorder, postorder, and level-by-level traversals
level finder
Note: Execution terminates if memory isn't available for a new BST node.
---------------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename DataType>
class BST
{
private:
	/***** Node class *****/
	class BinNode
	{
	public:
		DataType data;
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default DataType value; both links are null.
		BinNode()
			: left(nullptr), right(nullptr)
		{}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(DataType item)
			: data(item), left(nullptr), right(nullptr)
		{}

	};// end of class BinNode declaration
public:
	typedef BinNode * BinNodePointer;
	/***** Function Members *****/
	BST();
	/*------------------------------------------------------------------------
	Construct a BST object.

	Precondition:  None.
	Postcondition: An empty BST has been constructed.
	-----------------------------------------------------------------------*/
	~BST();
	/*------------------------------------------------------------------------
	Destruct a BST object.

	Precondition:  None.
	Postcondition: All nodes are de-allocated.
	-----------------------------------------------------------------------*/
	BST(const BST<DataType> & origList);
	/*------------------------------------------------------------------------
	Copy constructor.

	Precondition:  None.
	Postcondition: the origList is copied.
	-----------------------------------------------------------------------*/
	const BST<DataType> & operator=(const BST<DataType> & rightHandSide);
	/*------------------------------------------------------------------------
	Assignment Operator.

	Precondition:  None.
	Postcondition: the rightHandSide is copied to the left.
	-----------------------------------------------------------------------*/
	bool empty() const;
	/*------------------------------------------------------------------------
	Check if BST is empty.

	Precondition:  None.
	Postcondition: Returns true if BST is empty and false otherwise.
	-----------------------------------------------------------------------*/

	bool search(const DataType & item) const;
	/*------------------------------------------------------------------------
	Search the BST for item.

	Precondition:  None.
	Postcondition: Returns true if item found, and false otherwise.
	-----------------------------------------------------------------------*/

	void insert(const DataType & item);
	/*------------------------------------------------------------------------
	Insert item into BST.

	Precondition:  None.
	Postcondition: BST has been modified with item inserted at proper
	position to maintain BST property.
	------------------------------------------------------------------------*/

	void remove(const DataType & item);
	/*------------------------------------------------------------------------
	Remove item from BST.

	Precondition:  None.
	Postcondition: BST has been modified with item removed (if present);
	BST property is maintained.
	Note: remove uses auxiliary function search2() to locate the node
	containing item and its parent.
	------------------------------------------------------------------------*/

	void inorder(std::ostream & out) const;
	/*------------------------------------------------------------------------
	Inorder traversal of BST.

	Precondition:  ostream out is open.
	Postcondition: BST has been inorder traversed and values in nodes
	have been output to out.
	Note: inorder uses private auxiliary function inorderAux().
	------------------------------------------------------------------------*/

	void graph(std::ostream & out) const;
	/*------------------------------------------------------------------------
	Graphic output of BST.

	Precondition:  ostream out is open.
	Postcondition: Graphical representation of BST has been output to out.
	Note: graph() uses private auxiliary function graphAux().
	------------------------------------------------------------------------*/

	bool isExactlyEqual(const BST<DataType> & treeToCompare) const;
	/*------------------------------------------------------------------------
	compares the treeToCompare with this object and return true if trees are
	exactly the same.

	Precondition:  treeToCompare is a BST object.
	Postcondition: returns true if trees are exactly the same
	------------------------------------------------------------------------*/

	unsigned countNodes() const;
	/*------------------------------------------------------------------------
	Count number of nodes in a tree.

	Precondition:  subtreePtr points to a subtree of this BST.
	Postcondition: returns the number of nodes in a binary search tree
	------------------------------------------------------------------------*/

	int indexSearch(const DataType & item) const;
	/*------------------------------------------------------------------------
	compares the treeToCompare with this object and return true if trees are
	exactly the same.

	Precondition:  item is a DataType contained in the tree
	Postcondition: returns the index number that correspondes to an array
	storage where the root is 0 and index increments from left to right
	moving down the tree.
	------------------------------------------------------------------------*/

private:

	/***** Private Function Members *****/
	void search2(const DataType & item, bool & found, BinNodePointer & locptr, BinNodePointer & parent) const;
	/*------------------------------------------------------------------------
	Locate a node containing item and its parent.

	Precondition:  None.
	Postcondition: locptr points to node containing item or is null if
	not found, and parent points to its parent.#include <iostream>
	------------------------------------------------------------------------*/

	void inorderAux(std::ostream & out, BinNodePointer subtreePtr) const;
	/*------------------------------------------------------------------------
	Inorder traversal auxiliary function.

	Precondition:  ostream out is open; subtreePtr points to a subtree
	of this BST.
	Postcondition: Subtree with root pointed to by subtreePtr has been
	output to out.
	------------------------------------------------------------------------*/

	void graphAux(std::ostream & out, int indent, BinNodePointer subtreeRoot) const;
	/*------------------------------------------------------------------------
	Graph auxiliary function.

	Precondition:  ostream out is open; subtreePtr points to a subtree
	of this BST.
	Postcondition: Graphical representation of subtree with root pointed
	to by subtreePtr has been output to out, indented indent spaces.
	------------------------------------------------------------------------*/

	bool isExactlyEqualAux(const BinNodePointer myTree, const BinNodePointer treeToCompare) const;
	/*------------------------------------------------------------------------
	Returns true if trees are exactly equal

	Precondition:  myTree and treeToCompare are BST's.
	Postcondition: returns true if trees are exactly equal
	------------------------------------------------------------------------*/

	unsigned countNodesAux(BinNodePointer subtreeRoot) const;
	/*------------------------------------------------------------------------
	Recursive function that count number of nodes in a tree aux.

	Precondition:  subtreePtr points to a subtree of this BST.
	Postcondition: returns the number of nodes in the binary search tree
	------------------------------------------------------------------------*/

	void destructAux(BinNodePointer subtreeRoot);
	/*------------------------------------------------------------------------
	Recursive function that deallocates the nodes in subtreeRoot.

	Precondition:  subtreePtr points to a subtree of this BST.
	Postcondition: noes are deallocated.
	------------------------------------------------------------------------*/

	void copyAux(const BinNodePointer subtreeRoot);
	/*------------------------------------------------------------------------
	Recursive function that copies subtreeRoot to myRoot and allocates the appropriate
	nodes.

	Precondition:  subtreePtr points to a subtree of this BST.
	Postcondition: creates the treeToBuild by copying the subtreeRoot.
	------------------------------------------------------------------------*/
  
    void copyInOrder(BinNodePointer orgTree, BinNodePointer & copyTree) ;
  
	/***** Data Members *****/
	BinNodePointer myRoot;

}; // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline BST<DataType>::BST()
	: myRoot(nullptr)
{}

template <typename DataType>
BST<DataType>::~BST()
{
	destructAux(myRoot);
}

template <typename DataType>
BST<DataType>::BST(const BST<DataType> & origList) : myRoot(nullptr)
{
	copyAux(origList.myRoot);
}

//--- Definition of empty()
template <typename DataType>
inline bool BST<DataType>::empty() const
{
	return myRoot == nullptr;
}

//--- Definition of search()
template <typename DataType>
bool BST<DataType>::search(const DataType & item) const
{
	BinNodePointer locptr = myRoot;
	bool found = false;
	while (!found && locptr != nullptr)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	return found;
}

//--- Definition of insert()
template <typename DataType>
inline void BST<DataType>::insert(const DataType & item)
{
	BinNodePointer	locptr = myRoot, parent = nullptr;      // pointer to parent of current node
	bool found = false;    // indicates if item already in BST
	while (!found && locptr != nullptr)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{ // construct node containing item
		locptr = new BinNode(item);
		if (parent == nullptr)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
		std::cout << "Item already in the tree\n";
}

//--- Definition of remove()
template <typename DataType>
void BST<DataType>::remove(const DataType & item)
{
	bool found;                      // signals if item is found
	BinNodePointer x, parent;        // points to node to be deleted
	//    "    " parent of x and xSucc
	search2(item, found, x, parent);

	if (!found)
	{
		std::cout << "Item not in the BST\n";
		return;
	}
	//else
	if (x->left != nullptr && x->right != nullptr)
	{                                // node has 2 children
		// Find x's inorder successor and its parent
		BinNodePointer xSucc = x->right;
		parent = x;
		while (xSucc->left != nullptr)       // descend left
		{
			parent = xSucc;
			xSucc = xSucc->left;
		}

		// Move contents of xSucc to x and change x 
		// to point to successor, which will be removed.
		x->data = xSucc->data;
		x = xSucc;
	} // end if node has 2 children

	// Now proceed with case where node has 0 or 2 child
	BinNodePointer
		subtree = x->left;             // pointer to a subtree of x
	if (subtree == nullptr)
		subtree = x->right;
	if (parent == nullptr)                  // root being removed
		myRoot = subtree;
	else if (parent->left == x)       // left child of parent
		parent->left = subtree;
	else                              // right child of parent
		parent->right = subtree;
	delete x;
}

//--- Definition of inorder()
template <typename DataType>
inline void BST<DataType>::inorder(std::ostream & out) const
{
	inorderAux(out, myRoot);
}

//--- Definition of graph()
template <typename DataType>
inline void BST<DataType>::graph(std::ostream & out) const
{
	graphAux(out, 0, myRoot);
}

//--- Definition of search2()
template <typename DataType>
void BST<DataType>::search2(const DataType & item, bool & found, BinNodePointer & locptr, BinNodePointer & parent) const
{
	locptr = myRoot;
	parent = nullptr;
	found = false;
	while (!found && locptr != nullptr)
	{
		if (item < locptr->data)       // descend left
		{
			parent = locptr;
			locptr = locptr->left;
		}
		else if (locptr->data < item)  // descend right
		{
			parent = locptr;
			locptr = locptr->right;
		}
		else                           // item found
			found = true;
	}
}

//--- Definition of inorderAux()
template <typename DataType>
void BST<DataType>::inorderAux(std::ostream & out, BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != nullptr)
	{
		inorderAux(out, subtreeRoot->left);    // L operation
		out << subtreeRoot->data << "  ";      // V operation
		inorderAux(out, subtreeRoot->right);   // R operation
	}
}

//--- Definition of graphAux()
#include <iomanip>

template <typename DataType>
void BST<DataType>::graphAux(std::ostream & out, int indent, BinNodePointer subtreeRoot) const
{
	if (subtreeRoot != nullptr)
	{
		graphAux(out, indent + 8, subtreeRoot->right);
		out << std::setw(indent) << " " << subtreeRoot->data << std::endl;
		graphAux(out, indent + 8, subtreeRoot->left);
	}
}

template <typename DataType>
bool BST<DataType>::isExactlyEqual(const BST<DataType> & treeToCompare) const
{
	if (countNodes() == treeToCompare.countNodes())
	   return isExactlyEqualAux(myRoot, treeToCompare.myRoot);
	 else
	   return false ;
}

template <typename DataType>
bool BST<DataType>::isExactlyEqualAux(const BinNodePointer myTree, const BinNodePointer treeToCompare) const
{

	
	 /*1. both empty */
    if (myTree==NULL && treeToCompare==NULL) 
         return true ;
    /* 2. both non-empty -> compare them */
     else if (myTree !=NULL && treeToCompare!=NULL)
         {
                  return ( myTree->data == treeToCompare->data && 
            isExactlyEqualAux(myTree->left, treeToCompare->left) && 
            isExactlyEqualAux(myTree->right, treeToCompare->right) ) ;
         }
     else /* 3. one empty, one not -> false */
        return false ;
        
// 	bool rv  = false;        
// 	if ((myTree == nullptr) && (treeToCompare == nullptr))
// 		return true;
// 	if ((myTree == nullptr) && (treeToCompare != nullptr))
// 		return false;
// 	if ((myTree != nullptr) && (treeToCompare == nullptr))
// 		return false;
// 	if ((myTree->data != treeToCompare->data))
// 		return false;
// 	rv = isExactlyEqualAux(myTree->left, treeToCompare->left);
// 	if (rv == false)
// 		return false;
// 	rv = isExactlyEqualAux(myTree->right, treeToCompare->right);
//	return rv;
}

template <typename DataType>
unsigned BST<DataType>::countNodes() const
{
	return countNodesAux(myRoot);
}

template <typename DataType>
unsigned BST<DataType>::countNodesAux(BinNodePointer subtreeRoot) const
{
	if (subtreeRoot == nullptr)
	   return 0;
	else 
	   return 1+countNodesAux(subtreeRoot->left)+countNodesAux(subtreeRoot->right) ;
}

template <typename DataType>
int BST<DataType>::indexSearch(const DataType & item) const
{
	 int index =  0 ; 
	 if (myRoot == nullptr || !search(item))
	    return -1 ;
         else if (myRoot->data == item)
            return 0 ;
	 else
	  { 
	     BinNodePointer current = 	myRoot ;
	    
	     while(current != nullptr)
	     {
	        	         
	         if (item  == current->data  )
	              {
                        
                          return index ;
	              }
	         else if ( item <  current->data && current->left !=nullptr   )
	             {
	               index  = index * 2 +1 ;
	               current = current->left ;
	             }
	         else if ( item >  current->data && current->right !=nullptr )
	              {
	               index  = index * 2 + 2 ;
	               current = current->right ;
	              }
	     }
	    
	  }
	return -1 ;
}

template <typename DataType>
void BST<DataType>::copyAux(const BinNodePointer treeToCopy)
{
   if (treeToCopy != nullptr)
   {
      BinNodePointer newNode = new BinNode() ;
      newNode->data = treeToCopy->data ;
      
       if (myRoot == nullptr)
            myRoot = newNode ;
            
       copyInOrder(treeToCopy,myRoot) ;
           
   }
}

template <typename DataType>
void BST<DataType>::copyInOrder(BinNodePointer orgTree, BinNodePointer & copyTree){
    if(orgTree !=nullptr){
        //left side
        if (orgTree->left !=nullptr)
        {
        BinNodePointer newLeftNode = new BinNode(orgTree->left->data);
        copyTree->left = newLeftNode;
        copyInOrder(orgTree->left, copyTree->left);
        }

        //right side
        if (orgTree->right !=nullptr)
         {
        BinNodePointer newRightNode = new BinNode(orgTree->right->data);
        copyTree->right = newRightNode;
        copyInOrder(orgTree->right, copyTree->right);
         }
    }
}

template <typename DataType>
void BST<DataType>::destructAux(BinNodePointer subtreeRoot)
{
    if (subtreeRoot != nullptr)
    {
        destructAux(subtreeRoot->left) ;
        destructAux(subtreeRoot->right) ;
        
        if (subtreeRoot->left == nullptr && subtreeRoot->right == nullptr ) 
              delete subtreeRoot ;                       
    }

}

template <typename DataType>
const BST<DataType> & BST<DataType>::operator=(const BST<DataType> & rightHandSide)
{     
    if(this != &rightHandSide) 
       {         
         destructAux(myRoot) ;
         myRoot = nullptr ;    
         copyAux(rightHandSide.myRoot) ;
       }
	return *this;
}
#endif
