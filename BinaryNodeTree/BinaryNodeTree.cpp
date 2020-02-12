/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:   November 22, 2018  10:11pm
 * @Email:  amirah.ghada@ku.edu
 * @Filename: BinaryNodeTree.cpp
 * @Last modified by:   amirah
 * @Last modified time: November 23, 2018  07:31am
 */
#include "BinaryNodeTree.h"
//#include "BinaryNode.h"
//#include "BinaryTreeInterface.h"
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
template <class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr) {
    return 0;
  }

  else {
     return 1 + getHeightHelper(subTreePtr->getLeftChildPtr())+ getHeightHelper(subTreePtr->getRightChildPtr()) ;
  }
}




template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodesHelper(BinaryNode<ItemType>* subTreePtr) const {
  if (subTreePtr == nullptr)

    return 0;

  else

    return (1 + getNumberOfNodesHelper(subTreePtr->getLeftChildPtr())

            + getNumberOfNodesHelper(subTreePtr->getRightChildPtr()));
}

// Recursively deletes all nodes from the tree.
template <class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(BinaryNode<ItemType>* subTreePtr) {
  if (subTreePtr->getLeftChildPtr() != nullptr) {
    destroyTree(subTreePtr->getLeftChildPtr());
  }
  if (subTreePtr->getRightChildPtr() != nullptr) {
    destroyTree(subTreePtr->getRightChildPtr());
  }
  if (subTreePtr != nullptr) {
    delete subTreePtr;
  }
}

// Copies the tree rooted at treePtr and returns a pointer to
// the copy.
template <class ItemType>
BinaryNode<ItemType>* BinaryNodeTree<ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
  BinaryNode<ItemType>* copy;
  if (treePtr == nullptr) {
    copy = nullptr;
  }
  else {
    copy = new BinaryNode<ItemType>(treePtr->getItem());
    if (treePtr->getLeftChildPtr() != nullptr) {
      BinaryNode<ItemType>* lChild = copyTree(treePtr->getLeftChildPtr());
      copy->setLeftChildPtr(lChild);
    }
    if (treePtr->getRightChildPtr() != nullptr) {
      BinaryNode<ItemType>* rChild = copyTree(treePtr->getRightChildPtr());
      copy->setRightChildPtr(rChild);
    }
  }
  return copy;
}

// Recursive traversal helper methods:
template <class ItemType>
void BinaryNodeTree<ItemType>::preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    ItemType next = treePtr->getItem();
    visit(next);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    ItemType next = treePtr->getItem();
    visit(next);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const {
  if (treePtr != nullptr) {
    ItemType next = treePtr->getItem();
    visit(next);
    preorder(visit, treePtr->getLeftChildPtr());
    preorder(visit, treePtr->getRightChildPtr());
  }
}

//public; Constructor and Destructor Methods
//template <class ItemType>
//BinaryNodeTree<ItemType>::BinaryNodeTree() {}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem) {
  rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);  //constructor
}

template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem, const BinaryNodeTree<ItemType>* leftTreePtr,
                                         const BinaryNodeTree<ItemType>* rightTreePtr) {
   rootPtr = new BinaryNode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
   //this method is the copy contrustor
}
template <class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const BinaryNodeTree<ItemType>& tree) {
  rootPtr = copyTree(tree.rootPtr);  //copy constructor
}

 template <class ItemType>  //virtual destructor
 BinaryNodeTree<ItemType>::~BinaryNodeTree() {
 destroyTree(rootPtr);  //delete the root pointer
}

//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//other public methods
template <class ItemType>
bool BinaryNodeTree<ItemType>::isEmpty() const {
  if (rootPtr != nullptr) {
    return false;
  }
  return true;
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getHeight() const {
  return getHeightHelper(rootPtr);
}

template <class ItemType>
int BinaryNodeTree<ItemType>::getNumberOfNodes() const {
  return getNumberOfNodesHelper();
}

template <class ItemType>
ItemType BinaryNodeTree<ItemType>::getRootData() const throw(PrecondViolatedExcep) {
  if (rootPtr == nullptr) {
    throw PrecondViolatedExcep("Empty root pointer!\n");
  }
  return rootPtr->getItem();
}

template <class ItemType>
void BinaryNodeTree<ItemType>::setRootData(const ItemType& newData) {
  if (isEmpty()) {
    rootPtr = new BinaryNode<ItemType>(newData, 0, 0);
  }
  else {
    rootPtr->setItem(newData);
  }
}

template <class ItemType>
void BinaryNodeTree<ItemType>::clear() {
  destroyTree(rootPtr);
  rootPtr = 0;
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template <class ItemType>
void BinaryNodeTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
  preorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
  inorder(visit, rootPtr);
}

template <class ItemType>
void BinaryNodeTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
  postorder(visit, rootPtr);
}

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
template <class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType>& rightHandSide) {
  if (!isEmpty()) {
    clear();
    this = copyTree(&rightHandSide);
  }
  return *this ;
}

