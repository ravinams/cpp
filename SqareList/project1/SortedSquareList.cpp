#include "SortedSquareList.h"
#include "SSLColumn.h"
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <cstring>

using namespace std ;
SortedSquareList::SortedSquareList()
{
    m_cols = new SSLColumn*[2];
    m_cols[0] = new SSLColumn();
    m_cols[1] = new SSLColumn();
    
    m_colInfo = new int[2];
    m_capacity = 2;
    m_size = 0;
    m_totalSize = 0;
    m_start = 0;
    m_end = 0;
}

SortedSquareList::SortedSquareList(const SortedSquareList & other)
{
    m_size = other.m_size;
    m_start = other.m_start;
    m_end = other.m_end;
    m_colInfo = new int[m_size];
    m_cols = new SSLColumn*[m_capacity];
    m_capacity = other.m_capacity;
    m_totalSize = other.m_totalSize;
    
    for (int i = 0; i < m_capacity; i++) {
        m_cols[i] = other.m_cols[i];
    }
}

SortedSquareList::~SortedSquareList()
{
    for (int i = 0; i < m_capacity; i++) {
        delete m_cols[i];
    }
    delete[] m_cols;
    
    delete[] m_colInfo;
    
}

const SortedSquareList& SortedSquareList::operator=(const SortedSquareList& rhs) {

    if (this != &rhs) {

        m_capacity = rhs.m_capacity;
        m_size = rhs.m_size;
        m_start = rhs.m_start;
        m_end = rhs.m_end;

        m_cols = new SSLColumn*[m_capacity / 2];

        for (int i = 0; i < m_capacity / 2; ++i) {
            new (&m_cols[i]) SSLColumn(m_capacity / 2);

            memcpy(&m_cols[i], &rhs.m_cols[i], m_capacity / 2);

        }
    }
    return *this;
}

void SortedSquareList::add(int data)
{
    
    int n = m_start;
    if (m_size == 0) {
        m_cols[n]->add(data);
        m_totalSize++;
        m_colInfo[n]++;
        m_size++;
        m_end++;
    }
    else
    {
        for (int i = m_start; i < m_size + m_start; i++) {
            if (m_totalSize == (m_capacity*m_capacity))
                grow();
            
            
            n = i;
            //Wrap
            if (n > m_capacity - 1)
                n = 0;
            
            if (m_cols[n]->size() == 0) {
                m_cols[n]->add(data);
                m_totalSize++;
                m_colInfo[n]++;
                m_end++;
                break;
            }
            int next = n + 1;
            if (next > m_capacity - 1)
                next = 0;
            int previous = n - 1;
            if (previous < 0)
                previous = m_capacity - 1;
            try {
                
                //Check if value smaller than tail
                if (data <= m_cols[n]->findAt(-1))
                {
                    //Check if value larger than head
                     if (m_cols[n]->size() >= (int)(ceil(sqrt(m_totalSize))) && m_cols[n]->findAt(0)&& n > m_start) {
                        m_cols[previous]->add(data);
                        m_colInfo[previous]++;
                        m_totalSize++;
                        break;
                    }
                    else {
                        m_cols[n]->add(data);
                        m_colInfo[n]++;
                        m_totalSize++;
                        break;
                    }
                }
                else if (i == m_size + m_start - 1)
                {
                    m_cols[n]->add(data);
                    m_colInfo[n]++;
                    m_totalSize++;
                    break;
                }
                
            }
            catch (std::overflow_error e) {
                shift(n);
                i = m_start - 1;
            }
        }
        int current = m_start;
        if (m_totalSize / m_size >= (int)ceil((sqrt(m_totalSize)))) {
            shift(n);
        }
        for (int i = 0; i < m_size; i++) {
            if (current > m_capacity - 1) {
                current = 0;
            }
            if (m_cols[current]->size() > (int)ceil((sqrt(m_totalSize)))) {
                shift(current);
            }
            current++;
        }
    }
}

int SortedSquareList::find(int data)
{
    int first = 0,                 //first array element
    last =  m_size,            //last array element
    middle;                        //mid point of search
    
    while (first <= last)
    {
        
        
        middle = (first + last) / 2; //this finds the mid point
        
        int middleT = middle + m_start;
        if (middleT > m_capacity - 1)
            middleT -= m_capacity;
        
        int pos = m_cols[middleT]->find(data);
        if (pos != -1) {
            return middle*2+pos;
        }
        else if (m_cols[middleT]->findAt(-1) > data) // if it's in the lower ha\
            lf
        {
            last = middle - 1;
        }
        else {
            first = middle + 1;                 //if it's in the upper half
        }
    }
    return -1;  // not found
}




int SortedSquareList::findAt(int pos)
{
    if (m_size > 0) {
        if (pos == -1) {
            if (m_end - 1 >= 0)
                return m_cols[m_end - 1]->findAt(pos);
            
        }
        
        if(pos < -1)
        {
            throw std::underflow_error("bad position");
        }
        
        if(pos > m_end)
        {
            for (int i = 0; i < m_capacity; i++) {
             delete m_cols[i];
               }
            delete[] m_cols;            

            throw std::overflow_error("bad position");
        }
        
        int n = (pos + m_start) / m_capacity;
        if (n > m_capacity - 1) {
            n -= m_capacity;
        }
        return m_cols[n]->findAt(pos);
    }
    else
        throw std::underflow_error("Buffer is empty");
}

