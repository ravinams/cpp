/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   INode.h
 * Author: oracle
 *
 * Created on March 7, 2018, 10:07 PM
 */

#ifndef INODE_H
#define INODE_H

#include "DNode.h"

class INode
{
private :
    
    
     int m_dNode_cnt ;
     
public:
    
     DNode *m_dNode;
     
     INode() ;
     INode(Int341 data) ;
     INode(DNode *node) ;
    ~INode();
    
    void add(const Int341& data);
  
    
    Int341  remove(const Int341& data);
    Int341  removeAt(int pos);
    int indexOf(const Int341& data);
    DNode* findAt(int pos) ;
    Int341& findAtPos(int pos) ;
    int numItems() ;
    void setSize(int size) ;
    void dump() ; 
};

#endif /* INODE_H */

