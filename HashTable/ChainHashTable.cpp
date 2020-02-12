#include "ChainHashTable.h"
#include<iostream>
#include<stdexcept>
#include <iterator>
#include<list>

using namespace std;

template <typename T>
ChainHashTable<T>::ChainHashTable(unsigned int (*hashFunc)(const T&), int n) {

    this->hashFunc = hashFunc;
    m_size = n;
    m_total_items = 0;
    m_table = new list<T>[m_size];
}

template <typename T>
void ChainHashTable<T>::dump() {
    cout << "ChainHashTable dump; size:" << m_size << " buckets" << endl;
    for (int i = 0; i < m_size; i++) {

        cout << "[" << i << "] :";

        typename std::list<T>::iterator lstIter;
        std::list<T> lst = m_table[i];

        for (lstIter = lst.begin(); lstIter != lst.end(); ++lstIter)
            cout << *lstIter << ",";

        cout << endl;
    }
    cout << "Total items: " << m_total_items << endl;

}

template <typename T>
ChainHashTable<T>::ChainHashTable(ChainHashTable& other) {

    this->hashFunc = other.hashFunc;
    m_size = other.m_size;
    m_total_items = other.m_total_items;

    delete[] m_table;
    m_table = new list<T>[m_size];

    for (int i = 0; i < m_size; i++) {
        m_table[i] = other.m_table[i];
    }

}

template <typename T>
const ChainHashTable<T>& ChainHashTable<T>::operator=(ChainHashTable& rhs) {
    if (this != rhs) {
        if (m_size < rhs.m_size) {
            m_size = rhs.m_size;
        }

        m_total_items = rhs.m_total_items;
        this->hashFunc = rhs.hashFunc;

        delete[] m_table;
        m_table = new list<T>[m_size];

        for (int i = 0; i < m_size; i++) {
            m_table[i] = rhs.m_table[i];
        }

    }

    return *this;
}

template <typename T>
bool ChainHashTable<T>::insert(const T &data) {

    int hashIndex = getHashCode(data);
    bool dataExists = false;
    
    dataExists = find(data) ;

    if (!dataExists) {
        m_table[hashIndex].push_front(data);
        m_total_items++;
    }

    return !dataExists;
}

template <typename T>
bool ChainHashTable<T>::find(const T &data) {

    int hashIndex = getHashCode(data);
    bool dataExists = false;

    // find the key in (inex)th list
    typename std::list<T>::iterator i;
    for (i = m_table[hashIndex].begin();
            i != m_table[hashIndex].end(); i++) {
        if (*i == data) {
            dataExists = true;
            break;
        }
    }

    return dataExists;
}

template <typename T>
T ChainHashTable<T>::remove(const T &data, bool &found) {

    int hashIndex = getHashCode(data);

    found = false;
    T item;

    // find the key in (inex)th list
    typename std::list<T>::iterator i;
    for (i = m_table[hashIndex].begin();
            i != m_table[hashIndex].end(); i++) {
        if (*i == data) {
            item = *i;
            found = true;
            m_table[hashIndex].erase(i);
            m_total_items--;
            break;
        }
    }

    return item;
}

template <typename T>
int ChainHashTable<T>::at(int index, std::vector<T> &contents) {

    if (index < 0 || index >= m_size) // out of range
        throw std::out_of_range(" Index is out of range");
  
    std::list<T> lst = m_table[index];
    copy(lst.begin(), lst.end(), back_inserter(contents));

}

template <typename T>
int ChainHashTable<T>::findLocation(const T &data) 
{
    int hashIndex = getHashCode(data);
    int location = -1  ;
     
     // find the key in (inex)th list
    typename std::list<T>::iterator i;
    for (i = m_table[hashIndex].begin(); i != m_table[hashIndex].end(); i++) {
        if (*i == data) {
           location = hashIndex ;
           break;
        }
    }
     
    return location ;    
}

template <typename T>
 int ChainHashTable<T>::getHashCode(const T &data) {
        return ( this->hashFunc(data) % m_size);
    }
 
template <typename T>
ChainHashTable<T>::~ChainHashTable() {
    delete[] m_table;
}
