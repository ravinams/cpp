#ifndef PROBEHASHTABLE_H
#define PROBEHASHTABLE_H

#include "HashTable.h"

template <typename T>
class ProbeHashTable : public HashTable<T> {

   private:

        // This implements hash function to find index to store value
        int getHashCode(const T &data) ;
        // this function returns the location of Element in ProbeHashTable, -1 if not found
        int findLocaton(const T &data) ;

        /* m_flag ; EMPTY = 0 , DELETE = -1 , VALUE = 1  */ 
        class HashTableEntry {
         public:
             int m_flag; 
             T m_data;
         };
         HashTableEntry *m_table;
         int m_size; // no of buckets
         int m_total_items; // total no .of items in those buckets  
    
    public:

        ProbeHashTable(unsigned int (*hashFunc)(const T&), int n = 101);   
        ProbeHashTable(ProbeHashTable& other);
        const ProbeHashTable& operator=(ProbeHashTable& rhs);
        virtual bool insert(const T &data);
        virtual T remove(const T &data, bool &found);
        virtual bool find(const T &data);
        virtual int at(int index, std::vector<T> &contents);
        virtual void dump();
        virtual ~ProbeHashTable();
    
};

#include "ProbeHashTable.cpp"
#endif /* PROBEHASHTABLE_H */

