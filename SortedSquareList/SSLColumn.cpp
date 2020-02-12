
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 * 
 * int *m_data;    // pointer to dynamically allocated array for buffer 
   int m_capacity;  // length of the allocated space pointed by m_data
   int m_size;      // number of active items in buffer
   // index of the first active item in the buffer (virtual index 0)
   int m_start;
   int m_end;       // index AFTER last active item in buffer

 * 
 */

#include "SSLColumn.h" 
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <cstring>


using namespace std;

SSLColumn::SSLColumn(int n) {

    m_capacity = n;
    m_size = 0;
    m_start = -1;
    m_end = -1;
    m_data = new int [m_capacity];
}

SSLColumn::SSLColumn(const SSLColumn& other) {

    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_start = other.m_start;
    m_end = other.m_end;

    m_data = new int [m_capacity];

    memcpy(m_data, other.m_data, m_capacity);
}

SSLColumn::~SSLColumn() {
   delete []m_data ;
}

const SSLColumn& SSLColumn::operator=(const SSLColumn& rhs) {

    if (this != &rhs) {

         int newCapacity  = m_capacity;
        
         if(m_capacity < rhs.m_capacity)
           {
             newCapacity = rhs.m_capacity ;
            
           }

      
        m_start = 0 ;
        m_end = 0 ;

   
        delete []m_data;
        m_data = new int [newCapacity];

        for (int i = 0 ; i < rhs.m_size ; i++)
          {
             addLast(rhs.m_data[i]) ;   
          }

       m_capacity = newCapacity ;
       m_size = rhs.m_size ;
       m_end = m_size-1 ;
              
    }

    return *this;
}

bool SSLColumn::isEmpty() {
        return ( m_start == -1);
    }

void SSLColumn::add(int data) {

    if (isFull()) {
        throw overflow_error("Error : Overflow Exception");
    } else {

        // If queue is  empty

        int arrayIndex = -1;


        // Queue is initially empty
        if (isEmpty()) {

            m_start = 0;
            m_end = 0;

            m_data[m_end] = data;

        } else {

            // find the probable position for new Element
            // assumption is Array is SORTED in ASCENDING order 

            for (int i = 0; i < m_capacity; i++) {
                if (m_data[i] > data) {
                    arrayIndex = i;
                    break;
                }
            }

            // element to be inserted at the end of Q
            if (arrayIndex == -1) {


                m_end++;
                m_size++;

                m_data[m_end] = data;
                return;

            }

            if (!isDataWarpped()) // DATA IS NOT WARPPED 
            {
                if (m_end == m_capacity - 1) // to preserve the last element 
                {
                    m_data[0] = m_data[m_capacity - 1];

                }

                // shift all elements to right to make space 
                for (int j = m_end; j >= arrayIndex; j--) {
                    m_data[j + 1] = m_data[j];
                }

                m_data[arrayIndex] = data;

                if (m_end == m_capacity - 1)
                    m_end = 0;
                else
                    m_end = m_end + 1;

            } else // ATA IS WARPPED && probable position can be in any half 
            {
                if (arrayIndex <= m_end) // that means , new element supposed to be inserted into WARPPED part.
                {
                    for (int j = m_end; j >= arrayIndex; j--) {
                        m_data[j + 1] = m_data[j];
                    }

                    m_data[arrayIndex] = data;

                } else { // else , new element supposed to be inserted into UNWARRPED part i.e at end . 

                    for (int j = m_end; j >= 0; j--) {
                        m_data[j + 1] = m_data[j];
                    }

                    m_data[0] = m_data[m_capacity - 1];

                    // shift all elements to right to make space 
                    for (int j = m_capacity - 1; j >= arrayIndex; j--) {
                        m_data[j + 1] = m_data[j];
                    }

                    m_data[arrayIndex] = data;

                }

                m_end = m_end + 1;
            }

        }

        m_size++;
    }

}

void SSLColumn::addFirst(int data) {

    if (isFull()) {
        throw overflow_error("Error : Overflow Exception");
    } else {

        // If queue is initially empty
        if (isEmpty()) {
            m_start = 0;
            m_end = 0;
        } else if (m_start == 0)
            m_start = m_capacity - 1;
        else
            m_start--;

        m_data[m_start] = data;
        m_size++;

    }
}

void SSLColumn::addLast(int data) {

    if (isFull()) {
        throw overflow_error("Error : Overflow Exception");
    } else {

        // If queue is initially empty
        if (isEmpty()) {

            m_start = 0;
            m_end = 0;

        }// rear is at last position of queue
        else if (m_end == m_capacity - 1) {

            m_end = 0;
        }// increment rear end by '1'
        else {

            m_end = m_end + 1;

        }

        // insert current element into Deque

        m_data[m_end] = data;
        m_size++;
    }

}

