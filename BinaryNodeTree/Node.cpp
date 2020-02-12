/*
*@author: Amirah Abdullah
*@filename: Node.cpp
*@date: 09/21/2018
*@due date: 09/28/2018
*@description: Node.cpp is the implementation of the node.hpp methods. This means they contain
*pre and post conditions. The linked list will in turn use the node.cpp class
*/
#include "Node.h"
#include <iostream>


template <typename T>
Node<T>::Node(T value, Node<T>* next_node) {
  m_value = value;
  m_next = next_node;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
  return m_next;
}

template <typename T>
T& Node<T>::getValue() {
  return m_value;
}

template <typename T>
void Node<T>::setNext(Node<T>* next) {
  m_next = next;
}

template <typename T>
void Node<T>::setValue(T value) {
  m_value = value;
}
