/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SqList.h
 * Author: oracle
 *
 * Created on March 7, 2018, 10:07 PM
 */

#ifndef SQLIST_H
#define SQLIST_H

#include "INode.h"
#include "Int341.h"
#include <list>

using namespace std;

class SqList {
private:
    list<INode> m_iList;

public:
    SqList();
    ~SqList();
    SqList(const SqList& other);
    const SqList& operator=(const SqList& rhs);
    void add(const Int341& data);
    Int341 remove(const Int341& data);
    Int341 removeAt(int pos);
    Int341& operator[](int pos);
    int indexOf(const Int341& data);
    int numItems();
    void dump();
    void consolidate();
    void inspector();
};

#endif /* SQLIST_H */

