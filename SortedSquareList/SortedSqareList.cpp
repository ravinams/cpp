
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortedSquareList.cpp
 * Author: oracle
 *
 * Created on February 14, 2018, 10:40 AM
 */

#include "SortedSquareList.h" 
#include "SSLColumn.h" 
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <math.h> 

using namespace std;

// default constructor

SortedSquareList::SortedSquareList() {

    int sqareDimension = 2;

    m_capacity = sqareDimension * 2;
    m_size = 0;
    m_start = -1;
    m_end = -1;

    m_cols = new SSLColumn*[sqareDimension];

    for (int i = 0; i < sqareDimension; ++i) {
        m_cols[i] = new SSLColumn(sqareDimension);
    }


}

// copy constructor

SortedSquareList::SortedSquareList(const SortedSquareList& other) {

    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_start = other.m_start;
    m_end = other.m_end;

    int currentSD = ceil(sqrt(m_capacity));


    m_cols = new SSLColumn*[currentSD];

    for (int i = 0; i < currentSD; ++i) {
        m_cols[i] = new SSLColumn(currentSD);
        memcpy(&m_cols[i], &other.m_cols[i], currentSD);
    }
}

const SortedSquareList& SortedSquareList::operator=(const SortedSquareList& rhs) {

    if (this != &rhs) {

       int newCapacity  = m_capacity;
       
        
         if(m_capacity < rhs.m_capacity)
           {
             newCapacity = rhs.m_capacity ;            
           }

        delete[] m_cols ;

        int newSD = ceil(sqrt(m_capacity)) ;

        m_cols = new SSLColumn*[newSD];
        
        for (int i = 0; i < newSD; ++i) {
           m_cols[i] = new SSLColumn(newSD);
        }

         int newEnd = 0;
        
          int start = rhs.m_start ;

            int sze = rhs.m_size ;
            while(start < sze)
               {
                    if (m_cols[newEnd]->size() == m_cols[newEnd]->capacity()) {
                    // cout << newEnd<< " column is Full" << endl ;
                    newEnd = newEnd + 1;
                }

                  for(int i = 0 ; i < rhs.m_cols[start]->size() ; i ++)
                 m_cols[newEnd]->addLast(rhs.m_cols[start]->findAt(i)) ;
                 
               }

        
        m_start = 0 ;
        m_end = newEnd ;
        m_size = newEnd + 1 ;
        m_capacity = newCapacity ;
        


        
    }
    return *this;
}

// destructor

SortedSquareList::~SortedSquareList() {

}

void SortedSquareList::extendSquareList() {

    if (isFull()) {

        // first figure existing square dimension

        int currentSD = ceil(sqrt(m_capacity));
        int proposedSD = currentSD * 2; //  double the dimensions each time

        SSLColumn ** new_cols = new SSLColumn*[proposedSD];

        // allocate space for NEW COLUMNS of NEW CAPACITY .

        for (int i = 0; i < proposedSD; ++i) {
            new_cols[i] = new SSLColumn(proposedSD);
        }

        // cout << "Extending again -- " << currentSD << " --> "<<proposedSD <<" --> "<< proposedSD * proposedSD<<endl ;

        // copy existing COLUMNS into new COLUMNS 

        m_start = 0;
        m_capacity = proposedSD * proposedSD;
        int newEnd = 0;
        for (int i = 0; i < currentSD; i++) {

            for (int j = 0; j < currentSD; j++) {

                if (new_cols[newEnd]->size() == new_cols[newEnd]->capacity()) {
                    // cout << newEnd<< " column is Full" << endl ;
                    newEnd = newEnd + 1;
                }

                new_cols[newEnd]->addLast(m_cols[i]->findAt(j));
            }
            delete m_cols[i];
        }

        delete[] m_cols;

        m_end = newEnd;
        m_size = newEnd + 1;
        m_cols = new_cols;
    }
}

/*
     SSLColumn*[proposedSD];
 */

void SortedSquareList::add(int data) {

    if (isFull()) {
        extendSquareList();
    }

    int currentSD = ceil(sqrt(m_capacity));

    // if it is empty , then add it first element 
    if (isEmpty()) {

        m_start = 0;
        m_end = 0;
        m_size = 1;
        m_cols[m_start]->addFirst(data);

    } else if (m_cols[m_end] -> findAt(m_cols[m_end]->size() - 1) < data) // appropriate position is last position
    {


        //end column is not full
        if (m_cols[m_end]->size() != m_cols[m_end]->capacity()) {


            m_cols[m_end]->addLast(data);
        } else //end column is full, then need to add it to next available COLUMN 
        {

            if (m_end == (currentSD - 1)) { // is LAST column ?? 
                m_end = 0;
            } else {
                m_end = m_end + 1;
            }

            m_cols[m_end]->addLast(data);
            m_size++;
        }
    } else { // then appropriate position is some where middle in Q 

        // find the probable position for new Element
        // assumption is Array is SORTED in ASCENDING order 
 
     
        
        int currentSD = ceil(sqrt(m_capacity));
        int colPos = -1;

        for (int i = m_start; i <= m_size; i++) {
            for (int j = 0; j < m_cols[i]->size(); j++) {

                if (m_cols[i]->findAt(j) > data) {

                    colPos = i;
                    break;
                }
            }

            if (colPos != -1) { // appropriate position found , 


                break;

            }

        }

        if (colPos == -1 && (m_end < m_start)) {

            for (int i = 0; i <= m_end; i++) {
                for (int j = 0; j < m_cols[i]->size(); j++) {

                    if (m_cols[i]->findAt(j) > data) {

                        colPos = i;
                        break;
                    }
                }

                if (colPos != -1) { // appropriate position found , 

                    break;
                }

            }
        }

        // cout << " appropriate position found ( colPos) " << colPos << endl;

        if (m_start < m_end && colPos <= m_end) {

            if (m_cols[m_end]->size() == m_cols[m_end]->capacity()) {
                m_end = m_end + 1;
            }

            for (int i = m_end; i > colPos; i--) {
                m_cols[i]->add(m_cols[i - 1]->removeLast());
            }

            m_cols[colPos]->add(data);

        } else {
            //  m_cols[colPos]->add(data);
        }
    }
}

