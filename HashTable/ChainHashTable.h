/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChainHashTable.h
 * Author: oracle
 *
 * Created on May 12, 2018, 12:55 AM
 */

#ifndef CHAINHASHTABLE_H
#define CHAINHASHTABLE_H

#include "HashTable.h"
#include <list>

template <typename T>
class ChainHashTable : public HashTable<T> {
    
public:

    ChainHashTable(unsigned int (*hashFunc)(const T&), int n = 101);
    virtual ~ChainHashTable();
    ChainHashTable(ChainHashTable& other);
    const ChainHashTable& operator=(ChainHashTable& rhs);
    virtual bool insert(const T &data);
    virtual bool find(const T &data);
    virtual T remove(const T &data, bool &found);
    virtual void dump();
    virtual int at(int index, std::vector<T> &contents);

private:

    int m_size; // no if buckets 
    int m_total_items; // no of items in those buckets
    std::list<T> *m_table;
    // This implements hash function to find index to store value
    int getHashCode(const T &data) ;
    int findLocation(const T &data) ;
    
};

#include "ChainHashTable.cpp"
#endif /* CHAINHASHTABLE_H */

