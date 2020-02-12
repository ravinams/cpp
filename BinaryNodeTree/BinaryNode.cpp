/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:   November 12, 2018  10:12pm
 * @Email:  amirah.ghada@ku.edu
 * @Filename: BinaryNode.cpp
 * @Last modified by:   amirah
 *
 */
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
/** ADT stack: Link-based implementation.
  @file LinkedStack.h */
#include "BinaryNode.h"
//#include <iostream>
//#include <string>


template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) {
  item = anItem;
  leftChildPtr = nullptr;
  rightChildPtr = nullptr;
}

template <class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, BinaryNode<ItemType>* leftPtr,
                                 BinaryNode<ItemType>* rightPtr) {
  item = anItem;
  leftChildPtr = leftPtr;
  rightChildPtr = rightPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

template <class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return item;
}

template <class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  return leftChildPtr == nullptr || rightChildPtr == nullptr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const {
  return leftChildPtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const {
  return rightChildPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr) {
  leftChildPtr = leftPtr;
}

template <class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr) {
  rightChildPtr = rightPtr;
}


