/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:    November 10, 2018
 * @Email:  amirah.ghada@ku.edu
 * @Filename: LinkedStack.h
 * @Last modified by:   amirah
 *
 */
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
/** ADT stack: Link-based implementation.
  @file LinkedStack.h */
#ifndef _LINKED_STACK
#define _LINKED_STACK
#include "Node.h"
#include "StackInterface.h"
#include "PrecondViolatedExcep.h"
template <class ItemType>
class LinkedStack : public StackInterface<ItemType> {
private:
  Node<ItemType>* topPtr;  // Pointer to first node in the chain; // this node contains the stack’s top
public:
  // Constructors and destructor:
  LinkedStack();                                     // Default constructor
  LinkedStack(const LinkedStack<ItemType>& aStack);  // Copy constructor virtual ~LinkedStack();
  ~LinkedStack();                                    // Destructor
  // Stack operations:
  bool isEmpty() const;
  void push(const ItemType& newItem) throw(PrecondViolatedExcep);
  void pop() throw(PrecondViolatedExcep);
  ItemType peek() const throw(PrecondViolatedExcep) ;
};  // end LinkedStack
//#include "LinkedStack.cpp"
#endif
