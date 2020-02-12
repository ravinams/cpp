/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SSLColumn.h
 * Author: oracle
 *
 * Created on February 14, 2018, 9:44 AM
 */

#ifndef _SSLCOLUMN_H_
#define _SSLCOLUMN_H_

class SSLColumn {
public:



    // Constructor, default size is 2
    SSLColumn(int n = 2);

    // Copy constructor
    // Makes exact copy, including relative positions in circular buffers
    SSLColumn(const SSLColumn& other);

    // Destructor
    ~SSLColumn();

    // overloaded assignment operator
    // We can copy into differently-sized array.  Copying done in-place if
    // target has sufficient capacity; else, target's internal array
    // will be reallocated to a larger size.
    const SSLColumn& operator=(const SSLColumn& rhs);

    // Adds item to correct sorted order position in circular buffer.
    // Throws exception if out of room.
    // REQUIREMENT: must execute in O(n) time, where n is size of column
    void add(int data);

    // Adds item to top/left of circular buffer.
    // Throws exception if out of room.
    // REQUIREMENT: must execute in O(1) time
    void addFirst(int data);

    // Adds item to bottom/right of circular buffer.
    // Throws exception if out of room.
    // REQUIREMENT: must execute in O(1) time
    void addLast(int data);

    // returns position of item in column, -1 if not found.
    // REQUIREMENT: must execute in O(log(n)) time, where n is size of column
    int find(int data);

    // Retrieves value at index pos in circular buffer, based on sort order.
    // If pos == -1, retrieves last value in list, a la Python
    // Throws exception if pos >= size.
    // REQUIREMENT: must execute in O(1) time.
    int findAt(int pos);

    // Removes item from column, returning original position of item,
    // -1 if not found.
    // REQUIREMENT: must execute in O(n) time, where n is size of column
    int remove(int data);

    // Removes top/left item from circular buffer and returns it.
    // Throws exception if empty.
    // REQUIREMENT: must execute in O(1) time
    int removeFirst(void);

    // Removes bottom/right item from circular buffer and returns it.
    // Throws exception if empty.
    // REQUIREMENT: must execute in O(1) time
    int removeLast(void);

    // return maximum number of items this buffer can hold
    int capacity();

    // return number of items currently held in the buffer
    int size();

    // debugging function. Prints out contents.
    void dump();

    // grading function used to examine private data members.
    // Do not implement!
    bool inspect(int* &buf, int &cap, int &size, int &start, int &end);
    
private:
    int *m_data; // pointer to dynamically allocated array for buffer 
    int m_capacity; // length of the allocated space pointed by m_data
    int m_size; // number of active items in buffer
    // index of the first active item in the buffer (virtual index 0)
    int m_start;
    int m_end; // index AFTER last active item in buffer

    // STUDENT-ADDED MEMBERS HERE

    // this check whether any elements exists or not 

    bool isEmpty();

    // this check whether any space exists or not 

    bool isFull() {
        return ( (m_start == 0 && m_end == m_capacity-1) || ( m_end +1 == m_start) );
    }

    // this check whether QUEUE is wrapped or not 

    bool isDataWarpped() {
        return ( m_end < m_start);
    }
    
    bool isElementInUnWrappedPart(int queueIndex) {
        return ( m_start + queueIndex <= m_capacity-1  );
    }
     
    // this method returns Array index based on elements's relative position in Q

    int getElementArrayIndexFromPos(int queueIndex) {
        
        if ( isElementInUnWrappedPart(queueIndex))
            return (queueIndex + m_start);

        else

            return ( (queueIndex - ( ( m_capacity -1 ) - m_start) ) -1  );
    }
    
    
       

    // END STUDENT-ADDED MEMBERS

};

#endif /* SSLCOLUMN_H */

