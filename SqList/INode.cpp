/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <stdexcept>
#include <sstream>

#include "INode.h"
#include "DNode.h"
#include "Int341.h"
using namespace std;

INode::INode() {
    m_dNode = NULL;
    m_dNode_cnt = 0;
}

INode::INode(Int341 data) {

    m_dNode = new DNode(data);
    m_dNode_cnt = 1;
}

INode::INode(DNode *node) {
    m_dNode = node;
    m_dNode_cnt = 1;
}

INode::~INode() {

}

int INode::numItems() {
    return m_dNode_cnt;
}

void INode::setSize(int size) {
    m_dNode_cnt = size;
}

void INode::add(const Int341& data) {

    DNode *newNode = new DNode(data);
    DNode *firstNode = m_dNode;
    DNode *lastNode = numItems() > 1 ? findAt(numItems() - 1) : m_dNode;

    if (numItems() == 0) // insert it as first node 
    {
        m_dNode = newNode;
        m_dNode->m_next = NULL;


    } else if (newNode->m_data <= firstNode->m_data) { // first node is greater than newnode , then insert at 0 

        newNode->m_next = m_dNode;
        m_dNode = newNode;
    } else if (newNode->m_data >= lastNode->m_data) // last node is smaller than newnode , then insert at last 
    {
        newNode->m_next = lastNode->m_next;
        lastNode->m_next = newNode;

    } else {

        DNode *tempNode = m_dNode;
        while (tempNode->m_next != NULL &&
                tempNode->m_next->m_data <= newNode->m_data) {

            tempNode = tempNode->m_next;
        }
        if (tempNode->m_next != NULL)
            newNode->m_next = tempNode->m_next;
        tempNode->m_next = newNode;
    }

    m_dNode_cnt++;
}

Int341 INode::remove(const Int341& data) {

    int idx = indexOf(data);

    if (idx == -1) {
        throw out_of_range("INode:93 - Error : Not found");
    } else {
        return (removeAt(idx));
    }
}

Int341 INode::removeAt(int pos) {
    //      cout<<" INode.removeAt = "<<pos<<endl ;

     if (numItems() == 0) {
        throw overflow_error("INode:116- Error : INode is Empty");
     }
        
    if (pos < 0 || pos >= numItems()) {
          string error = "";
        stringstream error_message(error);
        error_message << "INode:104 - Error : pos {'" << pos << "'} is not valid ";
        throw out_of_range(error_message.str());
        
           
    }

    DNode* previousNode = NULL;
    DNode* foundNode = NULL;

    Int341 result;
   
    if (pos == 0) { // first position 

        previousNode = m_dNode->m_next;
        result = m_dNode->m_data;

         
         
        
        delete m_dNode;
        m_dNode = previousNode;
        m_dNode_cnt--;

    } else {

        previousNode = findAt(pos - 1);

        DNode* deleteNode = previousNode->m_next;
        result = m_dNode->m_data;
        previousNode->m_next = NULL;

        if (deleteNode->m_next != NULL)
            previousNode->m_next = deleteNode->m_next;

         cout<<pos<<" -- "<<deleteNode->m_data.m_data <<endl ;;
        
        delete deleteNode;
        m_dNode_cnt--;

    }

    cout<<"-- "<<result.m_data ;;
    return result;
}

int INode::indexOf(const Int341 & data) {

    int idx = 0;
    bool found = false;
    int totCnt = numItems();

    DNode* current = m_dNode; // Initialize current

    while (current != NULL && idx < totCnt) {

        if (current->m_data == data) {
            found = true;
            break;
        }
        current = current->m_next;
        idx++;
    }

    if (found) {
        return idx;
    } else {
        return -1;
    }
}

Int341 & INode::findAtPos(int pos) {
    DNode* node = findAt(pos);
    if (node != NULL)
        return (node->m_data);
}

DNode* INode::findAt(int pos) {
    // if size is empty

    DNode* foundNode = NULL;

    if ( numItems() == 0) {        
        throw overflow_error("INode:173 - Error : iNode is Empty");
        
    } else if (pos < 0 || pos >= numItems()) {
        
        string error = "";
        stringstream error_message(error);
        error_message << "INode:177 - Error : pos {'" << pos << "'} is not valid ";
        throw out_of_range(error_message.str());

    } else if (pos == 0) {
        
        foundNode = m_dNode;
        
    } else {
        DNode *temp = m_dNode->m_next;
        //store previous of to be deleted node
        for (int i = 1; temp != NULL && i < pos; i++) {
            temp = temp->m_next;
        }
        if (temp == NULL) {
            throw out_of_range("INode:183 - Error : data not found");
        }
        foundNode = temp;
    }
   
    
    return foundNode;
}

void INode::dump() {
    cout << "(" << numItems() << ") : ";

    DNode *temp = m_dNode;
    int elementsCnt = 0;
    int idx = 0 ;
    while (temp != NULL && elementsCnt++ < numItems()) {
        cout <<idx<<"-"<<temp->m_data.m_data << " ";
        temp = temp->m_next;
        idx++ ;
    }
    cout << endl;
}