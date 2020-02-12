/**
 * @Author: Amirah Abdullah <amirah>
 * @Date:   November 16, 2018  07:31am
 * @Email:  amirah.ghada@ku.edu
 * @Filename: node.h
 * @Last modified by:   amirah
 * @Last modified time: November 23, 2018  07:31am
 */
#pragma once

template <typename T>
class Node {
public:
  /*
      * @pre None
      * @post A Node is created to point to some other node
      */
  Node(T, Node<T>* = nullptr);

  /*
      * @pre None
      * @post None
      * @return  (with the pointer) address of stored value
      */
  T& getValue();

  /*
      * @pre None
      * @post None
      * @return Pointer to next node or nullptr
      */
  Node<T>* getNext() const;

  /*
      * @pre None
      * @post *m_next will be set to given node
      */
  void setNext(Node<T>*);

  /*
      * @pre None
      * @post m_value is set to given value
      */
  void setValue(T);

private:
  T m_value;
  Node<T>* m_next;
};