int SortedSquareList::find(int data) {

    if (isEmpty())
        throw overflow_error("Error : Circular Queue is Empty");

    int pos = -1;
    int currentSD = ceil(sqrt(m_capacity));

    // find relative elememnt position in array 

    int clmnSize = 0;
    int elementPos = -1;

    if (m_start <= m_end) {

        for (int i = m_start; i <= m_end; i++) {
            if (m_cols[i] -> findAt(m_cols[i] ->size() - 1) >= data) // then element must exists in this column
            {
                elementPos = elementPos + m_cols[i]->find(data) + 1;
                break;

            }
            elementPos = elementPos + m_cols[i]->size();
        }
    } else {
        // first check unwarpped part 

        for (int i = m_start; i <= m_size; i++) {
            if (m_cols[i] -> findAt(m_cols[i] ->size() - 1) >= data) // then element must exists in this column
            {
                elementPos = elementPos + m_cols[i]->find(data) + 1;
                break;

            }
            elementPos = elementPos + m_cols[i]->size();
        }

        if (elementPos == -1) { // if element not found , then check wrapped part 

            for (int i = 0; i <= m_end; i++) {


                if (m_cols[i] -> findAt(m_cols[i] ->size() - 1) >= data) // then element must exists in this column
                {
                    elementPos = elementPos + m_cols[i]->find(data) + 1;
                    break;

                }
                elementPos = elementPos + m_cols[i]->size();
            }
        }

    }
     return elementPos;
}

    int SortedSquareList::findAt(int pos) {

        if (isEmpty())
            throw overflow_error("Error : Circular Queue is Empty");

        if (pos <= -2 || pos >= m_capacity)
            throw range_error("Error : Given position is Out of bounds ");

        if (pos == -1) {
            int lastActiveColumn = m_capacity / m_size;
            int lastActiveIndex = m_capacity % m_size;

            return m_cols[lastActiveColumn]->findAt(lastActiveIndex);
        }

        // find total elements/positions from m_start COLUMN to till end (m_capacity-1) COLUMN

        int currentSD = ceil(sqrt(m_capacity));

        int unwrappedPositionsCount = (m_capacity - m_start) * currentSD;
        int elementColumn = -1;
        int elementIndex = -1;


        if (pos <= unwrappedPositionsCount) {
            elementColumn = m_capacity / pos;
            elementIndex = m_capacity % pos;

            return m_cols[elementColumn]->findAt(elementIndex);

        } else {
            int wrappedPos = pos / unwrappedPositionsCount;

            elementColumn = m_capacity / currentSD;
            elementIndex = m_capacity % currentSD;

            return m_cols[elementColumn]->findAt(elementIndex);

        }


    }

    bool SortedSquareList::remove(int data) {

       

        if (isEmpty())
            throw overflow_error("Error : Circular Queue is Empty");

        int pos = find(data);

      

        if (pos < -1)
            return false;

      
        
        if (size() == 1) // there is only element in the entire Q  ;
        {
            m_cols[m_start]->removeFirst();
            m_start = -1;
            m_end = -1;
            m_size = 0;

        } else if (m_cols[m_end]->findAt(m_cols[m_end]->size()-1) == data) // check for the last element 
        {

            m_cols[m_end]->removeLast();

            if (m_cols[m_end]->size() == 0) {
                m_end--;
                m_size--;
            }
        } else // check for middle 
        {

            int currentSD = ceil(sqrt(m_capacity));
            int dataColumnIdx = pos / currentSD;
           
            
           
             
             
            m_cols[dataColumnIdx]->remove(data);
            
          
           

            for (int i = dataColumnIdx; i > m_start; i--) {
                
                // last element in last column
                int lastElement = m_cols[dataColumnIdx - 1]->removeLast() ;
                m_cols[dataColumnIdx]->addFirst(lastElement);
         
            }
            
          
                  
            if (m_cols[dataColumnIdx-1]->size() == 0) {
                m_start++;
                m_size--;
            }

        }

        return true;
    }

    int SortedSquareList::capacity() {
        return m_capacity;
    }

    int SortedSquareList::size() {
        int size = 0;
        if (!isEmpty()) {
            if (m_start <= m_end) {
                for (int i = m_start; i <= m_end; i++)
                    size = size + m_cols[i]->size();
            } else {
                for (int i = m_start; i < ceil(sqrt(m_capacity)); i++)
                    size = size + m_cols[i]->size();

                for (int i = 0; i <= m_end; i++)
                    size = size + m_cols[i]->size();
            }
        }

        return size;
    }

    bool SortedSquareList::isDataWarpped() {
        return ( m_end < m_start);
    }

    bool SortedSquareList::isFull() {

        return ( size() == capacity());
    }

    bool SortedSquareList::isEmpty() {
        return ( m_start == -1);
    }

    void SortedSquareList::dump() {


        cout << " OUTER Q --> " << endl << " | " << "m_capacity : " << m_capacity << " | " << "m_size: " << m_size << " | " << "m_start: " << m_start << " | " << "m_end: " << m_end << " | " << endl;
        cout << " ---------------------------------------------------------------------\n" << endl;


        for (int i = 0; i < ceil(sqrt(m_capacity)); i++) {
            cout << "INNER Q --> " << i << endl;
            m_cols[i]->dump();
        }
   }



