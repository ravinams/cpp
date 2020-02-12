#include "ProbeHashTable.h"
#include<iostream>
#include<stdexcept>

using namespace std;

template <typename T>
ProbeHashTable<T>::ProbeHashTable(unsigned int (*hashFunc)(const T&), int n) {

    this->hashFunc = hashFunc;
    this->m_size = n;
    this->m_total_items = 0;
    this->m_table = new HashTableEntry[m_size];

    for (int i = 0; i < m_size; i++) {
        m_table[i].m_flag = 0;
    }

}

template <typename T>
void ProbeHashTable<T>::dump() {
    cout << "ProbeHashTable dump; size:" << m_size << " buckets" << endl;
    for (int i = 0; i < m_size; i++) {
        cout << "[" << i << "] :";
        if (m_table[i].m_flag == 0)
            cout << "EMPTY";
        else if (m_table[i].m_flag == -1)
            cout << "DELETED";
        else if (m_table[i].m_flag == 1)
            cout << m_table[i].m_data << " (" << getHashCode(m_table[i].m_data) << ")";
        cout << endl;
    }
    cout << "Total items: " << m_total_items << endl;

}

template <typename T>
ProbeHashTable<T>::ProbeHashTable(ProbeHashTable& other) {

    this->hashFunc = other.hashFunc;
    m_size = other.m_size;
    m_total_items = other.m_total_items;

    delete[] m_table;
    m_table = new HashTableEntry[m_size];

    std::copy(other.m_table, other.m_table + m_size, m_table);

}

template <typename T>
const ProbeHashTable<T>& ProbeHashTable<T>::operator=(ProbeHashTable& rhs) {
    if (this != rhs) {
        if (m_size < rhs.m_size) {
            m_size = rhs.m_size;
        }

        m_total_items = rhs.m_total_items;
        this->hashFunc = rhs.hashFunc;

        delete[] m_table;
        m_table = new HashTableEntry[m_size];

        std::copy(rhs.m_table, rhs.m_table + m_size, m_table);

    }

    return *this;
}

template <typename T>
bool ProbeHashTable<T>::insert(const T &data) {

    bool dataInserted = false;
    int dataInsertionLocation = -1;
    int hashIndex = getHashCode(data);

    if (m_table[hashIndex].m_flag == 0 || m_table[hashIndex].m_flag == -1) // No collission 
    {
        dataInsertionLocation = hashIndex;
    } else {

        // Linear probing till the end , finding next empty location to insert new data
        int nextFreeIndex = 0;
        for (nextFreeIndex = hashIndex + 1; nextFreeIndex < m_size; nextFreeIndex++) {
            if (m_table[nextFreeIndex].m_flag == 0 || m_table[nextFreeIndex].m_flag == -1) {
                dataInsertionLocation = nextFreeIndex;
                break;
            }
        }

        // Linear probing till from the start , finding next empty location to insert new data .
        if (dataInsertionLocation == -1 && hashIndex > 0) // wrap case 
        {
            int wrapNextFreeIndex = 0;
            for (wrapNextFreeIndex = 0; wrapNextFreeIndex < hashIndex; wrapNextFreeIndex++) {
                if (m_table[wrapNextFreeIndex].m_flag == 0 || m_table[wrapNextFreeIndex].m_flag == -1) {
                    dataInsertionLocation = wrapNextFreeIndex;
                    break;
                }
            }
        }
    }

    if (dataInsertionLocation != -1) {
        m_table[dataInsertionLocation].m_flag = 1;
        m_table[dataInsertionLocation].m_data = data;
        m_total_items++;
        dataInserted = true;
    }

    return dataInserted;

}

template <typename T>
bool ProbeHashTable<T>::find(const T &data) {

    int location = findLocaton(data);

    if (location != -1)
        return true;
    else
        return false;
}

template <typename T>
T ProbeHashTable<T>::remove(const T &data, bool &found) {

    found = false;
    int location = findLocaton(data);
    T deletedData;

    if (location != -1) {
        m_table[location].m_flag = -1;
        m_total_items--;
        found = true;
        deletedData = m_table[location].m_data;
    }

    return deletedData;
}

template <typename T>
int ProbeHashTable<T>::at(int index, std::vector<T> &contents) {

    if ( !( index >= 0 && index < m_size ) ) 
        throw std::out_of_range(" Index is out of range ");

    if (m_table[index].m_flag == 1)
        contents.push_back(m_table[index].m_data);

}

template <typename T>
int ProbeHashTable<T>::getHashCode(const T &data) {
    return ( this->hashFunc(data) % m_size);
}

template <typename T>
int ProbeHashTable<T>::findLocaton(const T &data) {

    int dataLocation = -1;
    int hashIndex = getHashCode(data);

    if (m_table[hashIndex].m_data == data && m_table[hashIndex].m_flag == 1) {
        dataLocation = hashIndex;
    } else {

        //Linear probing till the end of HashTable
        int nextHashIndex = hashIndex + 1;
        while (nextHashIndex < m_size) {
            if (m_table[nextHashIndex].m_flag == 1 && m_table[nextHashIndex].m_data == data) {
                dataLocation = nextHashIndex;
                break;
            }

            nextHashIndex++;
        }

        //Linear probing from the start of HasTable 
        if (dataLocation == -1 && hashIndex > 0) // wrap case 
        {            
            int wrappedNextHashIndex = 0;
            while (wrappedNextHashIndex < hashIndex) {
                if ( m_table[wrappedNextHashIndex].m_data == data &&  m_table[wrappedNextHashIndex].m_flag == 1 ) {
                    dataLocation = wrappedNextHashIndex;
                    break;
                }
                wrappedNextHashIndex++;
            }
        }

    }

    return dataLocation;

}

template <typename T>
ProbeHashTable<T>::~ProbeHashTable() {
    delete[] m_table;
}