int binarySearch(int arr[], int low, int high, int number) {

    while (high >= low) {
        int middle = (low + high) / 2;
        if (arr[middle] == number) {
            return middle;
        } else if (arr[middle] < number) {
            low = middle + 1;
        } else if (arr[middle] > number) {
            high = middle - 1;
        }
    }
    return -1;
}

int SSLColumn::find(int data) {

    if (isEmpty())
        throw overflow_error("Error : Circular Queue is Empty");

    int arrayIndex = 0;
    int queueIndex = -1;

    // first search Array from 'm_start' to till end .

    if (!isDataWarpped()) {

        arrayIndex = binarySearch(m_data, m_start, m_end, data);

        if (arrayIndex != -1)
            queueIndex = arrayIndex - m_start;
    } else {
        //1. serach in unwarrped part 

        arrayIndex = binarySearch(m_data, m_start, m_end, data);


        if (arrayIndex != -1) {
            queueIndex = arrayIndex - m_start;
        } else {
            //2 then search in wrapped part
            arrayIndex = binarySearch(m_data, 0, m_end, data);

            if (arrayIndex != -1)
                queueIndex = (((m_capacity - 1) - m_start) + arrayIndex + 1);
        }
    }

    return queueIndex;
}

// 

int SSLColumn::findAt(int pos) {

    if (pos <= -1 || pos >= m_capacity)
        throw range_error("Error : Given position is Out of bounds ");

    if (isEmpty())
        throw overflow_error("Error : Circular Queue is Empty");

    if (isElementInUnWrappedPart(pos)) // Element in UNWRAPPED part
        return m_data[m_start + pos ];
    else //  Element in WRAPPED part
        return m_data[ pos - (m_capacity - m_start) ];

}

int SSLColumn::remove(int data) {

    int k;
    if (isEmpty())
        throw overflow_error("Error : Circular Queue is Empty");

    int pos = SSLColumn::find(data);

    if (pos < -1)
        throw overflow_error("Error : Element does not exists ");



    if (pos != -1) {

        int arrayIndex = getElementArrayIndexFromPos(pos);

        if (m_start == arrayIndex) {
            removeFirst();
        } else {

            if (isElementInUnWrappedPart(pos)) {


                for (int i = arrayIndex; i > m_start; i--)
                    m_data[i] = m_data[i - 1];

                m_data[m_start++] = 0;

            } else {

                if (m_end == 0) {
                    m_data[m_end] = 0;

                    m_end = m_capacity - 1;
                } else {

                    cout << endl << " inner :" << m_end << " " << arrayIndex;
                    for (int i = m_end; i > arrayIndex; i--)
                        m_data[i - 1] = m_data[i];

                    m_data[m_end--] = 0;
                }
            }

            m_size--;

        }
    }



    return pos;
}

int SSLColumn::removeFirst(void) {

    if (isEmpty())
        throw overflow_error("Error : Circular Queue is Empty");

    // Deque has only one element

    int element = m_data[m_start];
    m_data[m_start] = 0;

    if (m_size == 1) {
        m_start = -1;
        m_end = -1;
    } else {


        if (m_start == m_capacity - 1)
            m_start = 0;
        else
            m_start++;
    }

    m_size--;

    return element;
}



  int SSLColumn::removeLast(void) {

    if (isEmpty())
        throw overflow_error("Error : Circular Queue is Empty");

    int element = m_data[m_end];
    m_data[m_end] = 0;

    if (m_size == 1) {
        m_start = -1;
        m_end = -1;
    } else {

        if (m_end == 0)
            m_end = m_capacity - 1;
        else
            m_end--;
    }

    m_size--;

    return element;
}


int SSLColumn::capacity() {

    return m_capacity;
}

int SSLColumn::size() {

    return m_size;
}

void SSLColumn::dump() {


    cout << " | " << "m_capacity : " << m_capacity << " | " << "m_size: " << m_size << " | " << "m_start: " << m_start << " | " << "m_end: " << m_end << " | " << endl;

    if (isEmpty()) {
        cout << " Queue is Empty\n" << endl;
        return;
    }
    cout << " Elements in Circular Queue are: \n";

    // For easy readability , printing '|' to surround elements
    cout << " | ";
    for (int i = 0; i < m_capacity; i++)
        cout << m_data[i] << " | ";

    cout << "\n---------------------------\n" << endl;
}

/*
 * 
 
int main(int argc, char** argv) {

    SSLColumn s(4);

  

    s.add(10);
    s.add(15);
    s.add(20);
   // s.dump();
    s.add(13);
    
    s.remove(20);
    s.remove(15);
    
    // s.dump();
    
     s.addLast(30);
     s.addLast(40);
     s.dump();
     
     s.remove(30);
     s.dump();
   
     s.add(25);
     s.dump();

   
     
    return 0;
}
*/