bool SortedSquareList::remove(int data)
{
    try {
        int n = m_start;
        for (int i = m_start; i < m_size + m_start; i++) {
            if (n > m_capacity - 1)
                n = 0;
            n=i;
            if (m_cols[n]->find(data) != -1) {
                m_cols[n]->remove(data);
                return true;
            }
        }
        return false;
    }
    catch (std::underflow_error e) {
        return false;
    }
}

int SortedSquareList::capacity()
{
    return m_capacity;
}


int SortedSquareList::size()
{
    return m_size;
}

void SortedSquareList::dump()
{
    std::cout << "-----" << std::endl;
    int current = m_start;
    for (int i = 0; i < m_size; i++) {
        if(m_cols[current] != NULL)
            (*m_cols[current]).dump();
        current++;
        if (current > m_capacity - 1)
            current = 0;
        
    }
    
    
    std::cout << "-----" << std::endl;
}

void SortedSquareList::shift(int n)
{
    //Capacity reached
    if (m_totalSize == m_capacity * m_capacity) {
        
    }
    
    else if (n == m_start) {
        shiftRight(n);
    }
    else if (n == m_end) {
        shiftLeft(n);
    }
    else {
        int i = m_start;
        int counter = 0;
        double leftMean = 0;
        double rightMean = 0;
        
        while (i != n) {
            if (i > m_capacity - 1)
                i = 0;
            
            leftMean += m_cols[i]->size();
            i++;
            counter++;
            
        }
        leftMean = leftMean / counter;
        counter = 0;
        i = n + 1;
        if (i > m_capacity - 1)
            i = 0;
        while (i != m_end) {
            if (i > m_capacity - 1)
                i = 0;
            
            rightMean += m_cols[i]->size();
            i++;
            counter++;
        }
        rightMean = rightMean / counter;
        if (rightMean == (int)(ceil(sqrt(m_totalSize))))
            shiftLeft(n);
        else if (leftMean == (int)(ceil(sqrt(m_totalSize))))
            shiftLeft(n);
        else if (rightMean < leftMean) {
            shiftRight(n);
        }
        else
            shiftLeft(n);
        
    }
}

void SortedSquareList::shiftLeft(int n)
{
    int current = n;
    for (int i = current; i > m_start - m_size+2; i--) {
        if (current < 0)
            current = m_capacity - 1;
        
        if (m_cols[current]->size() < (int)ceil((sqrt(m_totalSize+1))))
            break;
        else if (i == m_start - m_size + 1) {
            m_size++;
            m_start--;
            if (m_start <0)
                m_start = m_capacity-1;
        }
        
        current--;
    }
    int next;
    while (current != n) {
        next = current + 1;
        if (next > m_capacity - 1)
            next = 0;
        
        m_cols[current]->add(m_cols[next]->removeFirst());
        current++;
        if (current < 0)
            current = m_capacity - 1;
        
    }
}

void SortedSquareList::shiftRight(int n)
{
    
    int current = n;
    for (int i = current; i < m_start + m_size;i++) {
        if (current > m_capacity - 1)
            current = 0;
        
        if (m_cols[current]->size() < (int)ceil((sqrt(m_totalSize+1))))
            break;
        else if (i == m_start + m_size - 1) {
            m_size++;
            m_end++;
            if (m_end > m_capacity - 1)
                m_end = 0;
        }
        
        current++;
    }
    int previous;
    while (current != n) {
        previous = current - 1;
        if (previous < 0)
            previous = m_capacity - 1;
        
        m_cols[current]->add(m_cols[previous]->removeLast());
        current--;
        if (current < 0)
            current = m_capacity - 1;
        
    }
}

void SortedSquareList::grow()
{
   

    SSLColumn** m_colsNew = new SSLColumn*[m_capacity * 2];
    for (int i = 0; i < m_capacity * 2; i++) {
        m_colsNew[i] = new SSLColumn(m_capacity * 2);
    }
   
    m_start = 0;
   int newEnd = 0;

 for (int i = 0; i < m_capacity; i++) {

 for (int j = 0; j < m_cols[i]->size(); j++) {
                             
                m_colsNew[newEnd]->addLast(m_cols[i]->findAt(j));

  if (m_colsNew[newEnd]->size() == m_colsNew[newEnd]->capacity()) {
                    // cout << newEnd<< " column is Full" << endl ;
                    newEnd = newEnd + 1;
                    
                }

                
            }
            delete m_cols[i];

    }
    
    delete []m_cols ;

    m_cols = m_colsNew;
    m_size = newEnd + 1;
    m_capacity = m_capacity * 2;
    m_start = 0;
    m_end = newEnd ;
    //std::cout << "GREW";
    
}




